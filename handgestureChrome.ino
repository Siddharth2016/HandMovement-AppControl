/*

Copyright (c) 2018 SIDDHARTH CHANDRA
Licensed under MIT License

*/

const int trigger1 = 11;  //Trigger pin of 1st Sesnor
const int echo1 = 10;     //Echo pin of 1st Sesnor
const int trigger2 = 6;   //Trigger pin of 2nd Sesnor
const int echo2 = 5;      //Echo pin of 2nd Sesnor

long time_taken;
int dist,distL,distR;

void setup() 
{

Serial.begin(9600); 
pinMode(trigger1, OUTPUT); 
pinMode(echo1, INPUT); 
pinMode(trigger2, OUTPUT); 
pinMode(echo2, INPUT); 

}

void calculate_distance(int trigger, int echo)
{

digitalWrite(trigger, LOW);
delayMicroseconds(2);

digitalWrite(trigger, HIGH);
delayMicroseconds(10);

digitalWrite(trigger, LOW);

time_taken = pulseIn(echo, HIGH);
dist= time_taken*0.034/2;
if (dist>50)
dist = 50;

}

void loop() 
{ //infinite loopy

calculate_distance(trigger1,echo1);
distL =dist; //get distance of left sensor

calculate_distance(trigger2,echo2);
distR =dist; //get distance of right sensor

//Control Modes
//Lock Left - Control Mode
if (distL>=14 && distL<=28)
{
  delay(500); //Hand Hold Time
  calculate_distance(trigger1,echo1);
  distL = dist;
  
  if (distL>=14 && distL<=28)
  {
    //Serial.println("Left Locked");
    
    while(distL<=40)
    {
      if (distL>14) //Hand pulled out
      {Serial.println ("next"); delay (2000);}
      
      calculate_distance(trigger1,echo1);
      distL =dist;
    }
  }
}

//Lock Right - Control Mode
if (distR>=14 && distR<=28)
{
  delay(500); //Hand Hold Time
  calculate_distance(trigger2,echo2);
  distR =dist;
  
  if (distR>=14 && distR<=28)
  {
    //Serial.println("Right Locked");
    
    while(distR<=40)
    {
      if (distR<14) //Right hand pushed in
      {Serial.println ("down"); delay (1000);}
      
      if (distR>16) //Right hand pulled out
      {Serial.println ("up"); delay (1000);}
      
      calculate_distance(trigger2,echo2);
      distR =dist;
  }
}
}

delay(500);

}
