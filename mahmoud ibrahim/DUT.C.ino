int H=9;
void setup() {
  pinMode(H,OUTPUT);
  // put your setup code here, to run once:
}
void loop()
{
   digitalWrite(H,HIGH); 
   delay(500);  //to make duty.C=25%
     digitalWrite(H,LOW); 
      delay(1500);
}
  



