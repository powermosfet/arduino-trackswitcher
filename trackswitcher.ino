/*
  Track switcher
 */

#include "motor.h"
#include "pin.h"

const int PIN_OBSTACLE_SENSOR = 6;
const int RUN_TIME            = 1000;
const int MOTOR_SPEED         = 255;

ts::Motor switcherMotor(ts::A, ts::FORWARDS);
ts::Pin irSensor(PIN_OBSTACLE_SENSOR);

void setup() {
  irSensor.onEdge(ts::FALL, [](){
    switcherMotor.runFor(RUN_TIME, MOTOR_SPEED).then([](){
      switcherMotor.changeDirection();
    });
  });
}

void loop() {
  irSensor.update();
  switcherMotor.update();

  delay(100);
}
