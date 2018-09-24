int outled=12;
int in=4;
int val=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(outled,OUTPUT);
  pinMode(in,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val=digitalRead(in);
  digitalWrite(outled,val);
}
