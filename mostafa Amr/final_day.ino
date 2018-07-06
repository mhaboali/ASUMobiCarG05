#define trig 13
#define echo 4
int input;
int Angle;
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
char Data3;
String Signal3;
int Distance;
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

float CMtoSteps(float cm) {

  float circumference = (wheeldiameter * 3.14) / 10; // Calculate wheel circumference in cm
  float cm_step = circumference / stepcount;  // CM per Step
  float f_result = cm / cm_step;  // Calculate result as a float
  return f_result;  // End and return result

}
void Forward(int distance)
{ analogWrite (right_motors_PWM , 100);
  digitalWrite (right_motors_in1 , HIGH);
  digitalWrite (right_motors_in2 , LOW);
  analogWrite (left_motors_PWM , 110);
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
  else if ( digitalRead(2) == 1)
  {
    while (1)
    {
      if ( digitalRead(2) == 0)
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
void Rotate (int angle)
{
  analogWrite (right_motors_PWM , 140);
  digitalWrite (right_motors_in1 , LOW);
  digitalWrite (right_motors_in2 , HIGH);
  analogWrite (left_motors_PWM , 160);
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
  else if ( digitalRead(2) == 1)
  {
    while (1)
    {
      if ( digitalRead(2) == 0)
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
  while (Serial.available())

  { delay(10);
    Data = Serial.read();
    Signal += Data;
  }

  //Print the recieved char
  if (Signal.length() > 0 )
  {
    Serial.println(Signal);
  }
  //***********************accurate mode****************************************
  if (Signal == "accurate")
  { Serial.println("accurate mode is on now ");
    while (1)
    { while (Serial.available())
      { delay(10);
        Data2 = Serial.read();
        Signal2 += Data2;
      }
      if (Signal2.length() > 0 )
      {
        Serial.println(Signal2);
      }
      if (Signal2 == "exit") {
        Signal2 = "";
        break;
      }
      if (Signal2 == "shapes") {
        Serial.println(Signal2);
        analogWrite (right_motors_PWM , 70);
        digitalWrite (right_motors_in1 , LOW);
        digitalWrite (right_motors_in2 , HIGH);
        analogWrite (left_motors_PWM , 255);
        digitalWrite (left_motors_in1 , LOW);
        digitalWrite (left_motors_in2 , HIGH);
        delay(6000);
        analogWrite (right_motors_PWM , 0);
        analogWrite (left_motors_PWM , 0);
        delay(550);
        analogWrite (right_motors_PWM , 255);
        digitalWrite (right_motors_in1 , LOW );
        digitalWrite (right_motors_in2 , HIGH);
        analogWrite (left_motors_PWM , 70);
        digitalWrite (left_motors_in1 , LOW);
        digitalWrite (left_motors_in2 , HIGH);
        delay(4300);
        analogWrite (right_motors_PWM , 0);
        analogWrite (left_motors_PWM , 0);
        delay(25000);

        for (int i = 0; i < 4; i++)
        {
          Forward(200.0);
          delay(2000);
          analogWrite (right_motors_PWM , 150);
          digitalWrite (right_motors_in1 , LOW);
          digitalWrite (right_motors_in2 , HIGH);
          analogWrite (left_motors_PWM , 170);
          digitalWrite (left_motors_in1 , HIGH);
          digitalWrite (left_motors_in2 , LOW);
          delay(465);
          analogWrite (right_motors_PWM , 0);
          analogWrite (left_motors_PWM , 0);

        }



        analogWrite (right_motors_PWM , 90);
        digitalWrite (right_motors_in1 , LOW);
        digitalWrite (right_motors_in2 , HIGH);
        analogWrite (left_motors_PWM , 255);
        digitalWrite (left_motors_in1 , LOW);
        digitalWrite (left_motors_in2 , HIGH);
        delay(9000);
        analogWrite (right_motors_PWM , 0);
        analogWrite (left_motors_PWM , 0);
        delay(25000);
      }
      if (Signal2 == "distance")
      {
        while (1)
        { while (Serial.available())
          { delay(10);
            Data3 = Serial.read();
            Signal3 += Data3;
          }
          if (Signal3 == "exit") {
            Signal3 = "";
            break;
          }
          if (Signal3.length() > 0 )
          {
            Distance = (Signal3.toInt());
            Serial.println(Distance);
            Forward(Distance);
          }
          Signal3 = "";
        }
      }
      if (Signal2 == "angle")
      {
        while (1)
        { while (Serial.available())
          { delay(10);
            Data3 = Serial.read();
            Signal3 += Data3;
          }
          if (Signal3 == "exit") {
            Signal3 = "";
            break;
          }
          if (Signal3.length() > 0 )
          {
            input = (Signal3.toInt());
            Serial.println(input);
            Angle = map(input, 0, 90, 0, 6);
            Rotate(Angle);
          }
          Signal3 = "";
        }

      }

    }
  }
  //********************************easy mode************************************************
  if (Signal == "easy")
  {
    Serial.println("easy driving mode is on now ");
    while (1) {
      digitalWrite(trig, LOW);
      delayMicroseconds(2);
      digitalWrite(trig, HIGH);
      delayMicroseconds(10);
      digitalWrite(trig, LOW);
      duration = pulseIn(echo, HIGH);
      distance = duration / 58;
      delayMicroseconds(100);

      if (distance <= 50)
      {
        analogWrite (right_motors_PWM , 0);
        analogWrite (left_motors_PWM , 0);
        delay(1000);
        Rotate(7);
        }
      while (Serial.available())
      { delay(10);
        Data2 = Serial.read();
        Signal2 += Data2;
      }
      if (Signal2.length() > 0 )
      {
        Serial.println(Signal2);
      }
      if (Signal2 == "exit") {
        Signal2 = "";
        break;
      }
      if (Signal2 == "F")
      {
        analogWrite (right_motors_PWM , 100);
        digitalWrite (right_motors_in1 , LOW);
        digitalWrite (right_motors_in2 , HIGH);
        analogWrite (left_motors_PWM , 100);
        digitalWrite (left_motors_in1 , LOW);
        digitalWrite (left_motors_in2 , HIGH);
      }
      if (Signal2 == "B")
      {
        analogWrite (right_motors_PWM , 100);
        digitalWrite (right_motors_in1 , HIGH);
        digitalWrite (right_motors_in2 , LOW);
        analogWrite (left_motors_PWM , 100);
        digitalWrite (left_motors_in1 , HIGH);
        digitalWrite (left_motors_in2 , LOW);

      }
      if (Signal2 == "S")
      {
        analogWrite (right_motors_PWM , 0);
        analogWrite (left_motors_PWM , 0);
      }
      
      if (Signal2 == "L")
      {
        analogWrite (right_motors_PWM , 100);
        digitalWrite (right_motors_in1 , LOW);
        digitalWrite (right_motors_in2 , HIGH);
        analogWrite (left_motors_PWM , 100);
        digitalWrite (left_motors_in1 , HIGH);
        digitalWrite (left_motors_in2 , LOW);
      }
      if (Signal2 == "R")
      {
        analogWrite (right_motors_PWM , 100);
        digitalWrite (right_motors_in1 , HIGH);
        digitalWrite (right_motors_in2 , LOW);
        analogWrite (left_motors_PWM , 100);
        digitalWrite (left_motors_in1 , LOW);
        digitalWrite (left_motors_in2 , HIGH);
      }
      Signal2 = "";
    }
  }
  //***************************line follower mode*******************
  if (Signal == "follower")
  { Serial.println("line follower mode is on now ");
    while (1) {
      while (Serial.available())
      { delay(10);
        Data2 = Serial.read();
        Signal2 += Data2;
      }
      if (Signal2.length() > 0 )
      {
        Serial.println(Signal2);
      }
      if (Signal2 == "exit") {
        Signal2 = "";
        break;
      }
      center =  digitalRead (10);
      right =  digitalRead (11);
      left =  digitalRead (12);
      if ((center == 1) ||((left == 1) && (center == 1)&&(right==1)))
      { Serial.println ("center");
        analogWrite (right_motors_PWM , 120);
        digitalWrite (right_motors_in1 , LOW);
        digitalWrite (right_motors_in2 , HIGH);
        analogWrite (left_motors_PWM , 120);
        digitalWrite (left_motors_in1 , LOW);
        digitalWrite (left_motors_in2 , HIGH);
      }
      if ((left == 1) || ((left == 1) && (center == 1)))
      { Serial.println ("left");
        analogWrite (right_motors_PWM , 120);
        digitalWrite (right_motors_in1 , LOW);
        digitalWrite (right_motors_in2 , HIGH);
        analogWrite (left_motors_PWM ,255);
        digitalWrite (left_motors_in1 , HIGH);
        digitalWrite (left_motors_in2 , LOW);
      }
      if (right == 1 || ((right == 1) && (center == 1)))
      { Serial.println ("right");
        analogWrite (right_motors_PWM , 255);
        digitalWrite (right_motors_in1 , HIGH);
        digitalWrite (right_motors_in2 , LOW);
        analogWrite (left_motors_PWM , 140);
        digitalWrite (left_motors_in1 , LOW);
        digitalWrite (left_motors_in2 , HIGH);
      }
     
    }
  }
}


