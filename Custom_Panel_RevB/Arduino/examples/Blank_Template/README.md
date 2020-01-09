## Blank Template

This template Arduino Sketch contains the bare minimum required to build a project for the NTS-1 Custom Panel reference board:

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
