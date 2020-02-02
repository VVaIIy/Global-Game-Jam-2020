/*

 The Calibrator
 By: Wally Proenza 
 Date: February 2nd, 2020

*/

#include "HX711.h"

#define calibration_factor -447.8572998 
#define WINNER 228.0
#define DOUT  3
#define CLK  2

unsigned long time;
float weight = 0.0;
int score = 0;

void wave();
void lightsON();
void lightsOFF();
void rightRed();
void rightYellow();
void rightGreen();
void rightBlue();
void white();
void leftBlue();
void leftGreen();
void leftYellow();
void leftRed();

HX711 scale;

void setup() {
  Serial.begin(9600);

  pinMode(12,OUTPUT); //left red
  pinMode(11,OUTPUT); //left yellow
  pinMode(10,OUTPUT); //left green
  pinMode(9,OUTPUT); //left blue
  pinMode(8,OUTPUT); // center white
  pinMode(7,OUTPUT); // right blue
  pinMode(6,OUTPUT); // right green 
  pinMode(5,OUTPUT); // right yellow
  pinMode(4,OUTPUT); // right red
  
  Serial.println("The Calibrator");

  scale.begin(DOUT, CLK);
  scale.set_scale(calibration_factor); 
  scale.tare(); //Assuming there is no weight on the scale at start up, reset the scale to 0
  Serial.println("You have 20 seconds to repair and recalibrate the scale.");
}

void loop() {
  
 lightsON();
 delay(300);
 lightsOFF();
 delay(300);
 lightsON();
 delay(300);
 Serial.println("Ready");
 delay(1000);
 wave();
 Serial.println("Set");
 delay(500);
 wave();
 Serial.println("Go!");
 delay(100);

 score = 0;
 time = millis();
 
 while((time + 20000) >= millis())
 {
    
    
    weight = scale.get_units();
    //Game
    if(weight > 700)
    {
    rightRed();  
    }
    else if (weight > 500)
    {
    rightYellow(); 
    score += 1; 
    }
    else if(weight > 400) 
    {
    rightGreen();  
    score += 2; 
    }
    else if( weight > 300)
    {
    rightBlue();  
    score += 3; 
    }
    else if (abs(weight - WINNER) < 12)
    {
    white();  
    score += 5; 
    }
    else if (weight > 156)
    {
    leftBlue();  
    score += 3; 
    }
     else if (weight > 130)
    {
    leftGreen(); 
    score += 2;  
    }
     else if (weight > 60)
    {
    leftYellow(); 
    score += 1;  
    }
     else
    {
    leftRed();  
    }

    Serial.print("Score: ");
    Serial.println(score);
 }


 wave();
 wave();
 wave();
 //end game
  Serial.print("Your score out of a possibile 1070: ");
  Serial.println(score);
  delay(500);
  Serial.print("The scale is ");
  Serial.print((double)score*100/1070);
  Serial.println("% accurate!");
  
 
 while(1)
 {
  
  lightsON();

  delay(500);

  lightsOFF();

  delay(500);
  
 }
}

