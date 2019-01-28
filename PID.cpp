#include "main.h"

pros::Motor leftBDrive_mtr(11, HIGHSPEED, FWD, DEGREES);
pros::Motor rightBDrive_mtr(12, HIGHSPEED, REV, DEGREES);
pros::Motor leftFDrive_mtr(1, HIGHSPEED, FWD, DEGREES);
pros::Motor rightFDrive_mtr(2, HIGHSPEED, REV, DEGREES);
pros::Motor flyWheel(10, HIGHSPEED, FWD, DEGREES);

pros::Motor tipper(9, HIGHSPEED, FWD, DEGREES);
pros::Motor intake(3, HIGHSPEED, REV, DEGREES);
pros::Motor indexer(4, HIGHSPEED, REV, DEGREES);
pros::Vision vision_sensor (8);

PID::PID()
{

}

/*int PID::takeSnapshot()
{
  pros::vision_object_s_t obj = vision_sensor.get_by_sig(0, 1);

  int xPix[20];
  int sum = 0;
/*
  for(int i = 0; i < 20; i++)
  {
    int xPix[i] = {obj.x_middle_coord};
  }

  for(int i = 0; i < 20; i++)
  {
    sum += xPix[i];
  }


  return sum/20;
}*/

void PID::capTip()
{
  tipper.set_brake_mode(HOLD);

  tipper.move_relative(-450, -127);

  pros::delay(1000);
}

void PID::visionCorrect()
{
  int midX = 158;

  bool linedUp = true;

  int x;

  while(linedUp)
  {
    pros::vision_object_s_t obj = vision_sensor.get_by_sig(0, 1);
    x = obj.x_middle_coord;

    if(x < (midX - 5))
    {
      leftBDrive_mtr.move(-20);
      leftFDrive_mtr.move(-20);
      rightFDrive_mtr.move(20);
      rightBDrive_mtr.move(20);
    }
    else if(x > (midX + 5))
    {
      leftBDrive_mtr.move(20);
      leftFDrive_mtr.move(20);
      rightFDrive_mtr.move(-20);
      rightBDrive_mtr.move(-20);
    }
    else
    {
      linedUp = false;
      leftBDrive_mtr.move(0);
      leftFDrive_mtr.move(0);
      rightFDrive_mtr.move(0);
      rightBDrive_mtr.move(0);
    }

    pros::lcd::set_text(5, "The Current Number is: " + std::to_string(x));
  }
}

void PID::drive(int speed)
{
  leftFDrive_mtr.move(speed);
  leftBDrive_mtr.move(speed);
  rightBDrive_mtr.move(speed);
  rightFDrive_mtr.move(speed);
}

void PID::resetPos()
{
  leftBDrive_mtr.tare_position();
  rightBDrive_mtr.tare_position();
  rightFDrive_mtr.tare_position();
  leftFDrive_mtr.tare_position();
}

void PID::stop(int x)
{
  pros::delay(x);
}

void PID::resetSensor(int target)
{
  leftFDrive_mtr.set_zero_position(target);
  rightBDrive_mtr.set_zero_position(target);
  leftBDrive_mtr.set_zero_position(target);
  rightFDrive_mtr.set_zero_position(target);
}

void PID::driveBrakeHold()
{
  leftBDrive_mtr.set_brake_mode(HOLD);
  leftFDrive_mtr.set_brake_mode(BRAKE);
  rightFDrive_mtr.set_brake_mode(BRAKE);
  rightBDrive_mtr.set_brake_mode(HOLD);
}

void PID::driveHold()
{
  leftFDrive_mtr.set_brake_mode(HOLD);
  rightFDrive_mtr.set_brake_mode(HOLD);
}

void PID::resetBrake()
{
  leftBDrive_mtr.set_brake_mode(COAST);
  rightBDrive_mtr.set_brake_mode(COAST);
  leftFDrive_mtr.set_brake_mode(COAST);
  rightFDrive_mtr.set_brake_mode(COAST);

}

void PID::movePID(int power)
{
  double kp = 0.6485;

 int main = 0;
 int secondary = 0;
 int error = 1;
  int powerLeft, powerRight;

  int maxPower = power;
  int MIN_POWER = maxPower - 1;
  //int leftPos = (abs(lfdMotor.get_position()) + abs(lbdMotor.get_Position())/2;
 main = (abs(rightFDrive_mtr.get_position()) >= abs(leftFDrive_mtr.get_position())) ? abs(rightFDrive_mtr.get_position()) : abs(leftFDrive_mtr.get_position());
 secondary = (abs(rightFDrive_mtr.get_position()) >= abs(leftFDrive_mtr.get_position())) ? abs(leftFDrive_mtr.get_position()) : abs(rightFDrive_mtr.get_position());

 error = main - secondary;

 if(main > secondary)
 {
     power = power - error * kp;
 }

  if(power > 0)
  {
    if(power < MIN_POWER)
    {
      power = MIN_POWER;
    }
  }
  else if(power < 0)
  {
    if(power > -MIN_POWER)
    {
      power = -MIN_POWER;
    }
  }

  if(rightFDrive_mtr.get_position() > leftFDrive_mtr.get_position())
  {
    powerLeft = maxPower;
    powerRight = power;
  }
  else
  {
    powerLeft = power;
    powerRight = maxPower;
  }

  leftFDrive_mtr.move(powerLeft);
  rightFDrive_mtr.move(powerRight);
  leftBDrive_mtr.move(powerLeft);
  rightBDrive_mtr.move(powerRight);
}

void PID::turn(int degrees, int x)
{
  PID::resetPos();
  degrees*=3.119968;

  leftFDrive_mtr.move_relative(degrees, x);
  leftBDrive_mtr.move_relative(degrees, x);
  rightBDrive_mtr.move_relative(-degrees, -x);
  rightFDrive_mtr.move_relative(-degrees, -x);

  while (!((leftFDrive_mtr.get_position() < (degrees + 5)) && (leftFDrive_mtr.get_position() > (degrees - 5)))
         && !((rightFDrive_mtr.get_position() < (-degrees + 5)) && (rightFDrive_mtr.get_position() > (-degrees - 5))))
  {
   pros::delay(2);
  }
  PID::driveBrakeHold();
}

void PID::flyCoast()
{
  flyWheel.set_brake_mode(COAST);
}

void PID::move(double targetDistance, int maxPower, int flyWheelP, int indexerP, int intakeP, int tipperP)
{
  int currentDistance = 0;
  double error = 20;

  int targ = (targetDistance/12.566) * 360;

  int leftF, rightF;

  PID::resetPos();


 while(error != 0)
 {
    leftF = abs(leftFDrive_mtr.get_position());
    rightF = abs(rightFDrive_mtr.get_position());

    currentDistance = (leftF + rightF)/2;

    error = targ - currentDistance;

    intake.move(intakeP);
    indexer.move(indexerP);

    flyWheel.move(flyWheelP);

    tipper.move(tipperP);

    PID::movePID(maxPower);

    if(error < 15 && error > -15)
    {
      error = 0;
      drive(0);
      PID::driveBrakeHold();
      PID::flyCoast();
    }
  }

  intake.move(0);
}

void PID::miscell(int intakeP, int indexerP, int tipperP, int x)
{
  tipper.set_brake_mode(HOLD);
  intake.move(intakeP);
  indexer.move(indexerP);
  tipper.move(tipperP);

  pros::delay(x);
}

void PID::flywheelAccel(int x)
{
 int speed = 0;

 for(int i = 1; i <= x; i++)
 {
   speed++;
 }

 flyWheel.move(speed);
}
