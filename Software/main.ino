#include "Stepper.h"
#include "Arduino.h"



#define X_DIR_PIN     2
#define X_STEP_PIN    3
#define Y_DIR_PIN     4
#definet Y_STEP_PIN   5




#define X_STEPS_PER_MM   800 
#define Y_STEPS_PER_MM   800 



Stepper xStepper(X_STEPS_PER_MM * 1, X_DIR_PIN, X_STEP_PIN);
Stepper yStepper(Y_STEPS_PER_MM * 1, Y_DIR_PIN, Y_STEP_PIN);

void setup() {
  xStepper.setup();
  yStepper.setup();
}

void loop() {


  // get the user inputs for the desired coordinates
  float xCoord, yCoord;
  Serial.print("Enter X coordinate (mm): ");
  while (!Serial.available()) {}
  xCoord = Serial.parseFloat();
  Serial.println(xCoord);

  Serial.print("Enter Y coordinate (mm): ");
  while (!Serial.available()) {}
  yCoord = Serial.parseFloat();
  Serial.println(yCoord);

  // convert the desired coordinates into steps
  int xSteps = xCoord * X_STEPS_PER_MM;
  int ySteps = yCoord * Y_STEPS_PER_MM;

  // move the stepper motors to the desired coordinates

  xStepper.setSteps(xSteps);
  yStepper.setSteps(ySteps);




}