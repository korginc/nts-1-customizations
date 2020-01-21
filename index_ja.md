---
# To modify the layout, see https://jekyllrb.com/docs/themes/#overriding-theme-defaults

layout: home_ja
permalink: /ja/
---

[Nu:Tekt NTS-1 digital kit](https://www.korg.com/nts_1) は自分でフロントパネルを作成し交換することで、外観とインターフェースをカスタマイズすることが可能です。
このサイトではこのようなカスタムパネルを作成するための資料やガイドラインを提供しています。

_Note: NTS-1 カスタムパネルは本体のシステムバージョン1.10以降でサポートされています。_

_Note: このシステムバージョン1.10は2020年2月末にリリース予定です。_

{% include youtube.html id="dL5zSNJrvd8" width="744" height="419" %}

## リファレンス基板について

独自のNTS-1 カスタムパネルを作成するためのテンプレートとして、またプロトタイピングを始める第一歩として使用可能なリファレンス基板です。基板の作成に必要な全てのデータはオープン・ハードウェアとして提供されます。

このリファレンス・パネルは必要最小限な操作子（10個のスイッチ、8個のLED、1個のロータリー・ボリューム）、またArduinoシールド互換の拡張コネクタ、STM32 Nucleo boardsシリーズ互換の拡張コネクタを備えており、迅速なプロトタイピングが可能となっています。

![Reference Custom Panel Board](assets/NTS-1_ref_cp_revb_front.jpg)

## Getting Started

 1. [組み立て](doc/assembly/)
    1. [基板を準備する](doc/assembly/#基板を準備する)
    2. [部品を準備する](doc/assembly/#部品を準備する)
    3. [部品のハンダ付け](doc/assembly/#部品のハンダ付け)
    4. [組み立て](doc/assembly/#組み立て)
 2. [プログラミング](doc/programming/)
    1. [書き込み装置を選ぶ](doc/programming/#書き込み装置を選ぶ)
    2. [接続](doc/programming/#接続)
    3. [Arduino IDEで書き込みを行う](doc/programming/#arduino-ideで書き込みを行う)
 3. [作成例](doc/demo/)
    1. [Blank Template](doc/demo/#blank-template): Bare minimum code required to build an arduino Sketch
    2. [Sequencer Template](doc/demo/#sequencer-template): Basic 8 step sequencer with minimal user interface
    3. [Demo Boards](doc/demo/#demo-boards): Demo custom panel boards made for NAMM 2020

_Tip: Try out the Sequencer Template example first. Find usage instructions [here](doc/examples/#sequencer-template)_
