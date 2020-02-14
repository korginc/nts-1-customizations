/** 
 * @file nts-1.cpp
 * @brief NTS1 Class implementation.
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

#include "nts-1.h"

static NTS1 *sNts1Instance = nullptr;

static nts1_note_off_event_handler sNoteOffEventHandler = nullptr;
static nts1_note_on_event_handler sNoteOnEventHandler = nullptr; 
static nts1_step_tick_event_handler sStepTickEventHandler = nullptr;
static nts1_unit_desc_event_handler sUnitDescEventHandler = nullptr;
static nts1_edit_param_desc_event_handler sEditParamDescEventHandler = nullptr;
static nts1_value_event_handler sValueEventHandler = nullptr;
static nts1_param_change_handler sParamChangeHandler = nullptr;


NTS1::NTS1(void)
{
  sNts1Instance = this;
}

NTS1::~NTS1(void) {
  if (sNts1Instance == this)
    sNts1Instance = nullptr;
}

void NTS1::setNoteOffEventHandler(nts1_note_off_event_handler handler) {
  sNoteOffEventHandler = handler;
}

void NTS1::setNoteOnEventHandler(nts1_note_on_event_handler handler) {
  sNoteOnEventHandler = handler;
}

void NTS1::setStepTickEventHandler(nts1_step_tick_event_handler handler) {
  sStepTickEventHandler = handler;
}

void NTS1::setUnitDescEventHandler(nts1_unit_desc_event_handler handler) {
  sUnitDescEventHandler = handler;
}

void NTS1::setEditParamDescEventHandler(nts1_edit_param_desc_event_handler handler) {
  sEditParamDescEventHandler = handler;
}

void NTS1::setValueEventHandler(nts1_value_event_handler handler) {
  sValueEventHandler = handler;
}

void NTS1::setParamChangeHandler(nts1_param_change_handler handler) {
  sParamChangeHandler = handler;
}

extern "C" __attribute__((weak))
void nts1_handle_note_off_event(const nts1_rx_note_off_t *note_off) {
  if (sNoteOffEventHandler != nullptr) {
    sNoteOffEventHandler(note_off);
  }
}

extern "C" __attribute__((weak))
void nts1_handle_note_on_event(const nts1_rx_note_on_t *note_on) {
  if (sNoteOnEventHandler != nullptr) {
    sNoteOnEventHandler(note_on);
  }
}

extern "C" __attribute__((weak))
void nts1_handle_step_tick_event(void) { 
  if (sStepTickEventHandler != nullptr) {
    sStepTickEventHandler();
  }
}

extern "C" __attribute__((weak))
void nts1_handle_unit_desc_event(const nts1_rx_unit_desc_t *unit_desc) {
  if (sUnitDescEventHandler != nullptr) {
    sUnitDescEventHandler(unit_desc);
  }
}

extern "C" __attribute__((weak))
void nts1_handle_edit_param_desc_event(const nts1_rx_edit_param_desc_t *param_desc) {
  if (sEditParamDescEventHandler != nullptr) {
    sEditParamDescEventHandler(param_desc);
  }
}

extern "C" __attribute__((weak))
void nts1_handle_value_event(const nts1_rx_value_t *value) {
  if (sValueEventHandler != nullptr) {
    sValueEventHandler(value);
  }
}

extern "C" __attribute__((weak))
void nts1_handle_param_change(const nts1_rx_param_change_t *param_change) {
  if (sParamChangeHandler != nullptr) {
    sParamChangeHandler(param_change);
  }
}
