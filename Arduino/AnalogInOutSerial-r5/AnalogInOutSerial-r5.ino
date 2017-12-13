int analogInPin = A0;  
int analogOutPin=9;
int sensorValue = 0;        
int outputValue = 0;        

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(analogInPin);
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  if(outputValue>150)
     analogWrite(analogOutPin, outputValue);
  else
     {
     outputValue=0;
     analogWrite(analogOutPin, outputValue);
     }
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);
}
