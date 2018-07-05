#define trig 13
#define echo 4
long duration , distance ;
int right_motors_in1 = 6;
int right_motors_in2 = 7;
int right_motors_PWM = 3;
int left_motors_in1 = 8;
int left_motors_in2 = 9;
int left_motors_PWM = 5;
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
const float stepcount = 2.00;
// Integers for pulse counters
volatile int counter_A = 0;
// Integers for pulse counters
unsigned int counter_pulse = 0;

// Constant for wheel diameter
const float wheeldiameter = 65; // Wheel diameter in millimeters

float CMtoSteps(float cm) {

  float circumference = (wheeldiameter * 3.14) / 10; // Calculate wheel circumference in cm
  float cm_step = circumference / stepcount;  // CM per Step
  float f_result = cm / cm_step;  // Calculate result as a float
  return f_result;  // End and return result

}
void Forward(float distance)
{ analogWrite (right_motors_PWM , 255);
  digitalWrite (right_motors_in1 , HIGH);
  digitalWrite (right_motors_in2 , LOW);
  analogWrite (left_motors_PWM , 220);
  digitalWrite (left_motors_in1 , HIGH);
  digitalWrite (left_motors_in2 , LOW);
  if ( digitalRead(2) == 0)
  {
    while (1)
    {
      if ( digitalRead(2) == 1)
      {
        counter_A++;
        Serial.println(counter_A);
        delay (70);
      }
      if (CMtoSteps(distance) <= counter_A)
      { analogWrite (right_motors_PWM , 0);
        analogWrite (left_motors_PWM , 0);
        counter_A = 0;
        break;
      }

    }
  }
}
void Rotate (float angle)
{
  analogWrite (right_motors_PWM , 255);
  digitalWrite (right_motors_in1 , LOW);
  digitalWrite (right_motors_in2 , HIGH);
  analogWrite (left_motors_PWM , 255);
  digitalWrite (left_motors_in1 , HIGH);
  digitalWrite (left_motors_in2 , LOW);
  if ( digitalRead(2) == 0)
  {
    while (1)
    {
      if ( digitalRead(2) == 1)
      {
        counter_A++;
        Serial.println(counter_A);
        delay(70);
      }
      if (angle <= counter_A)
      { analogWrite (right_motors_PWM , 0);
        analogWrite (left_motors_PWM , 0);
        counter_A = 0;
        break;
      }
    }
  }
}
void setup() {
  // put your setup code here, to run once:
  pinMode (trig, OUTPUT);
  pinMode (echo, INPUT);
  pinMode (right_motors_in1, OUTPUT);
  pinMode (right_motors_in2, OUTPUT);
  pinMode (right_motors_PWM, OUTPUT);
  pinMode (left_motors_in1, OUTPUT);
  pinMode (left_motors_in2, OUTPUT);
  pinMode (left_motors_PWM, OUTPUT);
  pinMode (10, INPUT);
  pinMode (11, INPUT);
  pinMode (12, INPUT);
  Serial.begin(9600);

}

void loop() {
  for(int i=1;i<=4;i++)
  {
  Forward(200.0);
  delay(1000);
  Rotate(3.0);
  delay(1000);
  }
}


// put your main code here, to run repeatedly:
