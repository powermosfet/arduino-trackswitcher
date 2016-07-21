#ifndef PIN_H
#define PIN_H

namespace ts {
  typedef void (*PinCb)();

  class Pin {
      int pinN;
      PinCb callback;
      int edge;
      bool oldValue;
    public:
      Pin(int);
      void onEdge(int, PinCb);
      void update();
  };
}

#endif
