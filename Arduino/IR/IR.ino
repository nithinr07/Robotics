int led1=11;
void setup() {
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  digitalWrite(A2,HIGH);
  digitalWrite(A1,LOW);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(A0));
  delay(1000);
  if(analogRead(A0)<500)
  analogWrite(led1,A0);
  else
  analogWrite(led1,0);
}
