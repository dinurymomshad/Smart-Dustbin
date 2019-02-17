#include <Servo.h>                           //Includes Servo library//
int trigPin = 9;                             //Sets digital pin 9 as the Sensor's trigger pin//
int echoPin = 7;                             //Sets disital pin 7 as the Sensor's echo pin//
float distance, duration;                    //Declares variables//
Servo servo1;
void setup() {
  Serial.begin(9600);                        //Starts serial communication//
  servo1.attach(10);                         //Uses digital pin 10 as the signal pin for Servo Motor//
  pinMode(trigPin, OUTPUT);                  //Sets trigPin as an output//
  pinMode(echoPin, INPUT);                   //Sets echoPin as an input//
}

void loop() {
  servo1.write(0);                           // Initially keeps the servo at 0 degree position//

  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);         //Takes the time taken by the sensor to detect any object and puts it as the value for duration//

  distance = (duration * 0.034 / 2);         //Calculates distance using the duration and velocity of sound wave//
  if (distance <= 20) {
    servo1.write(70);                        //If there's any interruption within 20 Centimeters of the sensor the servo opens the lid//
    Serial.println("The distance is - ");
    Serial.print(distance);
    Serial.println(" Centimeter(s)");        //Prints the distance of the object//
    delay(5000);
    servo1.write(0);
  }
}
