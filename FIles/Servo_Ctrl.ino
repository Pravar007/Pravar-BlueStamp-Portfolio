#include <Servo.h>
#define servoPin 9  //servo Pin

Servo bottomServo;  //bottom servo Pin


void setup() {
  bottomServo.attach(7);          //Servo pin definition
  bottomServo.write(90); //set the angle of servo to 0°
  delay(1000);
}
void loop() {
  int bR = bottomServo.read();

  for(bR >= 0; bR -= 1;){
    bottomServo.write(bR);
    delay(30);
  }
  // for(bR >= 0; bR -= 1;){
  //   bottomServo.write(bR);
  //   delay(15);
  // }
}