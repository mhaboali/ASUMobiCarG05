//Initialization of Variables
#define trig 2
#define echo 4
long duration ,distance ;
int right_motors_in1=6;
int right_motors_in2=7;
int right_motors_PWM=3;
int left_motors_in1=8;
int left_motors_in2=9;
int left_motors_PWM=5;
int right ;
int left ;
int center ;
char Data;
String Signal;
char Data2;
String Signal2;

void setup() 
{
  pinMode (trig,OUTPUT);
  pinMode (echo,INPUT);
  pinMode (right_motors_in1,OUTPUT);
  pinMode (right_motors_in2,OUTPUT);
  pinMode (right_motors_PWM,OUTPUT);
  pinMode (left_motors_in1,OUTPUT);
  pinMode (left_motors_in2,OUTPUT);
  pinMode (left_motors_PWM,OUTPUT);
  pinMode (10,INPUT);
  pinMode (11,INPUT);
  pinMode (12,INPUT);
  Serial.begin (9600);
}

void loop() 
{
   //Signal Input from Bluetooth
  while (Serial.available())
 
 { delay(10);
  Data = Serial.read();
  Signal += Data;
  }
  
  //Print the recieved char
  if(Signal.length() > 0 )    
  {
    Serial.println(Signal);
  }

  //*********************************** easy driving mode ****************************************//
  if (Signal == "easy")
  {
    Serial.println("easy driving mode is on now ");
  while(1){
       digitalWrite(trig,LOW);
       delayMicroseconds(2);
       digitalWrite(trig,HIGH);
       delayMicroseconds(10);
       digitalWrite(trig,LOW);
duration =pulseIn(echo,HIGH);
distance =duration/58;
    delayMicroseconds(100);
     
    if (distance <=20)goto stoop;
    while (Serial.available())
       { delay(10);
         Data2 = Serial.read();
         Signal2 += Data2;
       }
       if(Signal2.length() > 0 )    
         { Serial.println(Signal2);}
       if(Signal2=="exit"){Signal2="";break;}
    if (Signal2 == "F")
  {
    analogWrite (right_motors_PWM , 150);
    digitalWrite (right_motors_in1 , HIGH);
    digitalWrite (right_motors_in2 , LOW);
    analogWrite (left_motors_PWM , 150);
    digitalWrite (left_motors_in1 , HIGH);
    digitalWrite (left_motors_in2 , LOW);
  }
    if (Signal2 == "B")
  {
    analogWrite (right_motors_PWM , 150);
    digitalWrite (right_motors_in1 ,LOW);
    digitalWrite (right_motors_in2 , HIGH);
    analogWrite (left_motors_PWM , 150);
    digitalWrite (left_motors_in1 , LOW);
    digitalWrite (left_motors_in2 , HIGH);
    
  }
    if (Signal2 == "S")
  {
 stoop:   analogWrite (right_motors_PWM , 150);
          digitalWrite (right_motors_in1 , LOW);
          digitalWrite (right_motors_in2 , LOW);
          analogWrite (left_motors_PWM , 150);
          digitalWrite (left_motors_in1 , LOW);
          digitalWrite (left_motors_in2 , LOW);
  }
   if (Signal2 == "R")
  {
    analogWrite (right_motors_PWM , 150);
    digitalWrite (right_motors_in1 , HIGH);
    digitalWrite (right_motors_in2 , LOW);
    analogWrite (left_motors_PWM , 150);
    digitalWrite (left_motors_in1 , LOW);
    digitalWrite (left_motors_in2 , HIGH);
  }
   if (Signal2 == "L")
  {
    analogWrite (right_motors_PWM , 150);
    digitalWrite (right_motors_in1 , LOW);
    digitalWrite (right_motors_in2 , HIGH);
    analogWrite (left_motors_PWM , 150);
    digitalWrite (left_motors_in1 , HIGH);
    digitalWrite (left_motors_in2 , LOW);
  }
  Signal2="";
}}
  //*************************************** line follower mode ***********************************************//
   if (Signal == "follower")
  {Serial.println("line follower mode is on now ");
  while(1){
    while (Serial.available())
       { delay(10);
         Data2 = Serial.read();
         Signal2 += Data2;
       }
       if(Signal2.length() > 0 )    
         { Serial.println(Signal2);}
      if(Signal2=="exit"){Signal2="";break;}
  center =  digitalRead (10);
  right =  digitalRead (11);
  left =  digitalRead (12);
   if (center == 1)
   {Serial.println ("center");
   analogWrite (right_motors_PWM , 150);
    digitalWrite (right_motors_in1 , HIGH);
    digitalWrite (right_motors_in2 , LOW);
    analogWrite (left_motors_PWM , 150);
    digitalWrite (left_motors_in1 , HIGH);
    digitalWrite (left_motors_in2 , LOW);
   }
   if (left == 1)
   {Serial.println ("left");
    analogWrite (right_motors_PWM , 150);
    digitalWrite (right_motors_in1 , LOW);
    digitalWrite (right_motors_in2 , HIGH);
    analogWrite (left_motors_PWM , 150);
    digitalWrite (left_motors_in1 , HIGH);
    digitalWrite (left_motors_in2 , LOW);
   }
   if (right == 1)
   {Serial.println ("right");
    analogWrite (right_motors_PWM , 150);
    digitalWrite (right_motors_in1 , HIGH);
    digitalWrite (right_motors_in2 , LOW);
    analogWrite (left_motors_PWM , 150);
    digitalWrite (left_motors_in1 , LOW);
    digitalWrite (left_motors_in2 , HIGH);
   }
   delay(200);
  }
  }

  //*********************************accurate mode**********************************************// 
   if (Signal == "acc")
  {Serial.println("accurate mode is on now ");
  while(1)
    {while (Serial.available())
       { delay(10);
         Data2 = Serial.read();
         Signal2 += Data2;
       }
       if(Signal2.length() > 0 )    
         { Serial.println(Signal2);}
      if(Signal2=="exit"){Signal2="";break;}
       if(Signal2=="sq"){
      Serial.println("make a square shape bitch !");
    analogWrite (right_motors_PWM , 185);
    digitalWrite (right_motors_in1 , HIGH);
    digitalWrite (right_motors_in2 , LOW);
    analogWrite (left_motors_PWM , 200);
    digitalWrite (left_motors_in1 , HIGH);
    digitalWrite (left_motors_in2 , LOW);
    delay(2000);
      analogWrite (right_motors_PWM , 185);
    digitalWrite (right_motors_in1 , HIGH);
    digitalWrite (right_motors_in2 , LOW);
    analogWrite (left_motors_PWM , 200);
    digitalWrite (left_motors_in1 , LOW);
    digitalWrite (left_motors_in2 , HIGH);
         delay(500);
     analogWrite (right_motors_PWM , 185);
    digitalWrite (right_motors_in1 , HIGH);
    digitalWrite (right_motors_in2 , LOW);
    analogWrite (left_motors_PWM , 200);
    digitalWrite (left_motors_in1 , HIGH);
    digitalWrite (left_motors_in2 , LOW);
    delay(2000);
     analogWrite (right_motors_PWM , 185);
    digitalWrite (right_motors_in1 , HIGH);
    digitalWrite (right_motors_in2 , LOW);
    analogWrite (left_motors_PWM , 200);
    digitalWrite (left_motors_in1 , LOW);
    digitalWrite (left_motors_in2 , HIGH);
         delay(500);
    analogWrite (right_motors_PWM , 185);
    digitalWrite (right_motors_in1 , HIGH);
    digitalWrite (right_motors_in2 , LOW);
    analogWrite (left_motors_PWM , 200);
    digitalWrite (left_motors_in1 , HIGH);
    digitalWrite (left_motors_in2 , LOW);
    delay(2000);
      analogWrite (right_motors_PWM , 185);
    digitalWrite (right_motors_in1 , HIGH);
    digitalWrite (right_motors_in2 , LOW);
    analogWrite (left_motors_PWM , 200);
    digitalWrite (left_motors_in1 , LOW);
    digitalWrite (left_motors_in2 , HIGH);
         delay(500);
          analogWrite (right_motors_PWM ,185);
    digitalWrite (right_motors_in1 , HIGH);
    digitalWrite (right_motors_in2 , LOW);
    analogWrite (left_motors_PWM , 200);
    digitalWrite (left_motors_in1 , HIGH);
    digitalWrite (left_motors_in2 , LOW);
    delay(2000);
     analogWrite (right_motors_PWM , 150);
          digitalWrite (right_motors_in1 , LOW);
          digitalWrite (right_motors_in2 , LOW);
          analogWrite (left_motors_PWM , 150);
          digitalWrite (left_motors_in1 , LOW);
          digitalWrite (left_motors_in2 , LOW);
       }
       Signal2="";
    }
  }
 
  Signal="";
}

