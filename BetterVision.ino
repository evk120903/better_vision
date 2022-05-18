#include "pitches.h"

const int ep1 = 2; //Echo Sensor 1 (links)
const int ep2 = 3; //Echo Sensor 2 (mitte)
const int ep3 = 4; //Echo Sensor 3 (rechts)
const int tp1 = 5; //Trigger Sensor 1 (links)
const int tp2 = 6; //Trigger Sensor 2 (mitte)
const int tp3 = 7; //Trigger Sensor 3 (rechts)

const int buz = 9; // Buzzer


//Konstanten für die versch. Frequenztöne, imporiert aus pitches.h
int tonC5 = NOTE_C5;
int tonD5 = NOTE_D5;
int tonE5 = NOTE_E5;
int tonF5 = NOTE_F5;
int tonG5 = NOTE_G5;
int tonA5 = NOTE_A5;
int tonB5 = NOTE_B5;

int tonC4 = NOTE_C4;
int tonD4 = NOTE_D4;
int tonE4 = NOTE_E4;
int tonF4 = NOTE_F4;
int tonG4 = NOTE_G4;
int tonA4 = NOTE_A4;
int tonB4 = NOTE_B4;

double duration1;
double duration2;
double duration3;

//gemessene Entfernung
double di1;
double di2;
double di3;


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
  di1 = duration1 * 0.034 / 2;
  /*Serial.print("di 1: ");
  Serial.println(di1);*/

  //Mittlerer US-Sensor misst Distanz und wertet sie aus
  digitalWrite(tp2, LOW);
  delayMicroseconds(2);
  digitalWrite(tp2, HIGH);
  delayMicroseconds(10);
  digitalWrite(tp2, LOW);
  duration2 = pulseIn(ep2, HIGH);
  di2 = duration2 * 0.034 / 2;
  /*Serial.print("di 2: ");
  Serial.println(di2);*/


  //Rechter US-Sensor misst Distanz und wertet sie aus
  digitalWrite(tp3, LOW);
  delayMicroseconds(2);
  digitalWrite(tp3, HIGH);
  delayMicroseconds(10);
  digitalWrite(tp3, LOW);
  duration3 = pulseIn(ep3, HIGH);
  di3 = duration3 * 0.034 / 2;
  /*Serial.print("di 3: ");
  Serial.println(di3);*/

  delay(50);

  /*
  Abfolge:
  Alle Drei
  Links-Rechts
  Mitte-Rechts
  Links-Mitte
  Links
  Mitte
  Rechts
  (Zuerst auf 30 cm geprüft, dann auf 75 cm)*/

  if (di1 <= 15 && di2 <= 15 && di3 <= 15) {
	tone(buz, tonA5, 70); //Tonausgabe
  Serial.print("Alle 3 30 cm \n");
  delay(10);
  }
  else if (di1 <= 15 && di3 <= 15){
    tone(buz, tonD5, 70); //Tonausgabe
    Serial.print("li re 30 cm \n");
  }
  else if (di2 <= 15 && di3 <= 15){
    tone(buz, tonE5, 70); //Tonausgabe
    Serial.print("mi re 30cm \n");
    delay(10);
  }
  else if (di1 <= 15 && di2 <= 15){
    tone(buz, tonF5, 70); //Tonausgabe
    Serial.print("li mi 30cm \n");
    delay(10);
  }
  else if (di1 <= 15){
    tone(buz, tonC5, 70); //Tonausgabe
    Serial.print("li 30cm \n");
    delay(10);
  }
  else if (di2 <= 15){
    tone(buz, tonG5, 70); //Tonausgabe
    Serial.print("mi 30cm \n");
    delay(10);
  }
  else if (di3 <= 15){
    tone(buz, tonB5, 70); //Tonausgabe
    Serial.print("re 30cm \n");
    delay(10);
  }
  else if (di1 <= 50 && di2 <= 50 && di3 <= 50) {
	tone(buz, tonA5, 70); //Tonausgabe
  Serial.print("Alle 3 30 cm \n");
  delay(200);
  }
  else if (di1 <= 30 && di3 <= 30){
    tone(buz, tonD5, 70); //Tonausgabe
    Serial.print("li re 30 cm \n");
    delay(200);
  }
  else if (di2 <= 30 && di3 <= 30){
    tone(buz, tonE5, 70); //Tonausgabe
    Serial.print("mi re 30cm \n");
    delay(200);
  }
  else if (di1 <= 30 && di2 <= 30){
    tone(buz, tonF5, 70); //Tonausgabe
    Serial.print("li mi 30cm \n");
    delay(200);
  }
  else if (di1 <= 30){
    tone(buz, tonC5, 70); //Tonausgabe
    Serial.print("li 30cm \n");
    delay(200);
  }
  else if (di2 <= 30){
    tone(buz, tonG5, 70); //Tonausgabe
    Serial.print("mi 30cm \n");
    delay(200);
  }
  else if (di3 <= 30){
    tone(buz, tonB5, 70); //Tonausgabe
    Serial.print("re 30cm \n");
    delay(200);
  }
  else if (di1 <=75 && di2 <= 75 && di3 <= 75) {
    tone(buz, tonA5, 70); //Tonausgabe
    Serial.print("Alle 3 1m \n");
    delay(700);
  }
  else if (di1 <= 75 && di3 <= 75){
    tone(buz, tonD5, 70); //Tonausgabe
    Serial.print("li re 1m \n");
    delay(700);
  }
  else if (di2 <= 75 && di3 <= 75){
    tone(buz, tonE5, 70); //Tonausgabe
    Serial.print("mi re 1m \n");
    delay(700);
  }
  else if (di1 <= 75 && di2 <= 75){
    tone(buz, tonF5, 70); //Tonausgabe
    Serial.print("li mi 1m \n");
    delay(700);
  }
  else if (di1 <= 75){
    tone(buz, tonC5, 70); //Tonausgabe
    Serial.print("li 1m \n");
    delay(700);
  }
  else if (di2 <= 100){
    tone(buz, tonG5, 70); //Tonausgabe
    Serial.print("mi 1m \n");
    delay(700);
  }
  else if (di3 <= 100){
    tone(buz, tonB5, 70); //Tonausgabe
    Serial.print("re 1m \n");
    delay(700);
  }
  else {
  }
}