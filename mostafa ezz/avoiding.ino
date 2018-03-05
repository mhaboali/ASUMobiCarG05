//Initialization of Variables
#include <SoftwareSerial.h>
SoftwareSerial HC05(0,1); // CONNECT 12 WITH TX & 11 WITH RX
#include <Servo.h>
Servo Control_Servo;
int right_motor_in=7;
int left_motor_in=6;
int right_motor_PWM=9;
int left_motor_PWM=10;
int trig_pin_front =2;
int echo_pin_front =3;
int trig_pin_rear =4;
int echo_pin_rear =5;
int Servo_Pos=13;
int Speed ;
char Data;
String Signal;

void setup() 
{
  pinMode (right_motor_in,OUTPUT);       
  pinMode (left_motor_in,OUTPUT);      
  pinMode (right_motor_PWM,OUTPUT);           
  pinMode (left_motor_PWM,OUTPUT);
  pinMode (trig_pin_front,OUTPUT);
  pinMode (echo_pin_front,INPUT);
  pinMode (trig_pin_rear,OUTPUT);
  pinMode (echo_pin_rear,INPUT);
  Control_Servo.attach (13);
  Serial.begin (9600);
  HC05.begin(9600);
}

void loop() 
{

  
 //Signal Input from Bluetooth
  

  //Initialization of Ultrasonics
  digitalWrite (trig_pin_front,LOW);  
  delayMicroseconds(2);
  digitalWrite (trig_pin_front,HIGH);
  delayMicroseconds(10);
   digitalWrite (trig_pin_front,LOW);  
   delayMicroseconds(2);
   int duration_front=pulseIn (echo_pin_front,HIGH);
   float x_front = duration_front*0.034/2;
   float distance_front = constrain (x_front, 0 ,400);
    
  digitalWrite (trig_pin_rear,LOW);
  delayMicroseconds(2);
  digitalWrite (trig_pin_rear,HIGH);
  delayMicroseconds(10);
  digitalWrite (trig_pin_rear,LOW);
  delayMicroseconds(2);
  int duration_rear=pulseIn (echo_pin_rear,HIGH);
  float x_rear = duration_rear*0.034/2;
  float distance_rear = constrain (x_rear, 0 ,400);
   
if (HC05.available())
  {
  Data = HC05.read();
  Signal += Data;
  }
  
  //Print the recieved char
  //ُEasy driving mode
  if(Signal.length() > 0 )    
  { 
     Serial.println(Data);
      //Determination of Speed;
      if (Data == "V") 
       Speed=50; 
        else if (Data == "U")
       Speed=255/2; 
        else if (Data == "W")
       Speed=255; 
 if (Data!= 'X' )
 {
    
    if(Data == 'F'  && distance_front > 25){
     Control_Servo.write(90);
    analogWrite (right_motor_PWM , Speed);
    digitalWrite (right_motor_in , HIGH);
    analogWrite (left_motor_PWM , Speed);
    digitalWrite (left_motor_in , HIGH);
    }
    else if (Data == 'F' && distance_front < 25 )
   { Control_Servo.write(90);
    analogWrite (right_motor_PWM , 0);
    digitalWrite (right_motor_in ,LOW);
    analogWrite (left_motor_PWM , 0);
    digitalWrite (left_motor_in , LOW);
   }
  
  else if(Data == 'B' && distance_rear > 25 ){
    Control_Servo.write(90);
     analogWrite (right_motor_PWM , Speed);
    digitalWrite (right_motor_in ,LOW);
    analogWrite (left_motor_PWM , Speed);
    digitalWrite (left_motor_in , LOW);
  }
  else if (Data == 'B' && distance_rear < 25 ) //back
   { Control_Servo.write(90);
    analogWrite (right_motor_PWM , 0);
    digitalWrite (right_motor_in ,LOW);
    analogWrite (left_motor_PWM , 0);
    digitalWrite (left_motor_in , LOW);
   }
 else if(Data == 'L'){    //left 
    Control_Servo.write(70);
    analogWrite (right_motor_PWM , Speed);
    digitalWrite (right_motor_in , HIGH);
    analogWrite (left_motor_PWM , Speed);
    digitalWrite (left_motor_in , HIGH);
    
    }
 
  else if(Data == 'R'){ // right
  Control_Servo.write(110);
    analogWrite (right_motor_PWM , Speed);
    digitalWrite (right_motor_in , HIGH);
    analogWrite (left_motor_PWM , Speed);
    digitalWrite (left_motor_in , HIGH);}

     else if(Data == 'I'){ // forward right
  Control_Servo.write(100);
    analogWrite (right_motor_PWM , Speed);
    digitalWrite (right_motor_in , HIGH);
    analogWrite (left_motor_PWM , Speed);
    digitalWrite (left_motor_in , HIGH);}
     else if(Data == 'G'){ // forward left
  Control_Servo.write(80);
    analogWrite (right_motor_PWM , Speed);
    digitalWrite (right_motor_in , HIGH);
    analogWrite (left_motor_PWM , Speed);
    digitalWrite (left_motor_in , HIGH);}

   else if(Data == 'J'){ // back right
 Control_Servo.write(110);
     analogWrite (right_motor_PWM , Speed);
    digitalWrite (right_motor_in ,LOW);
    analogWrite (left_motor_PWM , Speed);
    digitalWrite (left_motor_in , LOW);}
    
     else if(Data == 'H'){ // back left
 Control_Servo.write(70);
     analogWrite (right_motor_PWM , Speed);
    digitalWrite (right_motor_in ,LOW);
    analogWrite (left_motor_PWM , Speed);
    digitalWrite (left_motor_in , LOW);}
    
 
  }            
  
  
  else if (Data=='X') {
  
   //Autonomus Driving mode & Obstacles Avoidance
   Serial.print ("sensor 1 : " );
   Serial.println ( distance_front );

   Serial.print ("sensor 2 : " );
   Serial.println ( distance_rear );

   
 if (distance_front > 25) {  
     Control_Servo.write(90);
    analogWrite (right_motor_PWM , Speed);
    digitalWrite (right_motor_in ,HIGH);
    analogWrite (left_motor_PWM , Speed);
    digitalWrite (left_motor_in , HIGH);
   
      }
      
   else if (distance_front < 25&&distance_rear > 25) { 
    Control_Servo.write(90);
     analogWrite (right_motor_PWM , Speed);
    digitalWrite (right_motor_in ,LOW);
    analogWrite (left_motor_PWM , Speed);
    digitalWrite (left_motor_in , LOW);
   }
   
    else if (distance_front < 25&&distance_rear < 25)
            {     Control_Servo.write(110);
                  analogWrite (right_motor_PWM , Speed);
                  digitalWrite (right_motor_in ,HIGH);
                  analogWrite (left_motor_PWM , Speed);
                  digitalWrite (left_motor_in , HIGH);
                 delay ( 2000); 
                     
    
            }
  }   }
    //delay(800);   
     
   
      
 
 /* else {
   Serial.println ("No obstacle detected. going forward");
   delay (15);
    digitalWrite (right_motor_in1 , HIGH);
    digitalWrite (right_motor_in2 , LOW);
    digitalWrite (left_motor_in1 , HIGH);
    digitalWrite (left_motor_in2 , LOW);
  } */
  
  
}
