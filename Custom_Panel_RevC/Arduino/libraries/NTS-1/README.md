## NTS-1

This library provides a communication interface to NTS-1 digital kit's main board.

### API Constants

#### Success Statuses
* **`NTS1::STATUS_OK`**: Operation completed without error
* **`NTS1::STATUS_ERR`**: Operation failed with error
* **`NTS1::STATUS_BUSY`**: Operation failed due to ongoing concurent operation
* **`NTS1::STATUS_TIMEOUT`**: Operation timed out

#### Transmittable Event IDs
* **`NTS1::TX_EVENT_ID_NOTE_OFF`**: Note off event
* **`NTS1::TX_EVENT_ID_NOTE_ON`**: Note on event
* **`NTS1::TX_EVENT_ID_REQ_UNIT_COUNT`**: Request number of specified unit types
* **`NTS1::TX_EVENT_ID_REQ_UNIT_DESC`**: Request descritptor for specified unit
* **`NTS1::TX_EVENT_ID_REQ_EDIT_PARAM_DESC`**: Request descriptor for specified edit parameter
* **`NTS1::TX_EVENT_ID_REQ_VALUE`**: Request current value for given parameter

#### Receiveable Event IDs
* **`NTS1::RX_EVENT_ID_NOTE_OFF`**: Note off event
* **`NTS1::RX_EVENT_ID_NOTE_ON`**: Note on event
* **`NTS1::RX_EVENT_ID_STEP_TICK`**: Step tick event
* **`NTS1::RX_EVENT_ID_UNIT_DESC`**: Unit descriptor
* **`NTS1::RX_EVENT_ID_EDIT_PARAM_DESC`**: Edit parameter descriptor
* **`NTS1::RX_EVENT_ID_VALUE`**: Parameter value

#### Main Parameter IDs
##### Oscillator
* **`NTS1::PARAM_ID_OSC_TYPE`**: Oscillator type/index (0, num of osc.)
* **`NTS1::PARAM_ID_OSC_SHAPE`**: Shape parameter (0, 1023)
* **`NTS1::PARAM_ID_OSC_SHIFT_SHAPE`**: Alternate shape parameter (0, 1023)
* **`NTS1::PARAM_ID_OSC_LFO_RATE`**: LFO rate (0, 1023)
* **`NTS1::PARAM_ID_OSC_LFO_DEPTH`**: LFO depth (0, 1023)
* **`NTS1::PARAM_ID_OSC_EDIT`**: Edit parameter when available, see PARAM_SUBID

##### Filter
* **`NTS1::PARAM_ID_FILT_TYPE`**: Filter type/index (0, 6)
* **`NTS1::PARAM_ID_FILT_CUTOFF`**: Filter cutoff frequency (0, 1023)
* **`NTS1::PARAM_ID_FILT_PEAK`**: Filter resonance (0, 1023)
* **`NTS1::PARAM_ID_FILT_LFO_RATE`**: Sweep rate (0, 1023)
* **`NTS1::PARAM_ID_FILT_LFO_DEPTH`**: Sweep depth (0, 1023)

##### Amplitude E.G.
* **`NTS1::PARAM_ID_AMPEG_TYPE`**: Envelope type/index (0, 4)
* **`NTS1::PARAM_ID_AMPEG_ATTACK`**: Envelope attack time (0, 1023)
* **`NTS1::PARAM_ID_AMPEG_RELEASE`**: Envelope release time (0, 1023)
* **`NTS1::PARAM_ID_AMPEG_LFO_RATE`**: Tremollo rate (0, 1023)
* **`NTS1::PARAM_ID_AMPEG_LFO_DEPTH`**: Tremollo depth (0, 1023)

##### Modulation Effect
* **`NTS1::PARAM_ID_MOD_TYPE`**: Modulation effect type/index (0, num of mod. fx)
* **`NTS1::PARAM_ID_MOD_TIME`**: Time parameter (0, 1023)
* **`NTS1::PARAM_ID_MOD_DEPTH`**: Depth parameter (0, 1023)

##### Delay Effect
* **`NTS1::PARAM_ID_DEL_TYPE`**: Delay effect type/index (0, num of del. fx)
* **`NTS1::PARAM_ID_DEL_TIME`**: Time parameter (0, 1023)
* **`NTS1::PARAM_ID_DEL_DEPTH`**: Depth parameter (0, 1023)
* **`NTS1::PARAM_ID_DEL_MIX`**: Wet/dry mix parameter (0, 1023)

##### Reverb Effect
* **`NTS1::PARAM_ID_REV_TYPE`**: Reverb effect type/index (0, num of rev. fx)
* **`NTS1::PARAM_ID_REV_TIME`**: Time parameter (0, 1023)
* **`NTS1::PARAM_ID_REV_DEPTH`**: Depth parameter (0, 1023)
* **`NTS1::PARAM_ID_REV_MIX`**: Wet/dry mix parameter (0, 1023)

