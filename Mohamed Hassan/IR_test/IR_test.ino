//Setup Bluetooth Module
#include <Servo.h> 
Servo Control_Servo;
char data;

void setup() {
  // put your setup code here, to run once:
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(A4,OUTPUT);
  pinMode(A5,OUTPUT);
Serial.begin(9600);
  Control_Servo.attach (9); 

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    data=Serial.read();
    Serial.println(data);
    if(data=='B')
    {
      Serial.println("A7aaaaaa");
      analogWrite(11,255);
      analogWrite(10,195);
      digitalWrite(A4,LOW);
      digitalWrite(A5,HIGH);
      Control_Servo.write(90);
    }
    if(data=='F')
    {
      Serial.println("A7aaaaaa");
      analogWrite(11,255);
      analogWrite(10,195);
      digitalWrite(A4,HIGH);
      digitalWrite(A5,LOW);
          Control_Servo.write(90);

    }
     if(data=='L')
    {
      Control_Servo.write(125);
      //delay(3000);
      analogWrite(11,255);
      analogWrite(10,235);
      digitalWrite(A4,HIGH);
      digitalWrite(A5,LOW);
        

    }
    if(data=='S'){
      
      Control_Servo.write(90);
      //delay(3000);
      analogWrite(11,0);
      analogWrite(10,0);
      digitalWrite(A4,HIGH);
      digitalWrite(A5,HIGH);
      
      
      
      }
    if(data=='R')
    {
      Control_Servo.write(55);
      //delay(3000);
      analogWrite(11,255);
      analogWrite(10,235);
      digitalWrite(A4,HIGH);
      digitalWrite(A5,LOW);
      
    }  
  }


}

