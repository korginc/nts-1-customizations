/** 
 * @file nts-1.h 
 * @brief NTS1 Class definition.
 *
 * Provides an object oriented interface for the C API
 *   
 * BSD 3-Clause License
 *  Copyright (c) 2020, KORG INC.
 *  All rights reserved.
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 * * Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *  * Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 *  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 *  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 *  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 //*/

#ifndef _NTS1_H_
#define _NTS1_H_

#include "nts1_iface.h"

class NTS1 {
 public:
  
  /**
   * Default constructor
   */
  NTS1(void);

  /**
   * Default destructor
   */
  ~NTS1(void);

  // ----------------------------------------------------------
  
  /**
   * Success status returned by various operations
   */
  enum {
        STATUS_OK      = 0x00U,
        STATUS_ERR     = 0x01U,
        STATUS_BUSY    = 0x02U,
        STATUS_TIMEOUT = 0x03U,
  };

  /**
   * Transmitable event IDs
   */
  enum {
        TX_EVENT_ID_NOTE_OFF        = 0x00U,
        TX_EVENT_ID_NOTE_ON         = 0x01U,
        TX_EVENT_ID_INC_PARAM       = 0x04U,
        TX_EVENT_ID_INC_OSC_PARAM   = 0x05U,
        TX_EVENT_ID_REQ_UNIT_COUNT  = 0x10U,
        TX_EVENT_ID_REQ_UNIT_DESC   = 0x11U,
        TX_EVENT_ID_REQ_PARAM_DESC  = 0x12U,
        TX_EVENT_ID_REQ_VALUE       = 0x13U,
  };

  /**
   * Receivable event IDs
   */  
  enum {
        RX_EVENT_ID_NOTE_OFF        = 0x0U,
        RX_EVENT_ID_NOTE_ON         = 0x1U,
        RX_EVENT_ID_STEP_TICK       = 0x2U,
        RX_EVENT_ID_UNIT_DESC       = 0x11U,
        RX_EVENT_ID_PARAM_DESC      = 0x12U,
        RX_EVENT_ID_VALUE           = 0x13U,
  };

  /**
   * Parameter IDs
   */  
  enum {
        // OSC
        PARAM_ID_OSC_BASE = 0U,
        PARAM_ID_OSC_TYPE = PARAM_ID_OSC_BASE,
        PARAM_ID_OSC_SHAPE,
        PARAM_ID_OSC_SHIFT_SHAPE,
        PARAM_ID_OSC_LFO_RATE,
        PARAM_ID_OSC_LFO_DEPTH,
        PARAM_ID_OSC_EDIT, // WITH SUBID
        PARAM_ID_OSC_LAST = PARAM_ID_OSC_EDIT,
        
        // AMPEG
        PARAM_ID_AMPEG_BASE,
        PARAM_ID_AMPEG_TYPE = PARAM_ID_AMPEG_BASE,
        PARAM_ID_AMPEG_ATTACK,
        PARAM_ID_AMPEG_RELEASE,
        PARAM_ID_AMPEG_LFO_RATE,
        PARAM_ID_AMPEG_LFO_DEPTH,
        PARAM_ID_AMPEG_RESERVED3,
        PARAM_ID_AMPEG_LAST = PARAM_ID_AMPEG_RESERVED3,
        
        // FILTER
        PARAM_ID_FILT_BASE,
        PARAM_ID_FILT_TYPE = PARAM_ID_FILT_BASE,
        PARAM_ID_FILT_CUTOFF,
        PARAM_ID_FILT_PEAK,
        PARAM_ID_FILT_LFO_RATE,
        PARAM_ID_FILT_LFO_DEPTH,
        PARAM_ID_FILT_RESERVED3,
        PARAM_ID_FILT_LAST = PARAM_ID_FILT_RESERVED3,
        
        // MODULATION EFFECT
        PARAM_ID_MOD_BASE,
        PARAM_ID_MOD_TYPE = PARAM_ID_MOD_BASE,
        PARAM_ID_MOD_TIME,
        PARAM_ID_MOD_DEPTH,
        PARAM_ID_MOD_RESERVED1,
        PARAM_ID_MOD_RESERVED2,
        PARAM_ID_MOD_RESERVED3,
        PARAM_ID_MOD_LAST = PARAM_ID_MOD_RESERVED3,
        
        // DELAY EFFECT
        PARAM_ID_DEL_BASE,
        PARAM_ID_DEL_TYPE = PARAM_ID_DEL_BASE,
        PARAM_ID_DEL_TIME,
        PARAM_ID_DEL_DEPTH,
        PARAM_ID_DEL_RESERVED1,
        PARAM_ID_DEL_MIX,
        PARAM_ID_DEL_RESERVED3,
        PARAM_ID_DEL_LAST = PARAM_ID_DEL_RESERVED3,
        
        // REVERB EFFECT
        PARAM_ID_REV_BASE,
        PARAM_ID_REV_TYPE = PARAM_ID_REV_BASE,
        PARAM_ID_REV_TIME,
        PARAM_ID_REV_DEPTH,
        PARAM_ID_REV_RESERVED1,
        PARAM_ID_REV_MIX,
        PARAM_ID_REV_RESERVED3,
        PARAM_ID_REV_LAST = PARAM_ID_REV_RESERVED3,
        
