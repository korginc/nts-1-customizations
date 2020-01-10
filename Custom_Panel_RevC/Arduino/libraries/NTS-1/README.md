## NTS-1

This library provides a communication interface to NTS-1 digital kit's main board.

### API Constants

TODO

### API Data Types

TODO

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

#### Message Handlers

* **`void NTS1::setParamChangeHandler(nts1_param_change_handler handler)`**: Set handler function for param change messages  
_Params_ Handler function  

* **`void NTS1::setNoteOnEventHandler(nts1_note_on_event_handler handler)`**: Set handler function for note on events  
_Params_ Handler function  

* **`void NTS1::setNoteOffEventHandler(nts1_note_off_event_handler handler)`**: Set handler function for note off events  
_Params_ Handler function  

* **`void NTS1::setUnitDescEventHandler(nts1_unit_desc_event_handler handler)`**: Set handler function for unit descriptor replies  
_Params_ Handler function  

* **`void NTS1::setEditParamDescEventHandler(nts1_edit_param_desc_event_handler handler)`**: Set handler function for edit parameter descriptor replies  
_Params_ Handler function  

* **`void NTS1::setValueEventHandler(nts1_value_event_handler handler)`**: Set handler function for value replies  
_Params_ Handler function  
