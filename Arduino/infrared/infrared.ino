int led=13;
int obstaclePin=7;
int hasObstacles=HIGH;

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(obstaclePin,INPUT);
  Serial.begin(9600);
}
void loop()
{
  hasObstacles=digitalRead(obstaclePin);
  if(hasObstacles==LOW)
  {
    Serial.println("Something is ahead");
    digitalWrite(led,HIGH);
  }
  else
  {
  Serial.println("Path is clear");
  digitalWrite(led,LOW);
}
}

