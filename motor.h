#ifndef MOTOR_H
#define MOTOR_H

const int PIN_PWMA = 3;
const int PIN_PWMB = 11;
const int PIN_BRAKEA = 9;
const int PIN_BRAKEB = 8;
const int PIN_DIRA = 12;
const int PIN_DIRB = 13;

typedef void (*then_cb_t)();

enum MotorChannel { A, B };
enum MotorDirection { FORWARDS, BACKWARDS };

class Motor {
    MotorChannel channel;
    MotorDirection direction;
    unsigned long runSince;
    int runForMs;
    then_cb_t thenCallback;

    int runPin();
    int directionPin();
    int brakePin();
    
  public:
    Motor(MotorChannel, MotorDirection);
    Motor *runFor(int, byte);
    void start(byte);
    void stop();
    void update();
    void then(then_cb_t);
    void changeDirection();
};

#endif
