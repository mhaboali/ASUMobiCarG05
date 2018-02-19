#define LED 1

void setup() {
pinMode (LED,OUTPUT); 

}

void loop() {
 digitalWrite(LED,HIGH);
 delay(500); //25% from 2sec duty cycle 
 digitalWrite(LED,LOW);
 delay(1500); 

}
