#include<Servo.h>
int LeftMotorForward = 5; // Pin 10 has Left Motor connected on Arduino boards.
int LeftMotorReverse = 10;

int RightMotorForward = 3; // Pin 12 has Right Motor connected on Arduino boards.
int RightMotorReverse = 1; // Pin 13 has Right Motor connected on Arduino boards.
int trigpin=8;
int echopin=7;
int buzzpin=4;
Servo servo;
void setup()
{
  Serial.begin(9600);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(buzzpin,OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);  // initialize the  pin as an output.
  pinMode(RightMotorForward, OUTPUT);  // initialize the  pin as an output.
  pinMode(LeftMotorReverse, OUTPUT);  // initialize the  pin as an output.
  pinMode(RightMotorReverse, OUTPUT); 
  pinMode(12,OUTPUT);
  servo.attach(13);


}
void forward()
{
  analogWrite(RightMotorForward, 150);   // turn the Right Motor OFF
  digitalWrite(RightMotorReverse,LOW);
  digitalWrite(LeftMotorReverse,LOW);
  analogWrite(LeftMotorForward, 150);
}
void backward()
{
  digitalWrite(RightMotorForward, LOW);   // turn the Right Motor OFF
  digitalWrite(RightMotorReverse,HIGH);
  digitalWrite(LeftMotorReverse,HIGH);
  digitalWrite(LeftMotorForward, LOW);
}
void left()
{
  analogWrite(RightMotorForward, 150);   // turn the Right Motor OFF
  digitalWrite(RightMotorReverse,LOW);
  digitalWrite(LeftMotorReverse,LOW);
  digitalWrite(LeftMotorForward, LOW);
}
void right()
{
  digitalWrite(RightMotorForward, LOW);   // turn the Right Motor OFF
  digitalWrite(RightMotorReverse,LOW);
  digitalWrite(LeftMotorReverse,LOW);
  analogWrite(LeftMotorForward, 150);
}
void stop()
{
  digitalWrite(RightMotorForward, LOW);   // turn the Right Motor OFF
  digitalWrite(RightMotorReverse,LOW);
  digitalWrite(LeftMotorReverse,LOW);
  digitalWrite(LeftMotorForward, LOW);
}
void right_look()
{
  servo.write(0);
  delay(100);
}
void left_look()
{
  servo.write(180);
  delay(100);
}
void front_look()
{
  servo.write(90);
  delay(100);
}
double dist()
{
 double distance, duration;
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH); // Pin 9 has Left Motor connected on Arduino boards.

 delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  duration=pulseIn(echopin,HIGH);
  distance=(duration*0.033)/2; 
  return distance;
}
// The following Loop is to make the Robot go Right
void loop()
{
  digitalWrite(12,HIGH);
  front_look();
  double dis;
  forward();
  dis=dist();
 Serial.println(dis);
  if(dis<=35.0)
  {
   stop();
   int angle = 90;   
   dis=dist();
   int timer=0;
   while(dis<=35.0)
    {
      
   delay(500);
   
   digitalWrite(buzzpin,HIGH);
   delay(500);
   
   digitalWrite(buzzpin,LOW);
      angle -= 15;
      servo.write(angle);
      dis=dist();
      if(angle==0)
      {
        angle=180;
        servo.write(angle);
      }
    }
  if(angle<90)
  {
    
     right();
     
  }   
  else if(angle>90)
  {
    left();
    
  }
  delay(150);
  }
}
