/*
  Amesis Project
    ^ ^
  =( '' )=
  (")_(")
  &
  FDR Motorsport

  Speeduino Bosch electronic throttle body

*/

#include "Arduino.h"
//#include "PID_v1.h"


/*
  Hardware Connections:
  -Pedal Input 0:        Pin (pinPedalPosition)
  -TPS 0:                   Pin A1

  -VNH7070AS H-Bridge Enable A: tbMotPwmPin
  -VNH7070AS H-Bridge Input 1:  5V
  -VNH7070AS H-Bridge Input 2:  GND
  //pinMode(pinI1, OUTPUT); //VNH7070AS H-Bridge Input 1
  //pinMode(pinI2, OUTPUT); //VNH7070AS H-Bridge Input 2
  //digitalWrite(pinI2, LOW); //VNH7070AS H-Bridge Input 2
  //digitalWrite(pinI1, HIGH); //VNH7070AS H-Bridge Input 1

  //Pins assignments
  #define tbMotPwmPin 
*/

//Specify the links and initial tuning parameters
//PID myPID(&Input, &Output, &Setpoint, 1, 0, 0, DIRECT);

//Define Variables we'll be connecting to
//double Setpoint, Input, Output;

//myPID.SetMode(AUTOMATIC); // PID Mode

//Set PWM frequency to 31.37255 kHz
// TCCR1B = TCCR1B & 0b11111000 | 0x01;
  

//pinMode(tbMotPwmPin, OUTPUT); //VNH7070AS H-Bridge Enable


//Input = 0;
//Setpoint = 0;

byte tbSensorVal;
unsigned long currentTime=0;
unsigned long previousTime=0;

void tbCalibration();
//void tbCompute();
