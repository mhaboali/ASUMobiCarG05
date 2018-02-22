const int LED =13;
const int b=2;
int val ;
void setup() {

  pinMode(LED,OUTPUT);
pinMode(b,INPUT)
;}

void loop() {
  val=digitalRead(b);

  if(val==HIGH){
    
    
  digitalWrite(LED,HIGH);
  delay(1000);

    digitalWrite(LED,LOW);
  delay(1000);
  }
  else{
digitalWrite(LED,LOW);}
    
    }

