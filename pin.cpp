#include <Arduino.h>
#include "pin.h"

Pin::Pin(int pinN) {
  this->pinN = pinN;
}

void Pin::onEdge(Edge edge, PinCb callback) {
  this->edge = edge;
  this->callback = callback;
}

void Pin::update() {
  bool newValue = digitalRead(this->pinN);
  if(newValue != this->oldValue) {
    if((this->edge == RISING_EDGE  &&  newValue) ||
       (this->edge == FALLING_EDGE && !newValue)) {
        
      if(this->callback) {
        this->callback();
      }
    }
    this->oldValue = newValue;
  }
}

