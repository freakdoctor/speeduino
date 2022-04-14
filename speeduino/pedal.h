/*
  Amesis Project
    ^ ^
  =( '' )=
  (")_(")
  &
  FDR Motorsport

  Speeduino Bosch electronic throttle body

*/

//#include "Arduino.h"
//#include "PID_v1.h"



/*
  Hardware Connections:
  -Pedal Input 0:        Pin (pinPedalPosition)
  -TPS 0:                   Pin A1

  -VNH7070AS H-Bridge Enable A: throttlePwmPin
  -VNH7070AS H-Bridge Input 1:  5V
  -VNH7070AS H-Bridge Input 2:  GND
  //pinMode(pinI1, OUTPUT); //VNH7070AS H-Bridge Input 1
  //pinMode(pinI2, OUTPUT); //VNH7070AS H-Bridge Input 2
  //digitalWrite(pinI2, LOW); //VNH7070AS H-Bridge Input 2
  //digitalWrite(pinI1, HIGH); //VNH7070AS H-Bridge Input 1

  //Pins assignments
  #define throttlePwmPin
*/

//Input = 0;
//Setpoint = 0;
//Define Variables we'll be connecting to
void tbCalibration();
void ppsMinCal();
void ppsMaxCal();
void tbCompute();
