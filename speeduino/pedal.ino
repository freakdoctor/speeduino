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
#include "auxiliaries.h"
#include "pedal.h"

long tbSetpoint, tbInput, tbOutput;
PID tbPID(&tbInput, &tbOutput, &tbSetpoint, 1, 0, 0, DIRECT);

byte tbSensorVal;
unsigned long tbCurrentTime = 0;
unsigned long tbPreviousTime = 0;

void tbCalibration()
{
    tbCurrentTime = millis();
    tbPreviousTime = tbCurrentTime;

      //Auto Calibration TPS
      while (tbCurrentTime - tbPreviousTime < 1000) {
        tbSensorVal = analogRead(pinTPS);
        // record the minimum sensor value
        configPage2.tpsMin = tbSensorVal;
      }
      while (tbCurrentTime - tbPreviousTime < 2500) {
        tbSensorVal = analogRead(pinTPS);
        analogWrite(pinTpsPwm, 255);
        // record the maximum sensor value
        configPage2.tpsMax = tbSensorVal;
      }
      if (tbCurrentTime - tbPreviousTime >  2500) {
        analogWrite(pinTpsPwm, 0);
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


void tbCompute()
{
  
  if (configPage13.pedalPositionEnable > 0)
  {
    tbPID.SetTunings(0.80, 0.20, 0.01);
    tbPID.SetMode(AUTOMATIC);

    analogRead(pinTPS);
    long tpsPosition = analogRead(pinTPS);  //Range: autocalibrated min and max values

    //PID Input from TPS
    tbInput = map(tpsPosition, configPage2.tpsMin, configPage2.tpsMax, 0, 100);
    //Input = currentStatus.pedalPosition;

    analogRead(pinPedalPosition);
    int Pedal0 = map(analogRead(pinPedalPosition), configPage13.pedalPositionMin, configPage13.pedalPositionMax, 0, 100);
    //byte Pedal0 = Input;


    //PID Setpoint from Throttle Pedal
    tbSetpoint = Pedal0;
    //Set throttle to 0
    if (tbSetpoint <= 5)
    {
      analogWrite(pinTpsPwm, 0);
    }
    else
    {
    tbPID.Compute();
      analogWrite(pinTpsPwm, tbOutput);
    }

  }
}
