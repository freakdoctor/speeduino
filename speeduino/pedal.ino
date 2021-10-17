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
#include "src/PID_v1/PID_v1.h"


//Define Variables we'll be connecting to
long Setpoint, Input, Output;

//Specify the links and initial tuning parameters
PID tbPID(&Input, &Output, &Setpoint, 1, 0, 0, DIRECT);

void tbCalibration()
{
    currentTime = millis();
    previousTime=currentTime;
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
        analogWrite(pinThrottlePwm, 255);
        // record the maximum sensor value
        configPage2.tpsMax = tbSensorVal;
      }
      if (previousTime >  2500) {
        analogWrite(pinThrottlePwm, 0);
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
  tbPID.SetMode(AUTOMATIC); // PID Mode
  //PID Loop tunintbPID.SetTunings(0.15, 2.00, 0.00);
  tbPID.SetTunings(0.80, 0.20, 0.01);

  //byte tpsPosition = currentStatus.tpsADC;  //Range: autocalibrated min and max values

  //PID Input from TPS
   Input = map(currentStatus.tpsADC, configPage2.tpsMin, configPage2.tpsMax, 0, 255);

  byte Pedal0 = map(currentStatus.ppsADC, configPage13.pedalPositionMin, configPage13.pedalPositionMax, 0, 255);


  //PID Setpoint from Throttle Pedal
  Setpoint = Pedal0;
  //Set throttle to 0
  if (Setpoint <= 5)
  {
    analogWrite(pinThrottlePwm, 0);
  }
  else
  {
  tbPID.Compute();
    analogWrite(pinThrottlePwm, Output);
  }

}
*/
