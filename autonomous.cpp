#include "main.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

 int auton = 0;

 PID * pid = new PID();
 static Vision * vision = new Vision();

 void skillsAuton()
 {
   //pid->move(distance, power, flywheel, indexer, intake, tipper);
   //pid->miscell(tipper, intake, indexer, time);

     pid->flyCoast();

     //gets back cap

     pid->flywheelAccel(127);

     pid->capTip();

     //get angled cap
     pid->move(40, 87, 127, 0, 0, 0);

     pid->miscell(127, 0, 0, 500);

     pid->move(40, -87, 127, 0, 0, 0);

     //resets
     pid->drive(-57);

     pid->stop(600);

     //moves a bit forward
     pid->move(5.75, 87, 127, 0, 0, 0);

     pid->stop(150);

     //turns towards flags
     pid->turn(-90, -90);

     pid->stop(150);

     //moves forawrd a bit and toggles top high flag
     pid->move(4, 67, 127, 0, 0, 0);

     pid->stop(250);

     pid->miscell(0, 127, 0, 600);

     //moves forward and toggles the middle high flag
     pid->move(22, 67, 127, 0, 0, -25);

     pid->stop(150);

     pid->miscell(127, 127, 0, 1000);

     //toggles low flag
     pid->move(7, 67, 127, 0, 0, 0);

     //moves back and turns towards the front cap
     pid->move(31, -87, 127, 0, 0, 0);

     pid->stop(300);

     pid->turn(90, 90);

     pid->stop(200);

     pid->drive(-57);

     pid->stop(500);

     pid->move(7, 67, 127, 0, 0, 0);

     pid->stop(200);

     pid->turn(-45, -90);

     pid->stop(300);

     pid->move(10, 77, 127, 0, 0, 0);

     pid->miscell(100, 0, -60, 800);

     pid->miscell(120, 0, -5, 1200);

     pid->move(3, -87, 127, 0, 0, 0);

     pid->stop(200);

     pid->move(5, 87, 127, 0, 50, 0);

     pid->move(5, 87, 127, 0, 40, 127);

     pid->stop(150);

     pid->turn(51, 90);

     pid->stop(200);

     pid->move(32, 87, 127, 0, 0, 0);

     pid->stop(150);

     pid->turn(-90, -90);

     pid->stop(200);

     pid->move(8, -87, 127, 0, 40, 0);

     pid->stop(200);

     //vision->visionCorrect();

     pid->miscell(70, 127, 0, 650);

     pid->move(16, 87, 127, 0, 0, 20);

     pid->stop(200);

     //vision->visionCorrect();

     pid->miscell(127, 127, 0, 1000);

     pid->turn(-5, -90);

     pid->stop(150);

     pid->move(16, 87, 127, 0, 0, 0);

     pid->drive(57);

     pid->stop(850);

     pid->move(20, -87, 127, 0, 0, 0);

     pid->stop(200);

     pid->turn(90, 90);

     pid->stop(150);

     pid->move(11, 87, 127, 0, 0, 0);

     pid->stop(150);

     pid->turn(45, 90);

     pid->stop(150);

     pid->move(18, 87, 127, 0, 0, 20);

     pid->stop(150);

     pid->turn(-135, -90);

     pid->stop(150);

     pid->drive(-67);

     pid->stop(700);

     pid->capTip();

     pid->move(40, 87, 127, 0, 0, 0);

     pid->stop(550);

     pid->move(40, -87, 127, 0, 0, 0);

     pid->drive(-57);

     pid->stop(500);

     pid->move(6, 87, 127, 0, 0, 0);

     pid->stop(150);

     pid->turn(45, 90);

     pid->stop(300);

     pid->move(10, 77, 127, 0, 0, 0);

     pid->miscell(100, 0, -60, 800);

     pid->miscell(120, 0, -5, 1200);

     pid->move(3, -87, 127, 0, 0, 0);

     pid->stop(200);

     pid->move(5, 87, 127, 0, 50, 0);

     pid->move(5, 80, 127, 0, 40, 97);

     pid->stop(150);

     pid->turn(45, 90);

     pid->stop(150);

     pid->move(20, -87, 127, 0, 60, 0);

     pid->miscell(80, 127, -15, 800);

     pid->move(12, 87, 127, 0, 0, 0);

     pid->miscell(127, 127, -30, 600);

     pid->move(7, 67, 127, 0, 0, 0);
 }

 void blueAuton()
 {
   pid->flyCoast();

   //gets back cap

   pid->flywheelAccel(127);

   //get angled cap
   pid->move(40, 87, 127, 0, 0, 0);

   pid->miscell(127, 0, 0, 500);

   pid->move(40, -87, 127, 0, 0, 0);

   //resets
   pid->drive(-57);

   pid->stop(600);

   //moves a bit forward
   pid->move(5.75, 87, 127, 0, 0, 0);

   pid->stop(150);

   //turns towards flags
   pid->turn(90, 90);

   pid->stop(150);

   //moves forawrd a bit and toggles top high flag
   pid->move(4, 67, 127, 0, 0, 0);

   pid->stop(250);

   pid->miscell(0, 127, 0, 600);

   //moves forward and toggles the middle high flag
   pid->move(22, 67, 127, 0, 0, -20);

   pid->stop(150);

   pid->miscell(127, 127, 0, 1000);

   //toggles low flag
   pid->move(7, 67, 127, 0, 0, 0);

   //moves back and turns towards the front cap
   pid->move(31, -87, 127, 0, 0, 0);

   pid->stop(300);

   pid->turn(-90, -90);

   pid->stop(200);

   pid->drive(-57);

   pid->stop(500);

   pid->move(7, 67, 127, 0, 0, 0);

   pid->stop(200);

   pid->turn(45, 90);

   pid->stop(300);

   pid->move(10, 77, 127, 0, 0, 0);

   pid->miscell(100, 0, -60, 800);

   pid->miscell(120, 0, -5, 1200);

   pid->move(3, -87, 127, 0, 0, 0);

   pid->stop(200);

   pid->move(5, 87, 127, 0, 50, 0);

   pid->move(5, 77, 127, 0, 40, 100);

   pid->stop(150);

   pid->miscell(70, 127, 0, 450);

   pid->move(16, 87, 91, 0, 0, 20);

   pid->stop(200);

   pid->miscell(127, 127, 0, 1000);

   pid->move(9, -87, 0, 0, 0, 0);
 }
