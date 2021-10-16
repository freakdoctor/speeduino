/*
  Amesis Project
    ^ ^
  =( '' )=
  (")_(")
  &
  FDR Motorsport

  Speeduino Bosch electronic throttle body

*/

#include "sensors.h"
#include "globals.h"
#include "init.h"
#include "comms.h"

void tbCalibration()
{
    currentTime = millis();
    if((currentTime-previousTime)<2500)
    {
      //Auto Calibration TPS
      while (previousTime < 1000) {
        tbSensorVal = analogRead(pinTPS);
        // record the minimum sensor value
        configPage2.tpsMin = tbSensorVal;
      }
      while (previousTime < 2500) {
        tbSensorVal = analogRead(pinTPS);
        analogWrite(pinTbMotPwm, 255);
        // record the maximum sensor value
        configPage2.tpsMax = tbSensorVal;
      }
      if (previousTime >  2500) {
        analogWrite(pinTbMotPwm, 0);
        previousTime=currentTime;
      }
    }
}

void ppsMinCal()
{
  configPage13.pedalPositionMin = currentStatus.ppsADC;
}

void ppsMaxCal()
{
  configPage13.pedalPositionMax = currentStatus.ppsADC;
}

/*
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
    analogWrite(tbMotPwmPin, 0);
  }
  else
  {
    myPID.Compute();
    analogWrite(tbMotPwmPin, Output);
  }

}
*/
