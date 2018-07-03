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

void makeCircle(int r_motor, int l_motor)
{
  //FORWARD with higher speed (right wheels)
      analogWrite (right_motors_PWM , r_motor);
      digitalWrite (right_motors_in1 , LOW);    
      digitalWrite (right_motors_in2 , HIGH);
    //FORWARD with lower speed (left wheels)
      analogWrite (left_motors_PWM , l_motor);
      digitalWrite (left_motors_in1 , LOW);
      digitalWrite (left_motors_in2 , HIGH);
      delay(6500);
}

void makeCirleright(int r_motor, int l_motor)
{
  //FORWARD with higher speed (right wheels)
      analogWrite (right_motors_PWM , r_motor);
      digitalWrite (right_motors_in1 , LOW);    
      digitalWrite (right_motors_in2 , HIGH);
    //FORWARD with lower speed (left wheels)
      analogWrite (left_motors_PWM , l_motor);
      digitalWrite (left_motors_in1 , LOW);
      digitalWrite (left_motors_in2 , HIGH);
      delay(6000);
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
  Serial.begin (9600);
}

void loop() {
   
      delay(5000);
      analogWrite (right_motors_PWM , 255);
      digitalWrite (right_motors_in1 , HIGH);    
      digitalWrite (right_motors_in2 , LOW);
      delay(60);
      analogWrite (left_motors_PWM , 160);
      digitalWrite (left_motors_in1 , HIGH);
      digitalWrite (left_motors_in2 , LOW);
      delay(3700);
      analogWrite (right_motors_PWM , 0);
      analogWrite (left_motors_PWM , 0);
      delay(200);
      analogWrite (right_motors_PWM , 255);
      digitalWrite (right_motors_in1 , LOW);    
      digitalWrite (right_motors_in2 , HIGH);
      analogWrite (left_motors_PWM ,255);
      digitalWrite (left_motors_in1 , HIGH);
      digitalWrite (left_motors_in2 , LOW);
      delay(570);
      analogWrite (right_motors_PWM , 0);
      analogWrite (left_motors_PWM , 0);
  // put your main code here, to run repeatedly:
  //circle shape:
    //makeCircle(100,255);
   //***********************************
    //reset motors with delay
      //analogWrite (right_motors_PWM , 0);
      //analogWrite (left_motors_PWM , 0);
      //delay(4000);
    //infinty shape:
      //makeCircle(255,100);
      //makeCircle(100,255);
      //reset motors with delay
      //analogWrite (right_motors_PWM , 0);
      //analogWrite (left_motors_PWM , 0);
      //delay(4000);
}
