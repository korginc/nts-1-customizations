---
layout: page
title: Quick Start
title_long: クイックスタート
permalink: /ja/doc/quick-start/
language: ja
---

Follow these steps to use the template NTS-1 custom panel as-is.

## Preparing the PCB

Korg supplies the template PCB data and its demo code [here](). This template PCB has expansion connectors which has popular Arduino shield format, or similar format to STM32 MCU development boards; [Nucreo](https://www.st.com/en/evaluation-tools/stm32-nucleo-boards.html). And some switchs, LEDs, and a rotary volume is already equipped. You can start making with this template board, or if you are eager to design the whole interface, PCB data is also supplied as a KiCAD project file. Please proceed to your own design from this template circuit.

There are many PCB manufacture service over the world, 
 then please utilize them to make bare boards.

## Soldering and assembling

The parts list and the schematic are included in the zip file. Please solder needed parts on the PCB.

After completing the soldering, let's exchange the interface board of your NTS-1, with this custom board.

_note: NTS-1 main system has to be updated later than version 1.10 in order to work with this custom panel. Please make sure the software version of your NTS-1, before exchanging the board._

[NTS-1 software download]
*version 1.10 will be released in January 2020.

picture


### Connect the debugger

You need to prepare the ST-LINK/V2 compatible programmer to upload your cord on this custom panel. Detailed connection is described on the [programming page]().


### Arduino Code Templates

Install the Arduino IDE and add the board definition of NTS-1 custom panel. You can find it from the board manager on Arduino IDE. The demo cord can be loaded from Examples menu. We supplies two demo project:

* Blank: only the bare minimum code required.
* Sequencer: an 8 step sequencer with switch/VR scanning and LED control.

Detailed procedure is also described on the [programming page]().

### Play and modify

Now the custom panel works as a unique instrument. The template board works as follows if you upload the demo 1.

* Switch 1-8:
 enable or disable the note for the internal sequencer
* Switch 9:
 Play/Stop for the internal sequencer
* Switch 10:
 Shift function.
* VR A:
 changes the shape parameter of internal synth(set as waves; template user oscillator). And it has multiple functions accompanies with other interfaces.
 
 +Step1-8(Switch 1-8): change the pitch of each step
 +Shift(Switch 10): change the tempo.

We development team tried to make some gears, as examples of use case of this custom panel format. Please refer to them and make your own instruments.

movie