        // ARPEGGIATOR
        PARAM_ID_ARP_BASE,
        PARAM_ID_ARP_PATTERN = PARAM_ID_ARP_BASE,
        PARAM_ID_ARP_INTERVALS,
        PARAM_ID_ARP_LENGTH,
        PARAM_ID_ARP_STATE,
        PARAM_ID_ARP_TEMPO,
        PARAM_ID_ARP_LAST = PARAM_ID_ARP_TEMPO,
        
        NUM_PARAM_ID, // end regular param IDs
        
        // SPECIAL PARAM IDS
        PARAM_ID_SYS_BASE = NUM_PARAM_ID,
        PARAM_ID_SYS_VERSION = PARAM_ID_SYS_BASE, // read-only
        PARAM_ID_SYS_GLOBAL,
        PARAM_ID_SYS_LAST = PARAM_ID_SYS_GLOBAL,
        
        PARAM_ID_INVALID = 0x7FU,

        // For convenience
        NUM_OSC_PARAM_ID   = PARAM_ID_OSC_LAST - PARAM_ID_OSC_BASE,
        NUM_AMPEG_PARAM_ID = PARAM_ID_AMPEG_LAST - PARAM_ID_AMPEG_BASE,
        NUM_FILT_PARAM_ID  = PARAM_ID_FILT_LAST - PARAM_ID_FILT_BASE,
        NUM_MOD_PARAM_ID   = PARAM_ID_MOD_LAST - PARAM_ID_MOD_BASE,
        NUM_DEL_PARAM_ID   = PARAM_ID_DEL_LAST - PARAM_ID_DEL_BASE,
        NUM_REV_PARAM_ID   = PARAM_ID_REV_LAST - PARAM_ID_REV_BASE,
        NUM_ARP_PARAM_ID   = PARAM_ID_ARP_LAST - PARAM_ID_ARP_BASE,
        NUM_SYS_PARAM_ID   = PARAM_ID_SYS_LAST - PARAM_ID_SYS_BASE,
  };

  /**
   * Osc Edit Parameter Sub-IDs
   */  
  enum {
        // Osc edit parameters
        PARAM_SUBID_OSC_BASE  = 0U,
        PARAM_SUBID_OSC_EDIT1 = PARAM_SUBID_OSC_BASE,
        PARAM_SUBID_OSC_EDIT2,
        PARAM_SUBID_OSC_EDIT3,
        PARAM_SUBID_OSC_EDIT4,
        PARAM_SUBID_OSC_EDIT5,
        PARAM_SUBID_OSC_EDIT6,
        PARAM_SUBID_OSC_LAST = PARAM_SUBID_OSC_EDIT6,
        NUM_OSC_PARAM_SUBID,
  };

  /**
   * Global Parameter Sub-IDs
   */  
  enum {
        PARAM_SUBID_SYS_GLOBAL_BASE = 0,
        PARAM_SUBID_SYS_GLOBAL_INPUT_ROUTE = PARAM_SUBID_SYS_GLOBAL_BASE,
        PARAM_SUBID_SYS_GLOBAL_INPUT_TRIM,
        PARAM_SUBID_SYS_GLOBAL_SYNCOUT_POLARITY,
        PARAM_SUBID_SYS_GLOBAL_SYNCIN_POLARITY,
        PARAM_SUBID_SYS_GLOBAL_TEMPO_RANGE,
        PARAM_SUBID_SYS_GLOBAL_CLOCK_SOURCE,
        PARAM_SUBID_SYS_GLOBAL_SHORT_MESSAGE,
        PARAM_SUBID_SYS_GLOBAL_MIDI_ROUTE,
        PARAM_SUBID_SYS_GLOBAL_MIDI_CHANNEL,
        PARAM_SUBID_SYS_GLOBAL_SYNC_STEP,
        PARAM_SUBID_SYS_GLOBAL_LAST = PARAM_SUBID_SYS_GLOBAL_SYNC_STEP,
        NUM_SYS_GLOBAL_PARAM_SUBID,
  };

  /**
   * Meta Sub-IDs
   */  
  enum {
        INVALID_PARAM_SUBID = 0xFU,
  };

  /**
   * Types for edit parameters
   */  
  enum {
      EDIT_PARAM_TYPE_PERCENT = 0,
      EDIT_PARAM_TYPE_PERCENT_BIPOLAR,
      EDIT_PARAM_TYPE_SELECT,
  };

  // ----------------------------------------------------------

  /**
   * Initialize main board interface
   */  
  static inline uint8_t init() { return nts1_init(); }

  /**
   * Tear down main board interface
   */  
  static inline uint8_t teardown() { return nts1_teardown(); }

  /**
   * Process tx/rx communications with main board
   * Must be called regularly from the loop() function. 
   */  
  static inline uint8_t idle() { return nts1_idle(); }

  /**
   * Send a parameter change message to the NTS-1 main board
   */  
  static inline uint8_t paramChange(uint8_t id, uint8_t subid, uint16_t value) {
    return nts1_param_change(id, subid, value);
  }