/*
 void redAuton()
 {
   pid->flywheelAccel(127);
  //Moves forward
  pid->move(40, 87, 127, 0, 0);

  pid->miscell(60, 0, 600);
  //moves back

  pid->drive(-87);

  pid->stop(1000);

  pid->drive(-67);

  pid->stop(1000);

  //moves a bit forward
  pid->move(6, 67, 127, 0, 30);

  pid->stop(200);
  //turns
  pid->turn(-85, -90);

  pid->move(5, 67, 127, 0, 0);

  pid->miscell(0, 80, 1000);

  //moves forward to the low flag
  pid->move(20, 93, 127, 0, 0);

  pid->miscell(90, 90, 1400);

  pid->turn(-10, -67);

  //toggles low flag
  pid->move(14, 87, 90, 0, 0);

  pid->stop(150);

  //moves back towards cap
  pid->move(5, -77, 70, 0, 0);

  pid->stop(250);

  pid->turn(10, 67);

  pid->stop(250);

  pid->move(4, -90, 60, 0, 0);

  //turns towwards cap
  pid->turn(90, 90);

  pid->stop(250);

  //resets
  pid->drive(-67);

  pid->stop(600);

  //flips cap
  pid->move(23, 80, 40, 0, -55);

  pid->stop(250);

  pid->move(10, -87, 30, 0, 0);
}
*/



void autonomous()
{
  /*if(auton == 0)
  {
    blueAuton();
  }
  else if(auton == 1)
  {
    redAuton();
  }
  else if(auton == 2)
  {
    skillsAuton();
  }*/
  //blueAuton();
  skillsAuton();
  //redAuton();
//
 /*id->move(30, 85, 0, 0, 0, 0);
  pid->stop(1000);
  pid->move(30, -85, 0, 0, 0, 0);*/
   //pid->turn(90, 90);
}
