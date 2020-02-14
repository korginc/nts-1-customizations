/** 
 * @file nts1_iface.h 
 * @brief C API handling communication with the NTS-1 digital kit's main board.
 *
 * Provides initialization of necessary peripherals, handling of low level 
 * protocol details and convenience functions for bidrectional communication
 * with the NTS-1 digital kit's main board via SPI.
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


#ifndef __nts1_iface_h
#define __nts1_iface_h

#include <stdint.h>

enum {
  k_nts1_status_ok      = 0x00U,
  k_nts1_status_error   = 0x01U,
  k_nts1_status_busy    = 0x02U,
  k_nts1_status_timeout = 0x03U,
};

typedef uint8_t nts1_status_t;

enum {
  k_nts1_tx_event_id_note_off            = 0x00U,
  k_nts1_tx_event_id_note_on             = 0x01U,
  k_nts1_tx_event_id_req_unit_count      = 0x10U,
  k_nts1_tx_event_id_req_unit_desc       = 0x11U,
  k_nts1_tx_event_id_req_edit_param_desc = 0x12U,
  k_nts1_tx_event_id_req_value           = 0x13U,
};

typedef uint8_t nts1_tx_event_id_t;

enum {
  k_nts1_rx_event_id_note_off        = 0x0U,
  k_nts1_rx_event_id_note_on         = 0x1U,
  k_nts1_rx_event_id_step_tick       = 0x2U,
  k_nts1_rx_event_id_unit_desc       = 0x11U,
  k_nts1_rx_event_id_edit_param_desc = 0x12U,
  k_nts1_rx_event_id_value           = 0x13U,
};

typedef uint8_t nts1_rx_event_id_t;

enum {
  // osc
  k_param_id_osc_base = 0U,
  k_param_id_osc_type = k_param_id_osc_base,
  k_param_id_osc_shape,
  k_param_id_osc_shift_shape,
  k_param_id_osc_lfo_rate,
  k_param_id_osc_lfo_depth,
  k_param_id_osc_edit, // with subid
  k_param_id_osc_last = k_param_id_osc_edit,
  
  // ampeg
  k_param_id_ampeg_base,
  k_param_id_ampeg_type = k_param_id_ampeg_base,
  k_param_id_ampeg_attack,
  k_param_id_ampeg_release,
  k_param_id_ampeg_lfo_rate,
  k_param_id_ampeg_lfo_depth,
  k_param_id_ampeg_unset3,
  k_param_id_ampeg_last = k_param_id_ampeg_unset3,
  
  // filter
  k_param_id_filt_base,
  k_param_id_filt_type = k_param_id_filt_base,
  k_param_id_filt_cutoff,
  k_param_id_filt_peak,
  k_param_id_filt_lfo_rate,
  k_param_id_filt_lfo_depth,
  k_param_id_filt_unset3,
  k_param_id_filt_last = k_param_id_filt_unset3,
  
  // modulation effect
  k_param_id_mod_base,
  k_param_id_mod_type = k_param_id_mod_base,
  k_param_id_mod_time,
  k_param_id_mod_depth,
  k_param_id_mod_unset1,
  k_param_id_mod_unset2,
  k_param_id_mod_unset3,
  k_param_id_mod_last = k_param_id_mod_unset3,
  
  // delay effect
  k_param_id_del_base,
  k_param_id_del_type = k_param_id_del_base,
  k_param_id_del_time,
  k_param_id_del_depth,
  k_param_id_del_unset1,
  k_param_id_del_mix,
  k_param_id_del_unset3,
  k_param_id_del_last = k_param_id_del_unset3,
  
  // reverb effect
  k_param_id_rev_base,
  k_param_id_rev_type = k_param_id_rev_base,
  k_param_id_rev_time,
  k_param_id_rev_depth,
  k_param_id_rev_unset1,
  k_param_id_rev_mix,
  k_param_id_rev_unset3,
  k_param_id_rev_last = k_param_id_rev_unset3,
  
  // arpeggiator
  k_param_id_arp_base,
  k_param_id_arp_pattern = k_param_id_arp_base,
  k_param_id_arp_intervals,
  k_param_id_arp_length,
  k_param_id_arp_state,
  k_param_id_arp_tempo,
  k_param_id_arp_last = k_param_id_arp_tempo,
  
  k_num_param_id,

  // dummy param ids for system values
  k_param_id_sys_base = k_num_param_id,
  k_param_id_sys_version = k_param_id_sys_base,
  k_param_id_sys_global,
  k_param_id_sys_last = k_param_id_sys_global,

  k_num_all_param_id,
  
  k_param_id_invalid = 0x7FU,
  
  k_num_osc_param_id   = k_param_id_osc_last - k_param_id_osc_base,
  k_num_ampeg_param_id = k_param_id_ampeg_last - k_param_id_ampeg_base,
  k_num_filt_param_id  = k_param_id_filt_last - k_param_id_filt_base,
  k_num_mod_param_id   = k_param_id_mod_last - k_param_id_mod_base,
  k_num_del_param_id   = k_param_id_del_last - k_param_id_del_base,
  k_num_rev_param_id   = k_param_id_rev_last - k_param_id_rev_base,
  k_num_arp_param_id   = k_param_id_arp_last - k_param_id_arp_base,
  k_num_sys_param_id   = k_param_id_sys_last - k_param_id_sys_base,  
};

typedef uint8_t param_main_id_t;

enum {
  // osc edit parameters
  k_param_subid_osc_base  = 0U,
  k_param_subid_osc_edit1 = k_param_subid_osc_base,
  k_param_subid_osc_edit2,
  k_param_subid_osc_edit3,
  k_param_subid_osc_edit4,
  k_param_subid_osc_edit5,
  k_param_subid_osc_edit6,
  k_param_subid_osc_last = k_param_subid_osc_edit6,
  k_num_osc_param_subid,
};

enum {
  // global parameters
  k_param_subid_sys_global_base = 0,
  k_param_subid_sys_global_input_route = k_param_subid_sys_global_base,
  k_param_subid_sys_global_input_trim,
  k_param_subid_sys_global_syncout_polarity,
  k_param_subid_sys_global_syncin_polarity,
  k_param_subid_sys_global_tempo_range,
  k_param_subid_sys_global_clock_source,
  k_param_subid_sys_global_short_message,
  k_param_subid_sys_global_midi_route,
  k_param_subid_sys_global_midi_channel,
  k_param_subid_sys_global_sync_step,
  k_param_subid_sys_global_last = k_param_subid_sys_global_sync_step,
  k_num_sys_global_param_subid,
};

#define k_invalid_param_subid 0xF

typedef uint8_t param_sub_id_t;

enum {
      k_edit_param_type_percent = 0,
      k_edit_param_type_percent_bipolar,
      k_edit_param_type_select,
};

#define param_id_get_main(id) ((id)>>8)
#define param_id_get_sub(id)  ((id)&0x0F)
#define make_param_id(main, sub) ((((main) & 0x7F)<<8)|((sub) & 0x0F))

  typedef uint16_t param_id_t;

#define k_param_id_none    0x7FFF
#define k_param_id_invalid 0x7FFF


typedef struct nts1_tx_event {
  uint8_t event_id;
  uint8_t msb;         // 7 bit
  uint8_t lsb;         // 7 bit
} nts1_tx_event_t;

typedef struct nts1_tx_param_change {
  uint8_t param_id;
  uint8_t param_subid;
  uint8_t msb;         // 7 bit
  uint8_t lsb;         // 7 bit
} nts1_tx_param_change_t;

typedef struct nts1_rx_event_header {
  uint8_t size; // size of whole message incl. this header
  uint8_t event_id;
  // events are of variable size
  // data payload is encoded in 7 bit words
} nts1_rx_event_header_t;

typedef struct nts1_rx_param_change {
  uint8_t param_id;
  uint8_t param_subid;
  uint8_t msb;         // 7 bit
  uint8_t lsb;         // 7 bit
} nts1_rx_param_change_t;

typedef struct {
  uint8_t  note;
  uint8_t  velocity;
} nts1_rx_note_on_t;

typedef struct {
  uint8_t  note;
  uint8_t  padding;
} nts1_rx_note_off_t;

typedef struct {
  uint8_t  req_id;
  uint8_t  main_id;
  uint8_t  sub_id;
  uint8_t  padding;
  uint16_t value;
  uint8_t padding2[10];
} nts1_rx_value_t;

typedef struct {
  uint8_t  main_id;
  uint8_t  sub_id;
  uint8_t  param_count;
  char     name[13];
} nts1_rx_unit_desc_t;

typedef struct {
  uint8_t  main_id;
  uint8_t  sub_id;
  uint8_t  value_type;
   int8_t  min;
   int8_t  max;
  char     name[13];
} nts1_rx_edit_param_desc_t;

typedef void (*nts1_note_off_event_handler)(const nts1_rx_note_off_t *);
typedef void (*nts1_note_on_event_handler)(const nts1_rx_note_on_t *);
typedef void (*nts1_step_tick_event_handler)(void);
typedef void (*nts1_unit_desc_event_handler)(const nts1_rx_unit_desc_t *);
typedef void (*nts1_edit_param_desc_event_handler)(const nts1_rx_edit_param_desc_t *);
typedef void (*nts1_value_event_handler)(const nts1_rx_value_t *);
typedef void (*nts1_param_change_handler)(const nts1_rx_param_change_t *);

#ifdef __cplusplus
extern "C" {
#endif  
  
  nts1_status_t nts1_init();
  nts1_status_t nts1_teardown();
  nts1_status_t nts1_idle();
  
  nts1_status_t nts1_send_events(nts1_tx_event_t *events, uint8_t count);

  static inline nts1_status_t nts1_send_event(nts1_tx_event_t *event) {
    return nts1_send_events(event, 1);
  }

  nts1_status_t nts1_send_param_changes(nts1_tx_param_change_t *param_changes, uint8_t count);

  static inline nts1_status_t nts1_send_param_change(nts1_tx_param_change_t *param_change) {
    return nts1_send_param_changes(param_change, 1);
  }

  static inline uint32_t nts1_size_7to8(uint32_t size7) {
    return 7 * (size7 / 8) + size7%8 - 1;
  }

  static inline uint32_t nts1_size_8to7(uint32_t size8) {
    return 8 * (size8 / 7) + size8%7 + 1;
  }
  
  uint32_t nts1_convert_7to8(uint8_t *dest8, const uint8_t *src7, uint32_t size7);
  uint32_t nts1_convert_8to7(uint8_t *dest7, const uint8_t *src8, uint32_t size8);

  nts1_status_t nts1_param_change(uint8_t id, uint8_t subid, uint16_t value);
  
  nts1_status_t nts1_note_on(uint8_t note, uint8_t velo);  
  nts1_status_t nts1_note_off(uint8_t note);
  
  nts1_status_t nts1_req_sys_version(void);
  
  nts1_status_t nts1_req_param_value(uint8_t id, uint8_t subid);
  
  nts1_status_t nts1_req_osc_count(void);
  nts1_status_t nts1_req_osc_desc(uint8_t idx);
  nts1_status_t nts1_req_osc_edit_param_desc(uint8_t idx);  

  nts1_status_t nts1_req_filt_count(void);
  nts1_status_t nts1_req_filt_desc(uint8_t idx);
  
  nts1_status_t nts1_req_ampeg_count(void);
  nts1_status_t nts1_req_ampeg_desc(uint8_t idx);
  
  nts1_status_t nts1_req_mod_count(void);
  nts1_status_t nts1_req_mod_desc(uint8_t idx);

  nts1_status_t nts1_req_del_count(void);
  nts1_status_t nts1_req_del_desc(uint8_t idx);

  nts1_status_t nts1_req_rev_count(void);
  nts1_status_t nts1_req_rev_desc(uint8_t idx);

  nts1_status_t nts1_req_arp_pattern_count(void);
  nts1_status_t nts1_req_arp_pattern_desc(uint8_t idx);

  nts1_status_t nts1_req_arp_intervals_count(void);
  nts1_status_t nts1_req_arp_intervals_desc(uint8_t idx);
  
  // RX Event handlers, weakly defined in C++ NTS1 object. 
  void nts1_handle_note_off_event(const nts1_rx_note_off_t *note_off);
  void nts1_handle_note_on_event(const nts1_rx_note_on_t *note_on);
  void nts1_handle_step_tick_event(void);
  void nts1_handle_unit_desc_event(const nts1_rx_unit_desc_t *unit_desc);
  void nts1_handle_edit_param_desc_event(const nts1_rx_edit_param_desc_t *param_desc);
  void nts1_handle_value_event(const nts1_rx_value_t *value);
  void nts1_handle_param_change(const nts1_rx_param_change_t *param_change);
  
#ifdef __cplusplus
}
#endif

#endif // __nts1_iface_h
  
