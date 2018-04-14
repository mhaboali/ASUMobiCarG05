// Include the TimerOne Library from Paul Stoffregen
#include "TimerOne.h"
 
// Constants for Interrupt Pins
// Change values if not using Arduino Uno
 
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

// TimerOne ISR
void ISR_timerone()
{
  Timer1.detachInterrupt();  // Stop the timer
  Serial.print("Motor Speed: "); 
  float RPM = (counter_pulse / diskslots)*60;  // calculate RPM for Motor
  float motorspeed= (((wheeldiameter/2)/10)*RPM* 0.10472); // Calculate Speed in cm per sec
  Serial.print(motorspeed);
  Serial.println("Cm/Sec");
  counter_pulse = 0;  //  reset counter to zero  
  Timer1.attachInterrupt(ISR_timerone);  // Enable the timer
}

   void setup() 
{
  Serial.begin(9600);
  Timer1.initialize(1000000); // set timer for 1sec
  attachInterrupt(digitalPinToInterrupt (Photo_Interrupter), ISR_count, RISING);  // Increase counter 1 when speed sensor pin goes High
  Timer1.attachInterrupt( ISR_timerone ); // Enable the timer
} 

void loop ()
{}

