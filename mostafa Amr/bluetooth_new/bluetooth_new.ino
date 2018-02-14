
 char data ; 
 
String state ;
int IN =3;
void setup()
{
    Serial.begin(9600);
    
    pinMode(8,OUTPUT);
    
}
void loop()
{if (Serial.available()){
  delay(10);
  data = Serial.read();
  state += data;}


     
      if(state.length() > 0 ){
        Serial.println(state);}
          
      if(state == "f"){         
         digitalWrite(12,LOW);    
          digitalWrite(8,HIGH);
           digitalWrite(6,LOW);    
          digitalWrite(7,HIGH);
          
   }
    if(state =="b"){         
          digitalWrite(8,LOW);    
          digitalWrite(3,LOW);
           digitalWrite(6,HIGH);    
          digitalWrite(7,LOW);      
   }
     if(state =="l"){         
          digitalWrite(8,HIGH);    
          digitalWrite(13,LOW);
           digitalWrite(6,LOW);    
          digitalWrite(7,HIGH);      
   }
    if(state =="r"){         
          digitalWrite(12,LOW);    
          digitalWrite(8,HIGH);
           digitalWrite(6,HIGH);    
          digitalWrite(7,LOW);      
   }
      if(state == "s"){
          
          digitalWrite(6,LOW);    
          digitalWrite(8,LOW);
           digitalWrite(12,LOW);    
          digitalWrite(13,LOW);
     }
     if(state == "w"){
          
         analogWrite(11,100);
     }
       if(state == "h"){
          
         analogWrite(11,255);
     }
      if(state == "m"){
          
         analogWrite(11,150);
     }
      if(state == "s"){
          
          digitalWrite(6,LOW);    
          digitalWrite(7,LOW);
           digitalWrite(12,LOW);    
          digitalWrite(13,LOW);
     }
     
   state  ="";
}
