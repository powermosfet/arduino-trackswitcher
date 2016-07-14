#ifndef PIN_H
#define PIN_H

typedef void (*PinCb)();

enum Edge { RISING_EDGE, FALLING_EDGE };

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

#endif
