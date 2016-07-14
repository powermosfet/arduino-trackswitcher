#include <Arduino.h>
#include "motor.h"

Motor::Motor(MotorChannel channel, MotorDirection direction) {
  this->channel = channel;
  this->direction = direction;

  pinMode(this->runPin(),       OUTPUT);
  pinMode(this->directionPin(), OUTPUT);
  pinMode(this->brakePin(),    OUTPUT);
}

void Motor::update() {
  if(this->runSince && (millis() - this->runSince) > this->runForMs) {
    this->stop();
    this->runSince = 0;
    if(this->thenCallback) {
      this->thenCallback();
      this->thenCallback = NULL;
    }
  }
}

Motor *Motor::runFor(int runFor, byte speed) {
  this->runForMs = runFor;
  this->runSince = millis();
  this->start(speed);
  return this;
}

void Motor::start(byte speed) {
  digitalWrite(this->directionPin(), (this->direction == FORWARDS)? HIGH : LOW);
  digitalWrite(this->brakePin(), LOW);
  analogWrite(this->runPin(), speed);
}

void Motor::stop() {
  this->runSince = 0;
  analogWrite(this->runPin(), 0);
}

int Motor::runPin() {
  return (this->channel == A)? PIN_PWMA : PIN_PWMB;
}

int Motor::directionPin() {
  return (this->channel == A)? PIN_DIRA : PIN_DIRB;
}

int Motor::brakePin() {
  return (this->channel == A)? PIN_BRAKEA : PIN_BRAKEB;
}

void Motor::then(ThenCb callback) {
  this->thenCallback = callback;
}

void Motor::changeDirection() {
  this->direction = (this->direction == FORWARDS)? BACKWARDS : FORWARDS;
}
