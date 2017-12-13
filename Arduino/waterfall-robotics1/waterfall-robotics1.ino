int arr[8];
void a()
{
  for(int i=0;i<8;i++)
  {
     arr[i]=i+1;
  }
}
void setup() 
{
 for(int i=0;i<8;i++)
{
  pinMode(arr[i], OUTPUT);

}
}
void loop()
{
  a();
  setup();
  for(int i=0;i<8;i++)
  {
  digitalWrite(arr[i], HIGH);   
  delay(100);                  
  digitalWrite(arr[i], LOW);    
  delay(50);
  }
  for(int i=6;i>=1;i--)
  {
  digitalWrite(arr[i], HIGH);   
  delay(100);                  
  digitalWrite(arr[i], LOW);    
  delay(50);
  }               
}

