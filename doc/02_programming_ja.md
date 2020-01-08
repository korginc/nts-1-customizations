---
layout: page_ja
title: Programming
title_long: プログラミング
permalink: /ja/doc/programming/
language: ja
---

## Programming Hardware

The reference custom panel uses a [microcontroller (STM32F030R8)](https://www.st.com/en/microcontrollers-microprocessors/stm32f030r8.html) to scan for user interactions and communicate with the NTS-1 digital kit's main board. The most convenient way to program this microcontroller is via the exposed __SWD__ (4-pin) connector using an ST-LINK (or compatible) chip programmer, here are some examples:

* Standalone programmer (mini): [STLINK-V3MINI](https://www.st.com/en/development-tools/stlink-v3mini.html)
* Standalone programmer (modular): [STLINK-V3SET](https://www.st.com/en/development-tools/stlink-v3set.html)
* Development board including programmer: [NUCLEO-F030R8](https://www.st.com/en/evaluation-tools/nucleo-f030r8.html)
* OEM ST-LINK v2 compatible programmer dongles: i.e: [amazon](https://www.amazon.com/dp/B01J7N3RE6/ref=cm_sw_r_tw_dp_U_x_nkh.DbGGFNB6N) 

__Caution! In the case of many OEM programmers the Vref pin provides 3.3V on that pin instead of monitoring it for reference voltage is they should, make sure to NOT connect the Vref pin on such programmers. To be sure use a voltmeter to check the Vref pin of the programmer, if you see a voltage on it do NOT connect it to the reference custom panel board. Official STLINK programmers do not have that problem.__

Female-female DuPont pin cables with 2.54mm pitch will also be required to connect your programmer to the SWD pins of the reference board (sometimes provided with the programmer). Depending on the programmer you use the SWD pins of the reference board may not be in the same order, carefully read your programmer's manual and make sure you connect the pins in the right order. ([splitable or individual pin cables](https://www.amazon.com/40pcs-Female-2-54mm-Jumper-2x40pcs/dp/B00GSE2S98) may be useful if you need to reorder the connections)

## Connecting the Programmer

_note: The NTS-1 Custom Panel Reference Board is not 5V tolerant. Please don't connect 5V powered device. USB serial adapters sometimes have 3.3V/5V options, make sure to set it to 3.3V mode._

The ST-LINK compatible programmer should be connected to the __SWD__ connector in the following way:

__insert image__

## Preventing Panel Reset

While programming and generally during firmware development, it is recommended to prevent the reference custom panel from being reset by the NTS-1 digital kit's main board when communication timeouts occur.

To prevent panel resets, set the jumper on connector __CN11__ to the __DEBUG__ position.

The jumper can be placed back into the __NORMAL__ position when simply using the NTS-1 digital kit with the custom panel.

## Programming Methods

### Arduino IDE

An Arduino board definition package is provided for the reference custom panel, which allows to build firmwares from Arduino Sketches and program the microcontroller via the [Arduino IDE](https://www.arduino.cc/en/Main/Software). The board definition handles the low level details of the communication with the NTS-1 digital kit's main board, providing a high level interface suitable for fast prototyping.

#### Requirements

The following softwares must be installed:

* [Arduino IDE](https://www.arduino.cc/en/Main/Software)
* [STM32 Cube Programmer](https://www.st.com/en/development-tools/stm32cubeprog.html)

#### Setting Up the Board Definition

1. In the Arduino IDE, open the _Preferences_ from the _File_ menu
2. Open the _Additional Boards Manager URLs_ editing window
3. Add the following two URLs to the list:

```
 https://raw.githubusercontent.com/stm32duino/BoardManagerFiles/master/STM32/package_stm_index.json
 <TBD>
```

4. Click OK for both windows, and open the _Boards Manager_ from the _Tools > Board:_ menu
5. Search for _STM32 Cores_ and install version _1.7.0_
6. Search for _NTS-1 Custom Panels_ and install version _1.0.0_
7. Select _NTS-1 Custom Panel rev.B_ from the _Tools > Board:_ menu in the _NTS-1 Custom Panels_ group

#### Serial Monitoring

Monitoring via the built-in Arduino Serial object is possible by using a USB-Serial adapter (based on FTDI RS232 chip), such as [this one](https://www.mouser.jp/ProductDetail/FTDI/LC234X?qs=sGAEpiMZZMve4%2FbfQkoj%252BI%252BbU1q%2FCxfr%2FqVjw5o%252BdnQ%3D) or [this one](https://www.amazon.com/dp/B07TXVRQ7V/ref=cm_sw_r_tw_dp_U_x_2jh.DbQX9MS4Y).

Connect the USB-Serial adapter to the __SERIAL__ connector in the following way:

__insert image__

If using the Arduino IDE serial monitor, select the COM port corresponding to the USB-Serial adapter in the _tools > port_ menu. External serial monitoring software can also be used, in which case refer to that software's documentation.

#### Template Sketches

Some template Arduino Sketches are provided as examples and starting point for your own projects:

* Blank Template: bare minimum code required to build a Sketch with the NTS-1 Custom Panel board definition.
* Sequencer Template: basic 8 step sequencer with user interface scanning and LED control implemented via timer driven interrupts

You can find the templates in the _NTS-1 Custom Panels_ group of the _File > Examples_ menu.

#### Verify and Compile

You can compile your Sketch without uploading it to the board by pressing the _Verify_ button, or by selecting _Verify/Compile_ in the _Sketch_ menu.

Upon success you should see something like the output below in the Arduino IDE console.

```
 <add output example>
```

#### Uploading and Running

Once all prior steps have been completed. You can build and upload an Arduino Sketch to the reference custom panel board this way:

1. Make sure _Tools > Upload Method:_ is set to _SWD_.
2. Press the _Upload_ button, or select _Upload_ from the _Sketch_ menu.

Upon successful programming of the board you should see something like the output below in the Arduino IDE console:

```
  <Add example success build/upload output>
```

### Other Programming Methods

It is possible to program the reference custom panel directly using the [STM32 Cube Programmer](https://www.st.com/en/development-tools/stm32cubeprog.html) software from STMicro, or any other compatible programming/on-chip debugger software (i.e.: [OpenOCD](http://openocd.org/)), however it will be necessary to install toolchains on your own and build the firmware from scratch. 

Low level information about the communication protocol with the main board will be provided at a later date. 
