---
layout: page_ja
title: Demo
title_long: デモ
permalink: /ja/doc/demo/
language: ja
---

## Arduino Sketch Examples

Arduino Sketch examples can be found in the _NTS-1 Custom Panels_ group of the _File > Examples_ menu, or obtained from the [github repository](https://github.com/korginc/NTS-1-customizations/tree/master/Custom_Panel_RevB/Arduino/examples).

### Blank Template

This template contains the bare minimum required to build a project for the NTS-1 Custom Panel reference board:

 ```
 #include <nts1.h>

 NTS1 nts1;

 void setup() {
   nts1.init(); // Performs hardware and peripheral initialization
   
   // Insert your setup code here
 }

 void loop() {
   nts1.idle(); // Runs internal processing of tx/rx communication with the main board
   
   // Insert your loop code here
 }
 ```
 
[See code on github](https://github.com/korginc/NTS-1-customizations/blob/master/Custom_Panel_RevB/Arduino/examples/Blank_Template/Blank_Template.ino).

### Sequencer Template

This template demonstrates how to use the NTS1 Class to trigger note on/off events and set parameters on the NTS-1 digital kit main board. It also demonstrates how to configure hardware timers to generate interrupts to drive time sensitive operations like switch/rotary scanning and sequencer ticks.

* LEDs 1 to 8 are used to display the on/off state of each 8 step of the sequence
* Pressing switches 1 to 8 while holding down switch 10 toggles the on/off state of that step in the sequence
* Rotary 1/A allows to change the oscillator SHAPE parameter
* Turning rotary 1/A while holding down switches 1 to 8 changes the pitch for those steps
* Turning rotary 1/A while holding switch 10 changes the sequencer's tempo
* Switch 9 start and stops the sequencer

[See code on github](https://github.com/korginc/NTS-1-customizations/blob/master/Custom_Panel_RevB/Arduino/examples/Sequencer_Template/Sequencer_Template.ino).

## Demo Boards

### Circular Sequencer

### Effect Pedal

### User Oscillator Editor
