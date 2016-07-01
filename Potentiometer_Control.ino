//Potentiometer Control
#include <Servo.h>


Servo SideToSideServo;  // create servo object
Servo UpDownServo;
Servo InOutServo;
Servo ClawServo;


int potpin0 = 0;  // analog pin used to connect the Side to Side potentiometer
int potpin1 = 1;  // analog pin used to connect the In / Out potentiometer
int potpin2 = 2;  // analog pin used to connect the Up / Down potentiometer
int potpin3 = 3;  // analog pin used to connect the Claw potentiometer

int val0;    // variable to read the value from the analog pin
int val1;    
int val2;    
int val3;    

void setup() {
  Serial.begin(9600);
  //pins where servos are attached
  SideToSideServo.attach(6); //attaches the servo on pin 6 to the servo object
  UpDownServo.attach(9);
  InOutServo.attach(10);
  ClawServo.attach(11);
}

void loop() {
  val0 = analogRead(potpin0);            // reads the value of the potentiometer (value between 0 and 1023)
  val0 = map(val0, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  SideToSideServo.write(val0);           // sets the servo position according to the scaled value
  Serial.println(val0);
  delay(15);                             
  
  val1 = analogRead(potpin1);            
  val1 = map(val1, 0, 1023, 0, 180);     
  InOutServo.write(val1);                  
  //Serial.println(val1);
  delay(15);  
  
  val2 = analogRead(potpin2);            
  val2 = map(val2, 0, 1023, 0, 180);    
  UpDownServo.write(val2);                 
  //Serial.println(val2);
  delay(15); 

  val3 = analogRead(potpin3);            
  val3 = map(val3, 0, 1023, 0, 180);    
  ClawServo.write(val3);                  
  //Serial.println(val3);
  delay(15); 
}
