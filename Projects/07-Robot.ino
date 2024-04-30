#include <AFMotor.h>
const int motorSpeed = 200;
AF_DCMotor motorG(1); 
AF_DCMotor motorM(2);

void setup() {
  motorG.setSpeed(motorSpeed);
  motorM.setSpeed(motorSpeed);
  motorG.run(RELEASE);
  motorM.run(RELEASE);
}

void loop() {
  motorG.run(FORWARD);
  motorM.run(FORWARD);
  delay(5000);

  motorG.run(BACKWARD);
  motorM.run(BACKWARD);
  delay(5000);

  motorG.run(FORWARD);
  motorM.run(RELEASE);
  delay(500);

  motorG.run(RELEASE);
  motorM.run(FORWARD);
  delay(500);

  motorG.run(RELEASE);
  motorM.run(RELEASE);
  delay(500);
}
