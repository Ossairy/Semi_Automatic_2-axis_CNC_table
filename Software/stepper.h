

#ifndef STEPPER_H
#define STEPPER_H


class Stepper {
  public:
    Stepper(int stepsPerRevolution, int dirPin, int stepPin);
    void setup();
    void setDirection(bool dir);
    void step();
    void setSteps(int steps);
    void reset();


  private:
    int _stepsPerRevolution;
    int _dirPin;
    int _stepPin;
    int _currentPosition;
};


#endif
