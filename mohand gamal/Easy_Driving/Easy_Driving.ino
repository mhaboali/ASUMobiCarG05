#include <Servo.h>
Servo Control_Servo;
int right_motor=2;
int left_motor=3;
int trig_pin_front =4;
int echo_pin_front =5;
int trig_pin_rear =6;
int echo_pin_rear =7;
int Servo_Pos=0;
void setup() {
  // put your setup code here, to run once:
  pinMode (right_motor,INPUT);
  pinMode (left_motor,OUTPUT);
  pinMode (trig_pin_front,OUTPUT);
  pinMode (echo_pin_front,INPUT);
  pinMode (trig_pin_rear,OUTPUT);
  pinMode (echo_pin_rear,INPUT);
  Control_Servo.attach (8);
  Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (trig_pin_front,LOW);  //initialization of Ultrasonics
  digitalWrite (trig_pin_rear,LOW);
  delayMicroseconds(10);
  digitalWrite (trig_pin_front,HIGH);
  digitalWrite (trig_pin_rear,HIGH);
  delayMicroseconds(2);
  int duration_front=pulseIn (echo_pin_front,HIGH);
  int duration_rear=pulseIn (echo_pin_rear,HIGH);
  float x_front = duration_front*0.034/2;
  float x_rear = duration_rear*0.034/2;
  float distance_front = constrain (distance_front, 0 ,400);
  float distance_rear = constrain (distance_rear, 0 ,400);
  // Obstacles Avoidance
  if (distance_front <= 5 || distance_rear <= 5)
  {
    for(Servo_pos=0 ; Servo_pos <=90 ; Servo_pos +=1)
    {
    Control_Servo.write(Servo_pos);
    delay (15);
    }

    }
}
