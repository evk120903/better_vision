#include "pitches.h"

/*
Ein Buzzer mit:
Nur links
Nur rechts
Nur mitte
Links-Mitte
Rechts-Mitte
Links-Rechts
*/
const int ep1 = 2; //Echo Sensor 1
const int ep2 = 3; //Echo Sensor 2
const int ep3 = 4; //Echo Sensor 3
const int tp1 = 5; //Trigger Sensor 1
const int tp2 = 6; //Trigger Sensor 2
const int tp3 = 7; //Trigger Sensor 3

const int bl = 8; // Buzzer links
const int br = 9; // Buzzer rechts
const int bm = 13; // beide Buzzer

int tonA = NOTE_G5;
int tonB = NOTE_C5;
int tonC = NOTE_A5;

double duration1;
double duration2;
double duration3;

double distance1;
double distance2;
double distance3;


void setup() {
  pinMode(tp1, OUTPUT); 
  pinMode(ep1, INPUT); 
  pinMode(tp2, OUTPUT); 
  pinMode(ep2, INPUT);
  pinMode(tp3, OUTPUT); 
  pinMode(ep3, INPUT);  

  Serial.begin(9600);
  
}

void loop() {
  digitalWrite(tp1, LOW);
  delayMicroseconds(2);
  digitalWrite(tp1, HIGH);
  delayMicroseconds(10);
  digitalWrite(tp1, LOW);
  duration1 = pulseIn(ep1, HIGH);
  distance1 = duration1 * 0.034 / 2;
  /*Serial.print("Distance 1: ");
  Serial.println(distance1);*/


  digitalWrite(tp2, LOW);
  delayMicroseconds(2);
  digitalWrite(tp2, HIGH);
  delayMicroseconds(10);
  digitalWrite(tp2, LOW);
  duration2 = pulseIn(ep2, HIGH);
  distance2 = duration2 * 0.034 / 2;
  /*Serial.print("Distance 2: ");
  Serial.println(distance2);*/



  digitalWrite(tp3, LOW);
  delayMicroseconds(2);
  digitalWrite(tp3, HIGH);
  delayMicroseconds(10);
  digitalWrite(tp3, LOW);
  duration3 = pulseIn(ep3, HIGH);
  distance3 = duration3 * 0.034 / 2;
  /*Serial.print("Distance 3: ");
  Serial.println(distance3);*/

  delay(500);

  if(distance2 <= 50){
    tone(bl, tonC, 50);
    delay(20);
    tone(br, tonC, 50); //A5
    Serial.print("Mitte \n");
  }
  else if (distance3 <= 50){
    tone(br, tonB, 50); //C5
    Serial.print("Rechts \n");
  }
  else if (distance1 <= 50){
    tone(bl, tonA, 50); //G5
    Serial.print(" Links \n");
  }
  else {    
  }
}
