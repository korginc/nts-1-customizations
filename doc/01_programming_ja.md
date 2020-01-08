---
layout: page_ja
title: Programming
title_long: プログラミング
permalink: /ja/doc/programming/
language: ja
---

## Programming

### Preparing the tools

Some tools are need to upload and debug your sketch.
ST-LINK v2 or compatible writer is necessary to upload the sketch. We share you some example as follows.

https://www.mouser.jp/ProductDetail/STMicroelectronics/NUCLEO-F030R8?qs=fK8dlpkaUMvL9GSuoYnNYw%3D%3D

https://www.amazon.com/dp/B01J7N3RE6/ref=cm_sw_r_tw_dp_U_x_nkh.DbGGFNB6N

And if you want to serial monitor on Arduino IDE, USB-serial convert adapter with FTDI chip(RS232) is also necessary.

https://www.mouser.jp/ProductDetail/FTDI/LC234X?qs=sGAEpiMZZMve4%2FbfQkoj%252BI%252BbU1q%2FCxfr%2FqVjw5o%252BdnQ%3D
https://www.amazon.com/dp/B07TXVRQ7V/ref=cm_sw_r_tw_dp_U_x_2jh.DbQX9MS4Y


### Connect the tools

note: NTS-1 is not 5V tolerant. Please don't connect 5V powered device. The USB serial adopter has sometimes 3.3V/5V options, please don't miss to set it as 3.3V mode.

ST-LINK compatible writer should be connected to the SWD connector, and the USB Serial converter should be connected to the Serial connector like a pictures below.

pictures

### Arduino IED setting
2. NTS-1 Custom Panelを取り付けます。CN11はDebug側にジャンパを取り付けます。(MAIN基板からリセットがかからなくなります）

"3. 写真のように、SWDポートにST-LINK互換ライターを接続します。
注意: Vref端子はリファレンス電圧の出力端子です。一部のST-LINK互換ライターは3.3V電源を供給しますが、接続しないで下さい。"

4. Arduino IDEをダウンロード、インストールします。
https://www.arduino.cc/en/main/software

"5. Tools->boards->board manager を選択、NTS-1と入力しインストールします。
https://raw.githubusercontent.com/stm32duino/BoardManagerFiles/master/STM32/package_stm_index.json"

5. Tools->boards->board manager を選択、NTS-1と入力しインストールします。Tools->boards->NTS-1を選択します。


### Upload and run
6. File->ExamplesからNTS-1 Custom templateを選択します。

"7. Uploadボタンを押し、コードのビルド、書き込みを行います。
NTS-1 Custom PanelのLEDが点灯すれば成功です"
