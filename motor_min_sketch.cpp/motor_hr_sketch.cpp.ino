String command;

#include "ContinuousStepper.h"

// #define pwmA 3
// #define pwmB 11
// #define brakeA 9
// #define brakeB 8
// #define dirA 12
// #define dirB 13
//determine necessary FOUR pins for thingydo

ContinuousStepper<FourWireStepper> stepper;

int beginningRPM = 0.0625;

int delayCkr(int fullRevSec){
  return (fullRevSec*beginningRPM)
}

void setup() {
  Serial.begin(9600);

  stepper.begin(3, 11, 12, 13);

  // // Set the PWM and brake pins so that the direction pins can be used to control the motor:
  // pinMode(pwmA, OUTPUT);
  // pinMode(pwmB, OUTPUT);
  // pinMode(brakeA, OUTPUT);
  // pinMode(brakeB, OUTPUT);

  // digitalWrite(pwmA, HIGH);
  // digitalWrite(pwmB, HIGH);
  // digitalWrite(brakeA, LOW);
  // digitalWrite(brakeB, LOW);

  // // Set the motor speed (RPMs):
  // myStepper.setSpeed(200);
}

void loop() {
  
  if (Serial.available()) {
    command = Serial.readStringUntil('\n');
    command.trim();
    if (command.equals("scene change")) {
      stepper.spin(37.5);
    }
    else if (command.equals("standard rotation")) {
      stepper.spin(delayCkr(1));
    }
    else {
      stepper.spin(0);
    }

  }
  stepper.loop();
}