#ifndef PIN_H
#define PIN_H

namespace ts {
  typedef void (*PinCb)();

  enum Edge { RISE, FALL };

  class Pin {
    int pinN;
    PinCb callback;
    Edge edge;
    bool oldValue;
    public:
    Pin(int);
    void onEdge(Edge, PinCb);
    void update();
  };
}

#endif