##### Arpeggiator
* **`NTS1::PARAM_ID_ARP_PATTERN`**: Arpeggiator pattern
* **`NTS1::PARAM_ID_ARP_INTERVALS`**: Arpeggiator note intervals
* **`NTS1::PARAM_ID_ARP_LENGTH`**: Arpeggiator sequence length
* **`NTS1::PARAM_ID_ARP_STATE`**: Current arpeggiator state
* **`NTS1::PARAM_ID_ARP_TEMPO`**: Arpeggiator tempo

##### Meta Parameters
* **`NTS1::PARAM_ID_SYS_VERSION`**: Current main board system version. 
* **`NTS1::PARAM_ID_SYS_GLOBAL`**: Global options, see corresponding sub-ID. 
* **`NTS1::PARAM_ID_INVALID`**: Invalid parameter ID

#### Sub Parameter IDs
##### Oscillator
* **`NTS1::PARAM_SUBID_OSC_EDIT1`**
* **`NTS1::PARAM_SUBID_OSC_EDIT2`** 
* **`NTS1::PARAM_SUBID_OSC_EDIT3`** 
* **`NTS1::PARAM_SUBID_OSC_EDIT4`** 
* **`NTS1::PARAM_SUBID_OSC_EDIT5`** 
* **`NTS1::PARAM_SUBID_OSC_EDIT6`**

##### Global Options
* **`NTS1::PARAM_SUBID_SYS_GLOBAL_INPUT_ROUTE`**
* **`NTS1::PARAM_SUBID_SYS_GLOBAL_INPUT_TRIM`**
* **`NTS1::PARAM_SUBID_SYS_GLOBAL_SYNCOUT_POLARITY`**
* **`NTS1::PARAM_SUBID_SYS_GLOBAL_SYNCIN_POLARITY`**
* **`NTS1::PARAM_SUBID_SYS_GLOBAL_TEMPO_RANGE`**
* **`NTS1::PARAM_SUBID_SYS_GLOBAL_CLOCK_SOURCE`**
* **`NTS1::PARAM_SUBID_SYS_GLOBAL_SHORT_MESSAGE`**
* **`NTS1::PARAM_SUBID_SYS_GLOBAL_MIDI_ROUTE`**
* **`NTS1::PARAM_SUBID_SYS_GLOBAL_SYNC_STEP`**

##### Other
* **`NTS1::INVALID_PARAM_SUBID`**: 

#### Parameter Type
* **`NTS1::EDIT_PARAM_TYPE_PERCENT`**
* **`NTS1::EDIT_PARAM_TYPE_PERCENT_BIPOLAR`**
* **`NTS1::EDIT_PARAM_TYPE_SELECT`**

### API Data Types

#### Handlers for Received Messages

* **`typedef void (*nts1_note_off_event_handler)(const nts1_rx_note_off_t *)`**
* **`typedef void (*nts1_note_on_event_handler)(const nts1_rx_note_on_t *)`**
* **`typedef void (*nts1_step_tick_event_handler)(void)`**
* **`typedef void (*nts1_unit_desc_event_handler)(const nts1_rx_unit_desc_t *)`**
* **`typedef void (*nts1_edit_param_desc_event_handler)(const nts1_rx_edit_param_desc_t *)`**
* **`typedef void (*nts1_value_event_handler)(const nts1_rx_value_t *)`**
* **`typedef void (*nts1_param_change_handler)(const nts1_rx_param_change_t *)`**

#### Receiveable Types

* **`nts1_rx_param_change_t`**

```
  typedef struct nts1_rx_param_change {
    uint8_t param_id;
    uint8_t param_subid;
    uint8_t msb;         // 7 bit
    uint8_t lsb;         // 7 bit
  } nts1_rx_param_change_t;
```

* **`nts1_rx_note_off_t`**

```
  typedef struct {
    uint8_t  note;
    uint8_t  padding;
  } nts1_rx_note_off_t;
```

* **`nts1_rx_note_on_t`**

```
  typedef struct {
    uint8_t  note;
    uint8_t  velocity;
  } nts1_rx_note_on_t;
```

* **`nts1_rx_value_t`**

```
  typedef struct {
    uint8_t  req_id;
    uint8_t  main_id;
    uint8_t  sub_id;
    uint8_t  padding;
    uint16_t value;
    uint8_t padding2[10];
  } nts1_rx_value_t;
```

* **`nts1_rx_unit_desc_t`**

```
  typedef struct {
    uint8_t  main_id;
    uint8_t  sub_id;
    uint8_t  param_count;
    char     name[13];
  } nts1_rx_unit_desc_t;
```

* **`nts1_rx_edit_param_desc_t`**

```
  typedef struct {
    uint8_t  main_id;
    uint8_t  sub_id;
    uint8_t  value_type;
     int8_t  min;
     int8_t  max;
    char     name[13];
  } nts1_rx_edit_param_desc_t;
```

### API Functions

* **`NTS1::NTS(void)`**: Default class constructor  

