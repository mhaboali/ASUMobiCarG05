#define YELLOW 4 
#define RED 5
#define GREEN 6
#define BLUE 7

void setup() {
pinMode (YELLOW,OUTPUT);
pinMode (RED,OUTPUT);
pinMode (GREEN,OUTPUT);
pinMode (BLUE,OUTPUT);
}

void loop() {
digitalWrite (YELLOW,HIGH);
delay (1000);
digitalWrite (YELLOW,LOW);

digitalWrite (RED,HIGH);
delay (1000);
digitalWrite (RED,LOW);

digitalWrite (GREEN,HIGH);
delay (1000);
digitalWrite (GREEN,LOW);

digitalWrite (BLUE,HIGH);
delay (1000);
digitalWrite (BLUE,LOW);

digitalWrite (GREEN,HIGH);
delay (1000);
digitalWrite (GREEN,LOW);

digitalWrite (RED,HIGH);
delay (1000);
digitalWrite (RED,LOW);


}
