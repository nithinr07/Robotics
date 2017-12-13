int buzzpin=10;
void setup() {
  // put your setup code here, to run once:
  pinMode(buzzpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=255;i>=0;i-=50)
  {
    analogWrite(buzzpin,i);
    delay(100);
  }
}
