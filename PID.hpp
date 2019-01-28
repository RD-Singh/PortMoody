#ifndef _PID_HPP_
#define _PID_HPP_

#include "main.h"

class PID
{
  public:

    explicit PID();
    void stop(int x);
    void drive(int speed);
    void resetPos();
    void turn(int degrees, int x);
    void resetSensor(int target);
    void driveBrakeHold();
    void driveHold();
    void resetBrake();
    void movePID(int power);
    void flyCoast();
    void visionCorrect();
    void capTip();
    void move(double targetDistance, int maxPower, int flyWheelP, int indexerP, int intakeP, int tipperP);
    void miscell(int intakeP, int indexerP, int tipperP, int x);
    void flywheelAccel(int x);
};

#endif
