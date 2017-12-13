t arr[4];int led1=9;
void a()
{
  for(int i=0;i<4;i++)
  {
     arr[i]=i+1;
  }
}
void setup() {
  // put your setup code here, to run once:
for(int i=0;i<4;i++)
{
  pinMode(arr[i], OUTPUT);
}
pinMode(led1,OUTPUT);
}
void loop()
{
  a();
  setup();
  for(int i=1;i<=15;i++)
  {
    int binary[4];int num=i;int c=0;
    while(num>0)
    {
      int d=num%2;
        binary[c]=d;
      c++;
      num=num/2;
    }
    for(int j=0;j<4;j++)
    {
      if(binary[j]==0)
         digitalWrite(arr[j], LOW);
      else
         digitalWrite(arr[j], HIGH);  
    }
    
    int brightness=i*17;
    analogWrite(led1,brightness);
    delay(2000);
  }
}

