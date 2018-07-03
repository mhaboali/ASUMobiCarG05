#define trig 13
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
const byte Photo_Interrupter = 2;  // Motor 1 Interrupt Pin - INT 0
float RPS;
float motorspeed;
const float stepcount = 5.00;
// Integers for pulse counters
volatile int counter_A = 0;

// Integers for pulse counters
unsigned int counter_pulse = 0;

// Constant for wheel diameter
const float wheeldiameter = 65; // Wheel diameter in millimeters

// Interrupt Service Routines
 
// Motor pulse count ISR
void ISR_countA()  
{
  counter_A++;  // increment Motor A counter value
}

int CMtoSteps(float cm) {
 
  int result;  // Final calculation result
  float circumference = (wheeldiameter * 3.14) / 10; // Calculate wheel circumference in cm
  float cm_step = circumference / stepcount;  // CM per Step
  
  float f_result = cm / cm_step;  // Calculate result as a float
  result = (int) f_result; // Convert to an integer (note this is NOT rounded)
  
  return result;  // End and return result
 
}
void MoveForward(int steps, int mspeed) 
{
   counter_A = 0;  //  reset counter to zero
   
   // Set Motor  forward
   digitalWrite(right_motors_in1, HIGH);
   digitalWrite(right_motors_in2, LOW);
   digitalWrite(left_motors_in1, HIGH);
   digitalWrite(left_motors_in2, LOW);
   
   // Go forward until step value is reached
   while (steps > counter_A) 
   {
    if (steps > counter_A) {
    analogWrite(right_motors_PWM, mspeed);
    } 
    else {
    analogWrite(right_motors_PWM, 0);
    analogWrite(left_motors_PWM, 0);
    }
   }  
  // Stop when done
  analogWrite(right_motors_PWM, 0);
  counter_A = 0;  //  reset counter to zero
}

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
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt (Photo_Interrupter), ISR_countA, RISING);  // Increase counter 1 when speed sensor pin goes High
  MoveForward(CMtoSteps(50), 255);  // Forward half a metre at 255 speed
  delay(1000);  // Wait one second
} 
void loop()
{}

