int trigpin=13;
int echopin=12;
int buzzpin=10;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(buzzpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  double distance, duration;
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  duration=pulseIn(echopin,HIGH);
  distance=(duration*0.033)/2;
  if(distance<=8.0)
    { digitalWrite(buzzpin,HIGH);
     delay(100);}
  else
     digitalWrite(buzzpin,LOW);
  Serial.print((distance));
  Serial.println(" cm");
  delay(500);
}
