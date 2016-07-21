#include <Arduino.h>
#include "pin.h"

namespace ts {
  Pin::Pin(int pinN) {
    this->pinN = pinN;
  }

  void Pin::onEdge(int edge, PinCb callback) {
    this->edge = edge;
    this->callback = callback;
  }

  void Pin::update() {
    bool newValue = digitalRead(this->pinN);
    if(newValue != this->oldValue) {
      if((this->edge == RISING  &&  newValue) ||
          (this->edge == FALLING && !newValue)) {

        if(this->callback) {
          this->callback();
        }
      }
      this->oldValue = newValue;
    }
  }
}
