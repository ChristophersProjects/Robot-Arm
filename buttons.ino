//Buttons
#include <Servo.h>

Servo SideToSideServo;  // create servo object
Servo UpDownServo;
Servo InOutServo;
Servo ClawServo;

int RIGHT = 8;  //pin for right switch
int LEFT = 7;  //pin for left switch

int UP = 12; //pin for up switch
int DOWN = 13; //pin for down switch

int OUT = 3; //pin for outward switch
int IN = 2; //pin for inwards switch

int OPEN = 4; //pin for opening claw
int CLOSE = 5; //pin for closing claw



int StoSangle = 90; //intalize variable for servo position
int UpDownangle = 90; 
int InOutangle = 90;
int clawangle = 90;

int change = 2;

void setup()
{
  Serial.begin(9600);
  //pins where servos are attached
  SideToSideServo.attach(6); //attaches the servo on pin 6 to the servo object
  UpDownServo.attach(9);
  InOutServo.attach(10);
  ClawServo.attach(11);
  
  //Button Setup
  
  //right left buttons
  pinMode(RIGHT, INPUT); //initalize input pins
  pinMode(LEFT, INPUT);
  
  digitalWrite(RIGHT, HIGH); //sets internal pull up resistor
  digitalWrite(LEFT, HIGH);
  
  //up down buttons
  pinMode(UP, INPUT); //initalize input pins
  pinMode(DOWN, INPUT);
  
  digitalWrite(UP, HIGH); //sets internal pull up resistor
  digitalWrite(DOWN, HIGH);
  
  //in out buttons
  pinMode(IN, INPUT); //initalize input pins
  pinMode(OUT, INPUT);
  
  digitalWrite(IN, HIGH); //sets internal pull up resistor
  digitalWrite(OUT, HIGH);
  
  //claw buttons
  pinMode(OPEN, INPUT); //initalize input pins
  pinMode(CLOSE, INPUT);
  
  digitalWrite(OPEN, HIGH); //sets internal pull up resistor
  digitalWrite(CLOSE, HIGH);
}

void loop()
{
  //side to side loop
  if( digitalRead(RIGHT) == LOW)
  {
    StoSangle = StoSangle - change;
  }
  if( digitalRead(LEFT) == LOW)
  {
    StoSangle = StoSangle + change;
  }
  
  StoSangle = constrain(StoSangle, 0, 180);
  SideToSideServo.write(StoSangle); //write the side to side angle to the servo
  delay(20);
  
  //up down loop
  if( digitalRead(UP) == LOW)
  {
    UpDownangle = UpDownangle + change;
  }
  if( digitalRead(DOWN) == LOW)
  {
    UpDownangle = UpDownangle - change;
  }
  
  UpDownangle = constrain(UpDownangle, 40, 180);
  UpDownServo.write(UpDownangle); //write the up or down angle to the servo
  delay(20);
  
  //in out loop
  if( digitalRead(IN) == LOW)
  {
    InOutangle = InOutangle - change;
  }
  if( digitalRead(OUT) == LOW)
  {
    InOutangle = InOutangle + change;
  }
  
  InOutangle = constrain(InOutangle, 65, 180);
  InOutServo.write(InOutangle); //write the in or out angle to the servo
  delay(20);
  
  //claw loop
  if( digitalRead(OPEN) == LOW)
  {
    clawangle = clawangle - change;
  }
  if( digitalRead(CLOSE) == LOW)
  {
    clawangle = clawangle + change;
  }
  
  clawangle = constrain(clawangle, 50, 176);
  ClawServo.write(clawangle); //write the claw angle to the servo
  delay(20);
  
  
  Serial.print(StoSangle); //used to find limits
  Serial.print(" ");
}


