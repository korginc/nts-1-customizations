/* 
   Sequencer Template for NTS-1 Custom Panel reference board rev.B
     
   BSD 3-Clause License
    Copyright (c) 2020, KORG INC.
    All rights reserved.
    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
   * Redistributions of source code must retain the above copyright notice, this
      list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.
    * Neither the name of the copyright holder nor the names of its
      contributors may be used to endorse or promote products derived from
      this software without specific prior written permission.
    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
    OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//*/
 
// --- NTS-1 main boardinterface ------------------------------------------------------------------
#include <nts1.h>

NTS1 nts1;

// --- UI definitions and state -------------------------------------------------------------------
enum { sw_1 = 0, sw_2, sw_3, sw_4, sw_5, sw_6, sw_7, sw_8, sw_9, sw_10, sw_count };
const uint8_t g_sw_pins[sw_count] = { D34, D35, D36, D37, D38, D40, D41, D42, D46, D47};

enum {
  sw_step1 = sw_1,
  sw_step2 = sw_2,
  sw_step3 = sw_3,
  sw_step4 = sw_4,
  sw_step5 = sw_5,
  sw_step6 = sw_6,
  sw_step7 = sw_7,
  sw_step8 = sw_8,
  sw_play = sw_9,
  sw_shift = sw_10,
};

enum { led_1 = 0, led_2, led_3, led_4, led_5, led_6, led_7, led_8, led_count };
const uint8_t g_led_pins[led_count] = { D16, D17, D18, D19, D22, D23, D24, D25 };

enum { vr_1 = 0, vr_count };
const uint8_t g_vr_pins[vr_count] = { A10 };

typedef struct {
  HardwareTimer *timer; // for switch/vr scan
  uint32_t steps_pressed;
  bool is_shift_pressed;
} ui_state_t;

ui_state_t g_ui_state = {
  .timer = NULL,
  .steps_pressed = 0x0,
  .is_shift_pressed = false
};

// --- Sequencer definitions and state -----------------------------------------------------------

#define k_seq_length 8
#define k_seq_ticks_per_step 100

enum {
  k_seq_flag_reset = 1U<<0
};

typedef struct {
  HardwareTimer *timer; // for seq ticks
  uint32_t last_tick_us;
  uint8_t ticks;
  uint8_t step;
  uint8_t note;
  uint8_t flags;
  uint32_t gates;
  uint32_t tempo;
  uint8_t notes[k_seq_length];
  bool is_playing;
} seq_state_t;

seq_state_t g_seq_state = {
  .timer = NULL,
  .last_tick_us = 0,
  .ticks = 0xFF, // invalid
  .step = 0xFF, // invalid
  .note = 0xFF, // invalid
  .flags = 0x00, // none
  .gates = 0xFF, // 1 bit per step, all on
  .tempo = 1200, // 120.0 x 10
  .notes = {
    0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42
  },
  .is_playing = false
};

// --- UI scan/control ------------------------------------------------------------------------

void set_step_leds(uint8_t mask) {
  for (uint8_t i=led_1; i<=led_8; ++i) {
    nts1_digital_write(g_led_pins[i], (mask & (1U<<i)) ? HIGH : LOW);
  }
}

void scan_switches(unsigned long now_us) {
  static uint32_t last_sw_sample_us = 0;
  static uint32_t last_sw_state = 0;
  static uint8_t sw_chatter_cnt[sw_count] = {0};
  uint32_t sw_events = 0;
  
  if (now_us - last_sw_sample_us > 1000) {
    uint32_t sw_state = 0;
    for (uint8_t i=0; i<sw_count; ++i) 
    {
      const uint32_t val = nts1_digital_read(g_sw_pins[i]);
      const uint32_t last_val = ((last_sw_state>>i)&0x1);
      if (val != last_val) {
        if (++sw_chatter_cnt[i] > 6) {
          sw_state |= val<<i;
          sw_chatter_cnt[i] = 0;
        }
        else {
          sw_state |= last_val<<i;
        }
      }
      else {
        sw_chatter_cnt[i] = 0;
        sw_state |= last_val<<i;
      }
    }
    
    if (last_sw_state != sw_state) {
      // Change detected
       
      sw_events = sw_state ^ last_sw_state;
      
      // Check for play switch event
      static const uint32_t k_play_sw_mask = (1U<<sw_play);
      if (sw_events & k_play_sw_mask) {
         if ((~sw_state) & k_play_sw_mask) {
            // Pressed down
            // - reset sequencer
            g_seq_state.flags |= k_seq_flag_reset;
            // - toggle play state
            g_seq_state.is_playing = !g_seq_state.is_playing;
         }
      }

      // Check for shift switch event
      static const uint32_t k_shift_sw_mask = (1U<<sw_shift);
      if (sw_events & k_shift_sw_mask) {
        g_ui_state.is_shift_pressed = (sw_state & k_shift_sw_mask) == 0; // active low
      }

      // Check for step switch events
      static const uint32_t k_step_sw_mask = ((1U<<sw_9)-1);
      const uint32_t step_sw_events = sw_events & k_step_sw_mask;
      if (step_sw_events) {
        // New step presses
        const uint32_t new_presses = (~sw_state) & step_sw_events;
        // Released steps
        const uint32_t released = sw_state & step_sw_events;

        if (g_ui_state.is_shift_pressed) {
          // Set/unset sequencer gates
          g_seq_state.gates ^= new_presses>>sw_step1;
          set_step_leds(g_seq_state.gates);
        }
        
        g_ui_state.steps_pressed |= new_presses;
        g_ui_state.steps_pressed &= ~(released);
      }
    }

    last_sw_state = sw_state; // save state for ref. on next cycle
    last_sw_sample_us = now_us;
  }
}

