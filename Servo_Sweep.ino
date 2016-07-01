//Sweep
#include <Servo.h>

Servo SideToSideServo;  // create servo object to control a servo
Servo UpDownServo;
Servo InOutServo;
Servo ClawServo;

int pos = 0;    // variable to store the servo position

void setup() 
{
  Serial.begin(9600);
  SideToSideServo.attach(6); //attaches the servo on pin 6 to the servo object
  UpDownServo.attach(9);
  InOutServo.attach(10);
  ClawServo.attach(11);
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees in steps of 1 degree
    SideToSideServo.write(pos);              // tell servo to go to position in variable 'pos'
    ClawServo.write(pos);
    UpDownServo.write(pos);
    InOutServo.write(pos);
    Serial.print(pos);
    Serial.print(" ");
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees in steps of 1 degree
    SideToSideServo.write(pos);              // tell servo to go to position in variable 'pos'
    ClawServo.write(pos);
    UpDownServo.write(pos);
    InOutServo.write(pos);
    Serial.print(pos);
    Serial.print(" ");
    delay(15);                       // waits 15ms for the servo to reach the position    
  }

}
