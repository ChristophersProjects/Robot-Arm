//Bluetooth Control
#include <Servo.h>

char BlueToothValue;

Servo SideToSideServo, UpDownServo, InOutServo, ClawServo; //creates servo object

int SideToSideAngle = 90; //intalize variable for servo position
int UpDownAngle = 90; 
int InOutAngle = 90;
int ClawAngle = 90;

int Change = 2;

void setup()
{
  Serial.begin(9600);
  //pins where servos are attached
  SideToSideServo.attach(6); //attaches the servo on pin 3 to the servo object
  UpDownServo.attach(9);
  InOutServo.attach(10);
  ClawServo.attach(11); 
}

void loop()
{
  while(Serial.available())
    {//if there is data being recieved
      BlueToothValue=Serial.read(); //read it
      if (BlueToothValue == '#')
      {
      break;
    }
    }
    
    
    //Side To Side Servo
    if (BlueToothValue=='R')
    {//if value from bluetooth serial is R
      SideToSideAngle = SideToSideAngle - Change; //Turn the arm to the right
      SideToSideAngle = constrain(SideToSideAngle, 0, 180);
      SideToSideServo.write(SideToSideAngle); //write the Side to Side Angle to the servo
      delay(20);
    }
    
    if (BlueToothValue=='L')
    {//if value from bluetooth serial is L
      SideToSideAngle = SideToSideAngle + Change; //Turn the arm to the left
      SideToSideAngle = constrain(SideToSideAngle, 0, 180);
      SideToSideServo.write(SideToSideAngle); //write the Side to Side Angle to the servo
      delay(20);
  }
   
  //UP DOWN Servo
    if (BlueToothValue=='U')
    {//if value from bluetooth serial is U
      UpDownAngle = UpDownAngle + Change; //Move the arm UP
      UpDownAngle = constrain(UpDownAngle, 0, 180);
      UpDownServo.write(UpDownAngle); //write the UP DOWN Angle to the servo
      delay(20);
    }
    
    if (BlueToothValue=='D')
    {//if value from bluetooth serial is D
      UpDownAngle = UpDownAngle - Change; //Move the arm DOWN
      UpDownAngle = constrain(UpDownAngle, 0, 180);
      UpDownServo.write(UpDownAngle); //write the UP DOWN Angle to the servo
      delay(20);
  }
  
  //CLAW Servo
    if (BlueToothValue=='O')
    {//if value from bluetooth serial is O
      ClawAngle = ClawAngle + Change; //OPEN the CLAW
      ClawAngle = constrain(ClawAngle, 0, 180);
      ClawServo.write(ClawAngle); //write the CLAW Angle to the servo
      delay(20);
    }
    
    if (BlueToothValue=='C')
    {//if value from bluetooth serial is C
      ClawAngle = ClawAngle - Change; //CLOSE the Claw
      ClawAngle = constrain(ClawAngle, 0, 180);
      ClawServo.write(ClawAngle); //write the CLAW Angle to the servo
      delay(20);
  }
  
  //In Out Servo
    if (BlueToothValue=='F')
    {//if value from bluetooth serial is F
      InOutAngle = InOutAngle + Change; //Move the arm OUT
      InOutAngle = constrain(InOutAngle, 0, 180);
      InOutServo.write(InOutAngle); //write the InOut Angle to the servo
      delay(20);
    }
    
    if (BlueToothValue=='B')
    {//if value from bluetooth serial is B
      InOutAngle = InOutAngle - Change; //Move the arm IN
      InOutAngle = constrain(InOutAngle, 0, 180);
      InOutServo.write(InOutAngle); //write the InOut Angle to the servo
      delay(20);
  }
        
  
  //Serial.print(InOutangle); //used to find limits
}