void handle_vr_1(int16_t value) {
  // Keep references for catch mode behavior
  static int32_t last_tempo_vr_val = 0xFFFFFFFF;
  static int32_t last_shape_vr_val = 0xFFFFFFFF;
  
  if (g_ui_state.steps_pressed) { 
    // Set note if steps are pressed
    uint8_t note = value>>3; // 10bit to 7bit
    for (uint8_t i=sw_step1; i<=sw_step8; ++i) {
      if (g_ui_state.steps_pressed & (1U<<i)) {
         g_seq_state.notes[i] = note;
         if (note == 0) {
           // Force gate off
           g_seq_state.gates &= ~(1U<<i);
           nts1_digital_write(g_led_pins[i], LOW);
         }
         else {
           // Force gate on
           g_seq_state.gates |= 1U<<i;
           nts1_digital_write(g_led_pins[i], HIGH);
         }
      }
    }
  }
  else if (g_ui_state.is_shift_pressed){
    // Change tempo when shift is pressed
    if(last_tempo_vr_val == 0xFFFFFFFF
       || (abs(value - last_tempo_vr_val) < 10)) {
      g_seq_state.tempo = 200 + (value>>1)*10 + (value&0x1)*5; // 20.0 - 531.5 BPM in 0.5 increments
      last_tempo_vr_val = value;
    }
  }
  else {
    // Change SHAPE by default
    if(last_tempo_vr_val == 0xFFFFFFFF
       || (abs(value - last_shape_vr_val) < 10)) {
      // Set SHAPE parameter on NTS-1 main board
      nts1.paramChange(k_param_id_osc_shape, k_invalid_param_sub_id, value);
      last_shape_vr_val = value;
    }
  }
}

void scan_vrs(unsigned long now_us) {
  static uint32_t last_vr_sample_us = 0;
  static uint32_t last_vr_states[vr_count] = {0};
  static uint8_t vr_chatter_cnt[vr_count] = {0};
  
  if (now_us - last_vr_sample_us > 1000) {
    for (uint8_t i=0; i<vr_count; ++i) 
    {
      int32_t vr_state = 0;
      const int32_t val = analogRead(g_vr_pins[i]);
      const int32_t last_val = last_vr_states[i];
      if (val != last_val) {
        if (++vr_chatter_cnt[i] > 4) {
          vr_state = val;
          vr_chatter_cnt[i] = 0;
        }
        else {
          vr_state = last_val;
        }
      }
      else {
        vr_chatter_cnt[i] = 0;
        vr_state = last_val;
      }

      if (last_val == vr_state) {
        last_vr_sample_us = now_us;
        continue;
      }

      switch (i) {
        case vr_1:
          handle_vr_1(vr_state & 0x3FF);
          break;
        default:
          break;  
      }
      
      last_vr_states[i] = vr_state;
    }
    
    last_vr_sample_us = now_us;
  }
}

void scan_interrupt_handler(HardwareTimer *t) {
  unsigned long now_us = micros();
  scan_switches(now_us);
  scan_vrs(now_us);
}

// --- Sequencer Runtime ------------------------------------------------------------------------

