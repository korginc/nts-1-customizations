---
layout: page_ja
title: Assembly
title_long: 組み立て
permalink: /ja/doc/assembly/
language: ja
---


## 基板を準備する

NTS-1 カスタム・パネルはオープン・ハードウェアであり、全ての設計資料は[GitHub](https://github.com/korginc/nts-1-customizations/tree/master/Custom_Panel_RevC)で公開されています。 

リファレンス基板の[PCB Gerber data](https://github.com/korginc/nts-1-customizations/tree/master/Custom_Panel_RevC/Gerber)を使えば、すぐに一般的な基板製造サービスでベアボードを注文することが可能です。

またリファレンス基板は[KiCAD project](https://github.com/korginc/nts-1-customizations/tree/master/Custom_Panel_RevC/KiCAD)プロジェクト形式でも提供されています。このファイルを使って独自のパネルデザインを始めることができます。

## 部品を準備する

リファレンス基板を作成するためには下記リストの部品が必要です。

部品表データ：[PDF](https://github.com/korginc/nts-1-customizations/raw/master/Custom_Panel_RevC/BOM-mouser.pdf), [Excel](https://github.com/korginc/nts-1-customizations/raw/master/Custom_Panel_RevC/BOM-mouser.xls)

_Tip：このエクセルファイルを[Mouser](https://www.mouser.com)にアップロードすることで自動的に必要な部品をカートに追加することが出来ます_


| Manufacturer       | Description                                                           | Qty | Datasheet     |
|:------------------ |:--------------------------------------------------------------------- |:---:|:------------- |
| Yageo              | Thick Film Resistors - SMD ZERO OHM JUMPER                            | 1   | [datasheet](https://www.mouser.com/datasheet/2/447/PYu-RC_Group_51_RoHS_L_10-1664068.pdf) |
| Yageo              | Thick Film Resistors - SMD 33 OHM 5%                                  | 1   | [datasheet](https://www.mouser.com/datasheet/2/447/PYu-RC_Group_51_RoHS_L_10-1664068.pdf) |
| Yageo              | Thick Film Resistors - SMD 47 OHM 5%                                  | 4   | [datasheet](https://www.mouser.com/datasheet/2/447/PYu-RC_Group_51_RoHS_L_10-1664068.pdf) |
| Yageo              | Thick Film Resistors - SMD 220 OHM 5%                                 | 8   | [datasheet](https://www.mouser.com/datasheet/2/447/PYu-RC_Group_51_RoHS_L_10-1664068.pdf) |
| Yageo              | Thick Film Resistors - SMD 100K OHM 5%                                | 1   | [datasheet](https://www.mouser.com/datasheet/2/447/PYu-RC_Group_51_RoHS_L_10-1664068.pdf) |
| Yageo              | Thick Film Resistors - SMD 10K OHM 5%                                 | 4   | [datasheet](https://www.mouser.com/datasheet/2/447/PYu-RC_Group_51_RoHS_L_10-1664068.pdf) |
| Yageo              | Thick Film Resistors - SMD 1K OHM 5%                                  | 2   | [datasheet](https://www.mouser.com/datasheet/2/447/PYu-RC_Group_51_RoHS_L_10-1664068.pdf) |
| Yageo              | Thick Film Resistors - SMD 47K OHM 5%                                 | 1   | [datasheet](https://www.mouser.com/datasheet/2/447/PYu-RC_Group_51_RoHS_L_10-1664068.pdf) |
| KEMET              | Multilayer Ceramic Capacitors - SMD 16V 0.1uF 0603 X7R 10%            | 4   | [datasheet](https://www.mouser.com/datasheet/2/212/KEM_C1090_X7R_ESD-1103328.pdf) |
| KEMET              | Multilayer Ceramic Capacitors - SMD 16V 1000pF 0603 X7R 10% AEC-Q200  | 2   | [datasheet](https://www.mouser.com/datasheet/2/212/KEM_C1090_X7R_ESD-1103328.pdf) |
| KEMET              | Multilayer Ceramic Capacitors - SMD 16V 1uF X5R 0805 10%              | 1   | [datasheet](https://www.mouser.com/datasheet/2/212/KEM_C1006_X5R_SMD-1103249.pdf) |
| TE Connectivity    | Headers & Wire Housings 38 MODII HDR DRST UNSHRD .100                 | 2   | [datasheet](https://www.mouser.com/datasheet/2/418/NG_CD_87215_J4-642383.pdf) |
| TE Connectivity    | Headers & Wire Housings 1X02P RCPT HV-100 TE                          | 1   | [datasheet](https://www.mouser.com/datasheet/2/418/NG_CD_215299_E-1247332.pdf) |
| TE Connectivity    | Headers & Wire Housings 6P RECPT VERT HV-100                          | 1   | [datasheet](https://www.mouser.com/datasheet/2/418/NG_CD_215299_E-1247285.pdf) |
| TE Connectivity    | Headers & Wire Housings 8P RECPT VERT HV-100                          | 2   | [datasheet](https://www.mouser.com/datasheet/2/418/NG_CD_215299_E-1247329.pdf) |
| TE Connectivity    | Headers & Wire Housings 1X03 POS VERT TIN                             | 2   | [datasheet](https://www.mouser.com/datasheet/2/418/NG_CD_826629_AC-1262378.pdf) |
| TE Connectivity    | Headers & Wire Housings 1X04 POS VERT TIN                             | 1   | [datasheet](https://www.mouser.com/datasheet/2/418/NG_CD_826629_AC-673695.pdf) |
| Omron              | Headers & Wire Housings Sensor I/O Connector                          | 2   | [datasheet](https://www.mouser.com/datasheet/2/307/en-xg8-1539045.pdf) |
| Kingbright         | Standard LEDs - Through Hole 5mm Red LED 640nm                        | 8   | [datasheet](https://www.mouser.com/datasheet/2/216/WP7113SRD-J4-1114353.pdf) |
| ALPS               | Potentiometers 10 KOhms 20%                                           | 1   | [datasheet](https://www.mouser.com/catalog/specsheets/alps_alps-s-a0003696969-1.pdf) |
| ALPS               | Tactile Switches RND 6.0x4.3mm 100gf                                  | 10  | [datasheet](https://www.mouser.com/catalog/specsheets/alps_alps-s-a0002902225-1.pdf) |
| STMicroelectronics | ARM Microcontrollers - MCU Value-Line ARM MCU 64kB 48 MHz             |  1  | [datasheet](https://www.mouser.com/datasheet/2/389/stm32f030f4-956260.pdf) |
| TE Connectivity    | Headers & Wire Housings 2 POS POST SHUNT                              | 1   | [datasheet](https://www.mouser.com/datasheet/2/418/NG_SS_108-37006_D-876462.pdf) |

![NTS-1 Custom Panel and Parts](../assets/NTS-1_ref_cp_revb_assembly.jpg)

## 部品のハンダ付け

全ての部品が揃ったら、[回路図](https://github.com/korginc/nts-1-customizations/blob/master/Custom_Panel_RevC/schematic.pdf)や[マウント図](https://github.com/korginc/nts-1-customizations/blob/master/Custom_Panel_RevC/mount_diagram.pdf)を参考にハンダ付けを行います。

### ハンダ付けのチュートリアル

ハンダ付けに関しての様々なチュートリアルがインターネット上にありますが、NTS-1カスタム・パネルでは表面実装部品のハンダ付けが必要であり、少し迷ってしまうかもしれません。

例えば下記のチュートリアルには必要な技術が全て紹介されています：

* [EEVblog Soldering Tutorial Part 1: Tools](https://www.youtube.com/watch?v=J5Sb21qbpEQ)
* [EEVblog Soldering Tutorial Part 2: Through Hole](https://www.youtube.com/watch?v=fYz5nIHH0iY)
* [EEVblog Soldering Tutorial Part 3: Surface Mount](https://www.youtube.com/watch?v=fYz5nIHH0iY)

## 組み立て

ハンダ付けが終わったらNTS-1のインターフェース・パネルを取り外して新たに作成したパネルに交換しましょう。

_Note: NTS-1 カスタムパネルは本体のシステムバージョン1.10以降でサポートされています_
_Note: このシステムバージョン1.10は2020年1月末にリリース予定です_

<!-- ![Replacing the NTS-1 digital kit's Panel](../assets/NTS-1_ref_cp_revb_replace.jpg) -->

{% include youtube.html id="Ct_vkzv_E_4" width="744" height="419" %}
