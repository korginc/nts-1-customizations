---
# To modify the layout, see https://jekyllrb.com/docs/themes/#overriding-theme-defaults

layout: home_ja
permalink: /ja/
---

The appearance and user interface of the [Nu:Tekt NTS-1 digital kit](https://www.korg.com/nts_1) synthesizer can be customized by replacing the front panel with a custom created one. This site provides the base material and guidance for the creation of such custom panels.

_Note: Custom panels are supported by the NTS-1 digital kit firmware version 1.10 and newer_

_Note: Firmware version 1.10 will be released late January 2020_

## Reference Custom Panel Design

We provide an open hardware reference panel design that can be used for prototyping and as a template for the creation of new custom NTS-1 panel designs.

The reference design includes a minimal user interface in the form of 10 switches, 8 LEDs and a rotary, and also has Arduino shield compatible expansion connectors and ST-Morpho connectors like on the [STM32 Nucleo boards](https://www.st.com/en/evaluation-tools/stm32-nucleo-boards.html) to simplify prototyping. 

![Reference Custom Panel Board Rev.B](assets/NTS-1_ref_cp_revb_front.jpg)

## Getting Started

 1. [Assembly](doc/assembly/)
    1. [Preparing the PCB](doc/assembly/#preparing-the-pcb)
    2. [Acquiring parts](doc/assembly/#acquiring-parts)
    3. [Soldering](doc/assembly/#soldering)
    4. [Assembling](doc/assembly/#assembling)
 2. [Programming](doc/programming/)
    1. [Choosing a board programmer](doc/programming/#choosing-a-board-programmer)
    2. [Connecting the programmer](doc/programming/#connecting-the-programmer)
    3. [Programming with the Arduino IDE](doc/programming/#programming-with-the-arduino-ide)
 3. [Examples](doc/examples/)
    1. [Blank Template](doc/examples/#blank-template): Bare minimum code required to build an arduino Sketch
    2. [Sequencer Template](doc/examples/#sequencer-template): Basic 8 step sequencer with minimal user interface
    3. [Demo Boards](doc/examples/#demo-boards): Demo custom panel boards made for NAMM 2020

_Tip: Try out the Sequencer Template example first. Find usage instructions [here](doc/examples/#sequencer-template)_