  /**
   * Send a note on event to the NTS-1 main board
   */  
  static inline uint8_t noteOn(uint8_t note, uint8_t velo) {
    return nts1_note_on(note, velo);
  }

  /**
   * Send a note off event to the NTS-1 main board
   */  
  static inline uint8_t noteOff(uint8_t note) {
    return nts1_note_off(note);
  }
  
  /**
   * Request system version from the NTS-1 main board
   */  
  static inline uint8_t reqSysVersion(void) {
    return nts1_req_sys_version();
  }

  /**
   * Request value of given parameter from the NTS-1 main board
   */  
  static inline uint8_t reqParamValue(uint8_t id, uint8_t subid) {
    return nts1_req_param_value(id, subid);
  }
  
  /**
   * Request number of oscillators from the NTS-1 main board
   */  
  static inline uint8_t reqOscCount(void) {
    return nts1_req_osc_count();
  }

  /**
   * Request oscillator descriptor from the NTS-1 main board
   */  
  static inline uint8_t reqOscDesc(uint8_t idx) {
    return nts1_req_osc_desc(idx);
  }

  /**
   * Request oscillator edit parameter descriptor from the NTS-1 main board
   */  
  static inline uint8_t reqOscEditParamDesc(uint8_t idx) {
    return nts1_req_osc_edit_param_desc(idx);
  }  

  /**
   * Request number of filters from the NTS-1 main board
   */  
  static inline uint8_t reqFilterCount(void) {
    return nts1_req_filt_count();
  }

  /**
   * Request filter descriptor from the NTS-1 main board
   */  
  static inline uint8_t reqFilterDesc(uint8_t idx) {
    return nts1_req_filt_desc(idx);
  }
  
  /**
   * Request number of amp. env. generators from the NTS-1 main board
   */  
  static inline uint8_t reqAmpEGCount(void) {
    return nts1_req_ampeg_count();
  }

  /**
   * Request amp. env. generator descriptor from the NTS-1 main board
   */  
  static inline uint8_t reqAmpEGDesc(uint8_t idx) {
    return nts1_req_ampeg_desc(idx);
  }
  
  /**
   * Request number of modulation effects from the NTS-1 main board
   */  
  static inline uint8_t reqModCount(void) {
    return nts1_req_mod_count();
  }

  /**
   * Request modulation effect descriptor from the NTS-1 main board
   */  
  static inline uint8_t reqModDesc(uint8_t idx) {
    return nts1_req_mod_desc(idx);
  }

  /**
   * Request number of delay effects from the NTS-1 main board
   */  
  static inline uint8_t reqDelayCount(void) {
    return nts1_req_del_count();
  }

  /**
   * Request delay effect descriptor from the NTS-1 main board
   */  
  static inline uint8_t reqDelayDesc(uint8_t idx) {
    return nts1_req_del_desc(idx);
  }

  /**
   * Request number of reverb effects from the NTS-1 main board
   */
  static inline uint8_t reqReverbCount(void) {
    return nts1_req_rev_count();
  }

  /**
   * Request reverb effect descriptor from the NTS-1 main board
   */  
  static inline uint8_t reqReverbDesc(uint8_t idx) {
    return nts1_req_rev_desc(idx);
  }

  /**
   * Request number of arp. patterns from the NTS-1 main board
   */
  static inline uint8_t reqArpPatternCount(void) {
    return nts1_req_arp_pattern_count();
  }

  /**
   * Request arp. pattern descriptor from the NTS-1 main board
   */  
  static inline uint8_t reqArpPatternDesc(uint8_t idx) {
    return nts1_req_arp_pattern_desc(idx);
  }

  /**
   * Request number of arp. intervalss from the NTS-1 main board
   */
  static inline uint8_t reqArpIntervalsCount(void) {
    return nts1_req_arp_intervals_count();
  }

  /**
   * Request arp. intervals descriptor from the NTS-1 main board
   */  
  static inline uint8_t reqArpIntervalsDesc(uint8_t idx) {
    return nts1_req_arp_intervals_desc(idx);
  }
  
  /**
   * Register a handler function for received note off events
   */  
  void setNoteOffEventHandler(nts1_note_off_event_handler handler);

  /**
   * Register a handler function for received note on events
   */  
  void setNoteOnEventHandler(nts1_note_on_event_handler handler);

  /**
   * Register a handler function for received step tick events
   */  
  void setStepTickEventHandler(nts1_step_tick_event_handler handler);

  /**
   * Register a handler function for received unit descriptor events
   */
  void setUnitDescEventHandler(nts1_unit_desc_event_handler handler);

  /**
   * Register a handler function for received edit parameter descriptor events
   */  
  void setEditParamDescEventHandler(nts1_edit_param_desc_event_handler handler);

  /**
   * Register a handler function for received value events
   */  
  void setValueEventHandler(nts1_value_event_handler handler);

  /**
   * Register a handler function for received parameter change messages
   */  
  void setParamChangeHandler(nts1_param_change_handler handler);
  
};

#endif // _NTS1_H_
  
