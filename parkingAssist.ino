#include <LiquidCrystal.h>

const int buzz = 2;
const int redLED = 9, yellowLED = 10, greenLED = 11;
const int trigPin = 4;
const int echoPin = 3;
const int E = 13, RS = 12, D4 = 5, D5 = 6, D6 = 7, D7 = 8;
LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

float duration, distance;

void setup() {
  lcd.begin(16, 2);
  
  pinMode(buzz, OUTPUT); 
  pinMode(trigPin, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  if(distance > 100){
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
  }
  else if(distance > 50 && distance < 100){
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);

  }
  else if(distance < 50){
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);

  }
  if(distance <= 30){
    tone(buzz, 1000);
    //delay(1000); 
  }
  if(distance > 30){
    noTone(buzz);
    //delay(1000); 
  }



  duration = pulseIn(echoPin, HIGH);
  distance = microsecondsToCentimeters(duration);
  lcd.setCursor(0,0);
  lcd.print("Dist.: ");
  lcd.print(distance);
  lcd.print("cm");

  
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}