
#include "Stepper.h"
#include "Arduino.h"

Stepper::Stepper(int stepsPerRevolution, int dirPin, int stepPin) {
  _stepsPerRevolution = stepsPerRevolution;
  _dirPin = dirPin;
  _stepPin = stepPin;
}

void Stepper::setup() {
  pinMode(_dirPin, OUTPUT);
  pinMode(_stepPin, OUTPUT);
}

void Stepper::setDirection(bool dir) {
  digitalWrite(_dirPin, dir);
}

void Stepper::step() {
  digitalWrite(_stepPin, HIGH);
  delayMicroseconds(500);
  digitalWrite(_stepPin, LOW);
  delayMicroseconds(500);
  _currentPosition++;
}

void Stepper::setSteps(int steps) {
  int stepsToMove = steps - _currentPosition;
  bool dir = (stepsToMove > 0) ? HIGH : LOW;
  setDirection(dir);
  stepsToMove = abs(stepsToMove);
  for (int i = 0; i < stepsToMove; i++) {
    step();
  }
}

void Stepper::reset() {
  _currentPosition = 0;
}
