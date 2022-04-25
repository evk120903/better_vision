const int ep1 = 2; //Echo Sensor 1
const int ep2 = 3; //Echo Sensor 2
const int ep3 = 4; //Echo Sensor 3
const int tp1 = 7; //Trigger Sensor 1
const int tp2 = 6; //Trigger Sensor 2
const int tp3 = 5; //Trigger Sensor 3


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
  digitalWrite(tp2, LOW);
  digitalWrite(tp3, LOW);
  
  delayMicroseconds(2);
  
  digitalWrite(tp1, HIGH);
  digitalWrite(tp2, HIGH);
  digitalWrite(tp3, HIGH);
  
  delayMicroseconds(10);
  
  digitalWrite(tp1, LOW);
  digitalWrite(tp2, LOW);
  digitalWrite(tp3, LOW);

  duration1 = pulseIn(ep1, HIGH);
  duration2 = pulseIn(ep2, HIGH);
  duration3 = pulseIn(ep3, HIGH);

  distance1 = duration1 * 0.034 / 2;
  distance2 = duration2 * 0.034 / 2;
  distance3 = duration3 * 0.034 / 2;

  Serial.print("Distance 1: ");
  Serial.println(distance1);
  Serial.print("Distance 2: ");
  Serial.println(distance2); 
  Serial.print("Distance 3: ");
  Serial.println(distance3); 

}
