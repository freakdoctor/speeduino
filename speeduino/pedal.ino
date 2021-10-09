/*
  Amesis Project
    ^ ^
  =( '' )=
  (")_(")

  Speeduino Bosch electronic throttle body


  Hardware Connections:
  -Throttle Input 0:        Pin A0
  -TPS 0:                   Pin A1

  -VNH7070AS H-Bridge Enable A: Pin 9
  -VNH7070AS H-Bridge Input 1:  Pin 8
  -VNH7070AS H-Bridge Input 2:  Pin 11
*/

#include "pedal.h"

//Pins assignments
/*
#define pinI1 4
#define pinI2 5
#define speedPin 9
*/



/*



void tbCalibration()
{
  //Set PWM frequency to 31.37255 kHz
 // TCCR1B = TCCR1B & 0b11111000 | 0x01;

  Input = 0;
  Setpoint = 0;
  
  pinMode(pinI1, OUTPUT); //VNH7070AS H-Bridge Input 1
  pinMode(pinI2, OUTPUT); //VNH7070AS H-Bridge Input 2
  pinMode(speedPin, OUTPUT); //VNH7070AS H-Bridge Enable
  digitalWrite(pinI2, LOW); //VNH7070AS H-Bridge Input 2
  digitalWrite(pinI1, HIGH); //VNH7070AS H-Bridge Input 1

  //Auto Calibration TPS
  while (millis() < 1000) {
    sensorValue = analogRead(1);
    // record the minimum sensor value
    minTps = sensorValue;
  }
  while (millis() < 2500) {
    sensorValue = analogRead(1);
    analogWrite(speedPin, 255);
    // record the maximum sensor value
    maxTps = sensorValue;
  }
  if (millis() >  2500) {
    analogWrite(speedPin, 0);
  }
}


void tbCompute()
{
  //PID Loop tunings
  myPID.SetTunings(0.15, 2.00, 0.00);
  //myPID.SetTunings(0.80, 0.20, 0.01);

   int TPS1 = constrain(analogRead(1), minTps, maxTps);  //Range: autocalibrated min and max values

  //PID Input from TPS
   Input = map(constrain(TPS1, minTps, maxTps), minTps, maxTps, 0, 180);

  int Pedal0 = map(constrain(analogRead(0), 70, 470), 70, 470, 0, 180);  //Range: 70 - 470


  //PID Setpoint from Throttle Pedal
  Setpoint = Pedal0;
  //Set throttle to 0
  if (Setpoint <= 5)
  {
    analogWrite(speedPin, 0);
  }
  else
  {
    myPID.Compute();
    analogWrite(speedPin, Output);
  }

}
*/