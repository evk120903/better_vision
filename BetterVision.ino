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
const int ep1 = 2; //Echo Sensor 1 (links)
const int ep2 = 3; //Echo Sensor 2 (mitte)
const int ep3 = 4; //Echo Sensor 3 (rechts)
const int tp1 = 5; //Trigger Sensor 1 (links)
const int tp2 = 6; //Trigger Sensor 2 (mitte)
const int tp3 = 7; //Trigger Sensor 3 (rechts)

const int bl = 8; // Buzzer links
const int br = 9; // Buzzer rechts

int tonG5 = NOTE_G5; //Соль
int tonC5 = NOTE_C5; //До
int tonA5 = NOTE_A5; //Ля

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
  //Linker US-Sensor misst Distanz und wertet sie aus
  digitalWrite(tp1, LOW);
  delayMicroseconds(2);
  digitalWrite(tp1, HIGH);
  delayMicroseconds(10);
  digitalWrite(tp1, LOW);
  duration1 = pulseIn(ep1, HIGH);
  distance1 = duration1 * 0.034 / 2;
  /*Serial.print("Distance 1: ");
  Serial.println(distance1);*/

  //Mittlerer US-Sensor misst Distanz und wertet sie aus
  digitalWrite(tp2, LOW);
  delayMicroseconds(2);
  digitalWrite(tp2, HIGH);
  delayMicroseconds(10);
  digitalWrite(tp2, LOW);
  duration2 = pulseIn(ep2, HIGH);
  distance2 = duration2 * 0.034 / 2;
  /*Serial.print("Distance 2: ");
  Serial.println(distance2);*/


  //Rechter US-Sensor misst Distanz und wertet sie aus
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
    tone(bl, tonA5, 50);
    delay(20);
    tone(br, tonA5, 50); //A5
    Serial.print("Mitte \n");
  }
  else if (distance3 <= 50){
    tone(br, TonC5, 50); //C5
    Serial.print("Rechts \n");
  }
  else if (distance1 <= 50){
    tone(bl, tonG5, 50); //G5
    Serial.print(" Links \n");
  }
  else {    
  }
}