void seq_interrupt_handler(HardwareTimer *t) {
  uint32_t now_us = micros();
  
  if (g_seq_state.flags & k_seq_flag_reset) {
    if (g_seq_state.note != 0xFF) {
      // There's a pending note on
      // Send note off event to NTS-1 main board
      nts1.noteOff(g_seq_state.note);
      const uint32_t cur_step = g_seq_state.step;
      const uint8_t highlow = (g_seq_state.gates & (1U<<cur_step)) ? HIGH : LOW; // revert LEDs
      nts1_digital_write(g_led_pins[cur_step], highlow);
    }
    // reset sequencer
    g_seq_state.ticks = 0xFF;
    g_seq_state.step = 0xFF;
    g_seq_state.note = 0xFF;
    g_seq_state.last_tick_us = now_us;
    g_seq_state.flags &= ~k_seq_flag_reset; // clear flags
  }

  if (!g_seq_state.is_playing) {
    return;
  }
  
  const uint32_t us_per_tick = 600000000UL/(4*g_seq_state.tempo*100);
  const uint32_t tick_delta_us = now_us - g_seq_state.last_tick_us;
  if (tick_delta_us < us_per_tick) {
    return; 
  }
  // Increment ticks
  ++g_seq_state.ticks;
  
  // Set adjusted reference time for next tick
  g_seq_state.last_tick_us = now_us - (tick_delta_us - us_per_tick);

  uint32_t cur_step = g_seq_state.step;

  if (g_seq_state.ticks >= k_seq_ticks_per_step) {
    cur_step = (cur_step + 1) % k_seq_length;
    g_seq_state.ticks = 0;
    
    const uint8_t note = g_seq_state.notes[cur_step];
    
    if (g_seq_state.gates & (1U<<cur_step)) {
      // Send note on event to NTS-1 main board
      nts1.noteOn(note, 0x7F);
      nts1_digital_write(g_led_pins[cur_step], LOW);
    }
    else {
      nts1_digital_write(g_led_pins[cur_step], HIGH);
    }
    
    g_seq_state.step = cur_step;
    g_seq_state.note = note;
  }
  else if (g_seq_state.ticks >= (k_seq_ticks_per_step>>1)) {
    if (g_seq_state.note != 0xFF) {
      // Send note off event to NTS-1 main board
      nts1.noteOff(g_seq_state.note);
      uint32_t cur_step = g_seq_state.step;
      const uint8_t highlow = (g_seq_state.gates & (1U<<cur_step)) ? HIGH : LOW; // revert LEDs
      nts1_digital_write(g_led_pins[cur_step], highlow);
      g_seq_state.note = 0xFF;
    }
  }
}

// --- Hardware Timer Setup ------------------------------------------------------------------------

HardwareTimer *setup_timer(uint8_t ref_pin, uint32_t prescaler, uint32_t overflw, void (*interrupt_handler)(HardwareTimer *)) {
  // Automatically retrieve TIM instance and channel associated to pin
  // This is used to be compatible with all STM32 series automatically.
  HardwareTimer *timer = new HardwareTimer((TIM_TypeDef *)pinmap_peripheral(digitalPinToPinName(ref_pin), PinMap_PWM));
  uint32_t channel = STM_PIN_CHANNEL(pinmap_function(digitalPinToPinName(ref_pin), PinMap_PWM));
  timer->setMode(channel, TIMER_OUTPUT_COMPARE);
  
  // With a PrescalerFactor = 1, the minimum frequency value to measure is : TIM counter clock / CCR MAX
  //  = (SystemCoreClock) / 65535
  // Example on Nucleo_L476RG with systemClock at 80MHz, the minimum frequency is around 1,2 khz
  // To reduce minimum frequency, it is possible to increase prescaler. But this is at a cost of precision.
  // The maximum frequency depends on processing of the interruption and thus depend on board used
  // Example on Nucleo_L476RG with systemClock at 80MHz the interruption processing is around 4,5 microseconds and thus Max frequency is around 220kHz
  const uint32_t PrescalerFactor = 4;
  timer->setPrescaleFactor(PrescalerFactor);
  timer->setOverflow(overflw); //0x10000); // Max Period value to have the largest possible time to detect rising edge and avoid timer rollover
  timer->attachInterrupt(channel, interrupt_handler);
  //uint32_t freq = timer->getTimerClkFreq() / timer->getPrescaleFactor();
  return timer;
}

// --- Arduino Sketch Entry ------------------------------------------------------------------------

void setup() {
  // - Setup debug serial if needed ------------------------------
  Serial.begin(115200);

  // - Initialize VR and LED GPIOS -------------------------------
  for (uint8_t i=0; i<sw_count; ++i) {
    pinMode(g_sw_pins[i], INPUT_PULLUP);
  }
  for (uint8_t i=0; i<led_count; ++i) {
    uint8_t led_pin=g_led_pins[i];
    pinMode(led_pin, OUTPUT);
  }
  
  // - Initialize NTS-1 main board interface ---------------------
  nts1.init();

  // - Initialize UI state ---------------------------------------
  set_step_leds(g_seq_state.gates);
  
  // - Setup Hardware Timer for switch/vr scanning ---------------
  g_ui_state.timer = setup_timer(D2, 24, 2000, scan_interrupt_handler);

  // - Setup Hardware Timer for sequencer ------------------------
  g_seq_state.timer = setup_timer(D4, 24, 1000, seq_interrupt_handler); // 2KHz interrupt? -> 500ns per cycle

  // - Start timers ----------------------------------------------
  g_ui_state.timer->resume();
  g_seq_state.timer->resume();
}

// --- Arduino Sketch Idle Loop ----------------------------------------------------------------------

void loop() {  
  unsigned long now_ms = millis();
  unsigned long now_us = micros();
  
  // - Run NTS-1 interface idle callback -------------------------
  nts1.idle();
}