void rightRed()
{
  digitalWrite(12,LOW); //left red
  digitalWrite(11,LOW); //left yellow
  digitalWrite(10,LOW); //left green
  digitalWrite(9,LOW); //left blue
  digitalWrite(8,LOW); // center white
  digitalWrite(7,LOW); // right blue
  digitalWrite(6,LOW); // right green 
  digitalWrite(5,LOW); // right yellow
  digitalWrite(4,HIGH); // right red
}
void rightYellow()
{
  digitalWrite(12,LOW); //left red
  digitalWrite(11,LOW); //left yellow
  digitalWrite(10,LOW); //left green
  digitalWrite(9,LOW); //left blue
  digitalWrite(8,LOW); // center white
  digitalWrite(7,LOW); // right blue
  digitalWrite(6,LOW); // right green 
  digitalWrite(5,HIGH); // right yellow
  digitalWrite(4,LOW); // right red
}
void rightGreen()
{
  digitalWrite(12,LOW); //left red
  digitalWrite(11,LOW); //left yellow
  digitalWrite(10,LOW); //left green
  digitalWrite(9,LOW); //left blue
  digitalWrite(8,LOW); // center white
  digitalWrite(7,LOW); // right blue
  digitalWrite(6,HIGH); // right green 
  digitalWrite(5,LOW); // right yellow
  digitalWrite(4,LOW); // right red
}
void rightBlue()
{
  digitalWrite(12,LOW); //left red
  digitalWrite(11,LOW); //left yellow
  digitalWrite(10,LOW); //left green
  digitalWrite(9,LOW); //left blue
  digitalWrite(8,LOW); // center white
  digitalWrite(7,HIGH); // right blue
  digitalWrite(6,LOW); // right green 
  digitalWrite(5,LOW); // right yellow
  digitalWrite(4,LOW); // right red
}
void white()
{
  digitalWrite(12,LOW); //left red
  digitalWrite(11,LOW); //left yellow
  digitalWrite(10,LOW); //left green
  digitalWrite(9,LOW); //left blue
  digitalWrite(8,HIGH); // center white
  digitalWrite(7,LOW); // right blue
  digitalWrite(6,LOW); // right green 
  digitalWrite(5,LOW); // right yellow
  digitalWrite(4,LOW); // right red
}
void leftBlue()
{
  digitalWrite(12,LOW); //left red
  digitalWrite(11,LOW); //left yellow
  digitalWrite(10,LOW); //left green
  digitalWrite(9,HIGH); //left blue
  digitalWrite(8,LOW); // center white
  digitalWrite(7,LOW); // right blue
  digitalWrite(6,LOW); // right green 
  digitalWrite(5,LOW); // right yellow
  digitalWrite(4,LOW); // right red
}
void leftGreen()
{
  digitalWrite(12,LOW); //left red
  digitalWrite(11,LOW); //left yellow
  digitalWrite(10,HIGH); //left green
  digitalWrite(9,LOW); //left blue
  digitalWrite(8,LOW); // center white
  digitalWrite(7,LOW); // right blue
  digitalWrite(6,LOW); // right green 
  digitalWrite(5,LOW); // right yellow
  digitalWrite(4,LOW); // right red
}
void leftYellow()
{
  digitalWrite(12,LOW); //left red
  digitalWrite(11,HIGH); //left yellow
  digitalWrite(10,LOW); //left green
  digitalWrite(9,LOW); //left blue
  digitalWrite(8,LOW); // center white
  digitalWrite(7,LOW); // right blue
  digitalWrite(6,LOW); // right green 
  digitalWrite(5,LOW); // right yellow
  digitalWrite(4,LOW); // right red
}
void leftRed()
{
  digitalWrite(12,HIGH); //left red
  digitalWrite(11,LOW); //left yellow
  digitalWrite(10,LOW); //left green
  digitalWrite(9,LOW); //left blue
  digitalWrite(8,LOW); // center white
  digitalWrite(7,LOW); // right blue
  digitalWrite(6,LOW); // right green 
  digitalWrite(5,LOW); // right yellow
  digitalWrite(4,LOW); // right red
}
void lightsON()
{
  digitalWrite(12,LOW); //left red
  digitalWrite(11,LOW); //left yellow
  digitalWrite(10,LOW); //left green
  digitalWrite(9,LOW); //left blue
  digitalWrite(8,LOW); // center white
  digitalWrite(7,LOW); // right blue
  digitalWrite(6,LOW); // right green 
  digitalWrite(5,LOW); // right yellow
  digitalWrite(4,LOW); // right red
}
void lightsOFF()
{
  digitalWrite(12,HIGH); //left red
  digitalWrite(11,HIGH); //left yellow
  digitalWrite(10,HIGH); //left green
  digitalWrite(9,HIGH); //left blue
  digitalWrite(8,HIGH); // center white
  digitalWrite(7,HIGH); // right blue
  digitalWrite(6,HIGH); // right green 
  digitalWrite(5,HIGH); // right yellow
  digitalWrite(4,HIGH); // right red
}

void wave()
{
  lightsOFF();
  delay(300);
  rightRed();
  delay(300);
  rightYellow();
  delay(300);
  rightGreen();
  delay(300);
  rightBlue();
  delay(300);
  white();
  delay(300);
  leftBlue();
  delay(300);
  leftGreen();
  delay(300);
  leftYellow();
  delay(300);
  leftRed();
  delay(300);
}