* **`void NTS1::init(void)`**: Initialialize interface to main board  

* **`void NTS1::idle(void)`**: Process tx/rx communications with main board  

#### Direct Messages

* **`uint8_t NTS1::paramChange(uint8_t id, uint8_t subid, uint16_t value)`**: Send a parameter change message  
_Params_ Parameter id  
_Params_ Parameter sub-id  
_Params_ Value  
_Returns_ Sucess status  

* **`uint8_t NTS1::noteOn(uint8_t note, uint8_t velo)`**: Send a a note on event  
_Params_ Note (0-127 per MIDI interpretation)  
_Params_ Velocity  
_Returns_ Sucess status  

* **`uint8_t NTS1::noteOff(uint8_t note)`**: Send a a note off event  
_Params_ Note (0-127 per MIDI interpretation)  
_Returns_ Sucess status  

#### Requests

* **`uint8_t NTS1::reqSysVersion(void)`**: Request main board system version  
_Returns_ Sucess status  

* **`uint8_t NTS1::reqParamValue(uint8_t id, uint8_t subid)`**: Request value for specified parameter  
_Params_ param ID
_Params_ param sub-ID
_Returns_ Sucess status  

* **`uint8_t NTS1::reqOscCount(void)`**: Request number of oscillators  
_Returns_ Sucess status  

* **`uint8_t NTS1::reqOscDesc(uint8_t idx)`**: Request oscillator descriptor  
_Params_ Index  
_Returns_ Sucess status  

* **`uint8_t NTS1::reqOscEditParamDesc(uint8_t idx)`**: Request oscillator edit parameter descriptor  
_Returns_ Sucess status  

* **`uint8_t NTS1::reqFilterCount(void)`**: Request number of filters  
_Returns_ Sucess status  

* **`uint8_t NTS1::reqFilterDesc(uint8_t idx)`**: Request filter descriptor  
_Params_ Index  
_Returns_ Sucess status  

* **`uint8_t NTS1::reqAmpEGCount(void)`**: Request number of amplitude env. generators  
_Returns_ Sucess status  

* **`uint8_t NTS1::reqAmpEGDesc(uint8_t idx)`**: Request amplitude env. generator descriptor  
_Params_ Index  
_Returns_ Sucess status  

* **`uint8_t NTS1::reqModCount(void)`**: Request number of modulation effects  
_Returns_ Sucess status  

* **`uint8_t NTS1::reqModDesc(uint8_t idx)`**: Request modulation effect descriptor  
_Params_ Index  
_Returns_ Sucess status  

* **`uint8_t NTS1::reqDelayCount(void)`**: Request number of delay effects  
_Returns_ Sucess status  

* **`uint8_t NTS1::reqDelayDesc(uint8_t idx)`**: Request delay effect descriptor  
_Params_ Index  
_Returns_ Sucess status  

* **`uint8_t NTS1::reqReverbCount(void)`**: Request number of reverb effects  
_Returns_ Sucess status  

* **`uint8_t NTS1::reqReverbDesc(uint8_t idx)`**: Request reverb effect descriptor  
_Params_ Index  
_Returns_ Sucess status  

* **`uint8_t NTS1::reqArpPatternCount(void)`**: Request number of arpeggiator patterns  
_Returns_ Sucess status  

* **`uint8_t NTS1::reqArpPatternDesc(uint8_t idx)`**: Request arpeggiator pattern descriptor  
_Params_ Index  
_Returns_ Sucess status  

* **`uint8_t NTS1::reqArpIntervalsCount(void)`**: Request number of arpeggiator intervals  
_Returns_ Sucess status  

* **`uint8_t NTS1::reqArpIntervalsDesc(uint8_t idx)`**: Request arpeggiator intervals descriptor  
_Params_ Index  
_Returns_ Sucess status  



#### Message Handlers

* **`void NTS1::setParamChangeHandler(nts1_param_change_handler handler)`**: Set handler function for param change messages  
_Params_ Handler function  

* **`void NTS1::setNoteOnEventHandler(nts1_note_on_event_handler handler)`**: Set handler function for note on events  
_Params_ Handler function  

* **`void NTS1::setNoteOffEventHandler(nts1_note_off_event_handler handler)`**: Set handler function for note off events  
_Params_ Handler function  

* **`void NTS1::setStepTickEventHandler(nts1_step_tick_event_handler handler)`**: Set handler function for step tick events  
_Params_ Handler function  

* **`void NTS1::setUnitDescEventHandler(nts1_unit_desc_event_handler handler)`**: Set handler function for unit descriptor replies  
_Params_ Handler function  

* **`void NTS1::setEditParamDescEventHandler(nts1_edit_param_desc_event_handler handler)`**: Set handler function for edit parameter descriptor replies  
_Params_ Handler function  

* **`void NTS1::setValueEventHandler(nts1_value_event_handler handler)`**: Set handler function for value replies  
_Params_ Handler function  
