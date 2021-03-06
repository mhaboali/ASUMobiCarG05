//Setup Bluetooth Module
#include <SoftwareSerial.h>
SoftwareSerial HC05(10,12); // CONNECT 10 WITH TX & 12 WITH RX

//Setup Servo Motor
#include <Servo.h> 
Servo Control_Servo;

//Initialization of Variables
int right_motor_in=4;
int left_motor_in=5;
int right_motor_PWM=11;
int left_motor_PWM=11;
int trig_pin_front =6;
int echo_pin_front =7;
int trig_pin_rear =2;
int echo_pin_rear =3;
int Speed ;
char Data;
String Signal;

void setup() 
{
  //Setup PinModes
  pinMode (right_motor_in,OUTPUT);       
  pinMode (left_motor_in,OUTPUT);      
  pinMode (right_motor_PWM,OUTPUT);           
  pinMode (left_motor_PWM,OUTPUT);
  pinMode (trig_pin_front,OUTPUT);
  pinMode (echo_pin_front,INPUT);
  pinMode (trig_pin_rear,OUTPUT);
  pinMode (echo_pin_rear,INPUT);
  Control_Servo.attach (8); //Attach the Servo Pin

  //Setup Serial Communication 
  Serial.begin (9600);
  HC05.begin(9600);
}

void loop() 
{
//Reading recieved Character from Bluetooth
if (HC05.available())
  {
  Data = HC05.read();
  Serial.println(Data); //Print the recieved Character
  } 
  
  //Easy driving mode
  if(HC05.available() )    
  { 
     
      //Determination of Speed;
      if (Data == "V") //Low Speed
       Speed=50; 
        else if (Data == "U") //Medium Speed
       Speed=255/2; 
        else if (Data == "W") //High Speed 
       Speed=255; 
    
    if(Data == 'F' ) //Forward
    {
  //Initialization of Front Ultrasonic
  digitalWrite (trig_pin_front,LOW);  
  delayMicroseconds(2);
  digitalWrite (trig_pin_front,HIGH);
  delayMicroseconds(10);
  digitalWrite (trig_pin_front,LOW);  
  delayMicroseconds(2);
   int duration_front=pulseIn (echo_pin_front,HIGH);
   float x_front = duration_front*0.034/2;
   float distance_front = constrain (x_front, 0 ,400);
   //Print Front Ultrasonic Readings
   Serial.print ("sensor front: "); 
   Serial.println (distance_front);
   //Check on Distance
  if (distance_front > 25){
    Control_Servo.write(90);
     analogWrite (right_motor_PWM , Speed);
    digitalWrite (right_motor_in ,LOW);
    analogWrite (left_motor_PWM , Speed);
    digitalWrite (left_motor_in , LOW);
  }
  else
   { Control_Servo.write(90);
    analogWrite (right_motor_PWM , 0);
    digitalWrite (right_motor_in ,LOW);
    analogWrite (left_motor_PWM , 0);
    digitalWrite (left_motor_in , LOW);
   }
    }
  else if(Data == 'B' ) //Backward
  {
  //Initialization of Rear Ultrasonic
  digitalWrite (trig_pin_rear,LOW);
  delayMicroseconds(2);
  digitalWrite (trig_pin_rear,HIGH);
  delayMicroseconds(10);
  digitalWrite (trig_pin_rear,LOW);
  delayMicroseconds(2);
  int duration_rear=pulseIn (echo_pin_rear,HIGH);
  float x_rear = duration_rear*0.034/2;
  float distance_rear = constrain (x_rear, 0 ,400);
  
 //Print Rear Ultrasonic Readings
   Serial.print ("sensor rear: "); 
   Serial.println (distance_rear);
   
   //Check on Distance
   if (distance_rear > 25){
    Control_Servo.write(90);
    analogWrite (right_motor_PWM , Speed);
    digitalWrite (right_motor_in , HIGH);
    analogWrite (left_motor_PWM , Speed);
    digitalWrite (left_motor_in , HIGH);
    }
    else 
   {
    Control_Servo.write(90);
    analogWrite (right_motor_PWM , 0);
    digitalWrite (right_motor_in ,LOW);
    analogWrite (left_motor_PWM , 0);
    digitalWrite (left_motor_in , LOW);
   }
    
  }
 else if(Data == 'L') //Left
 {     
    Control_Servo.write(70);
    analogWrite (right_motor_PWM , Speed);
    digitalWrite (right_motor_in , HIGH);
    analogWrite (left_motor_PWM , Speed);
    digitalWrite (left_motor_in , HIGH);
    }
 
  else if(Data == 'R')//Right
  { 
    Control_Servo.write(110);
    analogWrite (right_motor_PWM , Speed);
    digitalWrite (right_motor_in , HIGH);
    analogWrite (left_motor_PWM , Speed);
    digitalWrite (left_motor_in , HIGH);
    }

    else if(Data == 'S')//Stop
    { 
    analogWrite (right_motor_PWM , 0);
    digitalWrite (right_motor_in , HIGH);
    analogWrite (left_motor_PWM , 0);
    digitalWrite (left_motor_in , HIGH);}
  }
 /*    else if(Data == 'I'){ // forward right
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
    
 
  }*/}            
  
  
 /* else if (Data=='X') {
  
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
   
     
   
      
 
 /* else {
   Serial.println ("No obstacle detected. going forward");
   delay (15);
    digitalWrite (right_motor_in1 , HIGH);
    digitalWrite (right_motor_in2 , LOW);
    digitalWrite (left_motor_in1 , HIGH);
    digitalWrite (left_motor_in2 , LOW);
  } */
  
  

