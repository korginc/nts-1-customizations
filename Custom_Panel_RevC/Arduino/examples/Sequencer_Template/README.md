## Sequencer Template

This template demonstrates how to use the NTS1 Class to trigger note on/off events and set parameters on the NTS-1 digital kit main board. It also demonstrates how to configure hardware timers to generate interrupts to drive time sensitive operations like switch/rotary scanning and sequencer ticks.

* LEDs 1 to 8 are used to display the on/off state of each 8 step of the sequence
* Pressing switches 1 to 8 while holding down switch 10 toggles the on/off state of that step in the sequence
* Rotary 1/A allows to change the oscillator SHAPE parameter
* Turning rotary 1/A while holding down switches 1 to 8 changes the pitch for those steps
* Turning rotary 1/A while holding switch 10 changes the sequencer's tempo
* Switch 9 start and stops the sequencer
