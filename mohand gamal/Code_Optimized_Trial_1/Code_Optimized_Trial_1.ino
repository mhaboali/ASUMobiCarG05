// Include the TimerOne Library from Paul Stoffregen
#include "TimerOne.h"

//Setup Servo Motor
#include <Servo.h>
Servo Control_Servo;
float distance_front;
float distance_rear;

// Constants for Interrupt Pins
const byte Photo_Interrupter = 2;  // Motor 1 Interrupt Pin - INT 0

// Integers for pulse counters
unsigned int counter_pulse = 0;

// Constant for wheel diameter
const float wheeldiameter = 65; // Wheel diameter in millimeters

// Float for number of slots in encoder disk
float diskslots = 4;  // Change to match value of encoder disk

// Interrupt Service Routines

// Motor pulse count ISR
void ISR_count()
{
  counter_pulse++;  // increment Motor 1 counter value
}


//Initialization of Variables
int right_motor_in = 7;
int left_motor_in = 6;
int right_motor_PWM = 11;
int left_motor_PWM = 11;
int trig_pin_front = 4;
int echo_pin_front = 5;
int trig_pin_rear = 12;
int echo_pin_rear = 13;
int Speed ;
char Data;


void ISR_timerone()
{

  Timer1.detachInterrupt();  // Stop the timer
  float RPM = (counter_pulse / diskslots) * 60; // calculate RPM for Motor
  float motorspeed = (((wheeldiameter / 2) / 10) * RPM * 0.10472); // Calculate Speed in cm per sec
  counter_pulse = 0;  //  reset counter to zero
  Timer1.attachInterrupt(ISR_timerone);  // Enable the timer

  digitalWrite (trig_pin_front, LOW);  // Read Front Ultrasonic
  delayMicroseconds(10);
  digitalWrite (trig_pin_front, HIGH);
  delayMicroseconds(2);
  float duration_front = pulseIn (echo_pin_front, HIGH);
  float x_front = duration_front * 0.034 / 2;
  if(x_front > 1 || x_front < 60)
  { distance_front = constrain (x_front, 0 , 60);}
 else
 {distance_front = 50;}


}




void setup()
{
  Timer1.initialize(1000000); // set timer for 1sec
  attachInterrupt(digitalPinToInterrupt (Photo_Interrupter), ISR_count, RISING);  // Increase counter 1 when speed sensor pin goes High
  Timer1.attachInterrupt( ISR_timerone ); // Enable the timer

  //Setup PinModes
  pinMode (right_motor_in, OUTPUT);
  pinMode (left_motor_in, OUTPUT);
  pinMode (right_motor_PWM, OUTPUT);
  pinMode (left_motor_PWM, OUTPUT);
  pinMode (trig_pin_front, OUTPUT);
  pinMode (echo_pin_front, INPUT);
  pinMode (trig_pin_rear, OUTPUT);
  pinMode (echo_pin_rear, INPUT);
  Control_Servo.attach (9); //Attach the Servo Pin

  //Setup Serial Communication
  Serial.begin (9600);
  Control_Servo.write(90);
}

void loop()
{
  Serial.println (distance_front);
  //Reading recieved Character from Bluetooth
  if (Serial.available())
  {
    Data = Serial.read();
    Serial.println(Data); //Print the recieved Character

    //Easy driving mode
    //Determination of Speed
    if (Data == "V") //Low Speed
      Speed = 50;
    else if (Data == "U") //Medium Speed
      Speed = 255 / 2;
    else Speed = 255; //High Speed

    if (Data == 'F' ) //Forward
    {
      
      if (distance_front > 10 && distance_front <= 100 ) {
        Control_Servo.write(90);
        analogWrite (right_motor_PWM , Speed);
        digitalWrite (right_motor_in , LOW);
        analogWrite (left_motor_PWM , Speed);
        digitalWrite (left_motor_in , LOW);
      }
      else
      {
        analogWrite (right_motor_PWM , 0);
        digitalWrite (right_motor_in , LOW);
        analogWrite (left_motor_PWM , 0);
        digitalWrite (left_motor_in , LOW);
      }
    }
    else if (Data == 'B' ) //Backward
    {

      //Check on Distance
      // if (distance_rear > 25) {
      Control_Servo.write(90);
      analogWrite (right_motor_PWM , Speed);
      digitalWrite (right_motor_in , HIGH);
      analogWrite (left_motor_PWM , Speed);
      digitalWrite (left_motor_in , HIGH);
    }
    else
    {
      analogWrite (right_motor_PWM , 0);
      digitalWrite (right_motor_in , LOW);
      analogWrite (left_motor_PWM , 0);
      digitalWrite (left_motor_in , LOW);
    }
  }
  else if (Data == 'L') //Left
  {
    Control_Servo.write(70);
    analogWrite (right_motor_PWM , Speed);
    digitalWrite (right_motor_in , HIGH);
    analogWrite (left_motor_PWM , Speed);
    digitalWrite (left_motor_in , HIGH);
  }
  else if (Data == 'r') //Right
  {
    Control_Servo.write(110);
    analogWrite (right_motor_PWM , Speed);
    digitalWrite (right_motor_in , HIGH);
    analogWrite (left_motor_PWM , Speed);
    digitalWrite (left_motor_in , HIGH);
  }

  else if (Data == 'S') //Stop
  {
    Control_Servo.write(90);
    analogWrite (right_motor_PWM , 0);
    digitalWrite (right_motor_in , HIGH);
    analogWrite (left_motor_PWM , 0);
    digitalWrite (left_motor_in , HIGH);
  }
}




