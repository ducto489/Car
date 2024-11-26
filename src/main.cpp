#include <Arduino.h>
#include "../lib/L298N/src/l298n.h"
#include "../lib/SRF05/src/srf05.h"


#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 10

#define TRIGPIN 3
#define ECHOPIN 2

#define DISTANCE 10 // 10cm

// Cycle time for each thread
#define sensorInterval 50    // 100ms cho cam bien
#define motorInterval  100     // 50ms cho dieu khien dong co

unsigned long motorSpeed;

// Luu thoi gian
unsigned long previousSensorMillis = 0;
unsigned long previousMotorMillis = 0;

// Speed
#define TURNSPEED 125

Motor MotorLeft(IN1, IN2);
Motor MotorRight(IN3, IN4);

void setup() {
  MotorLeft.setup_motor();
  MotorRight.setup_motor();    
  setup_mode1(TRIGPIN, ECHOPIN);
  Serial.begin(9600);
}

void loop() {
  // Lay thoi gian hien hanh
  unsigned long currentMillis = millis();

  // Luong doc gia tri cam bien
  if (currentMillis - previousSensorMillis >= sensorInterval) {
    previousSensorMillis = currentMillis;
    float distance = getDistance(TRIGPIN, ECHOPIN);

    if (distance <= DISTANCE) 
      motorSpeed = 0;
    else
      motorSpeed = 1;
  }                                                                                                                                                                                                                                                                                                                                                     

  // Luong dieu khien dong co
  if (currentMillis - previousMotorMillis >= motorInterval) {
    previousMotorMillis = currentMillis;
    if (motorSpeed == 0)
      Serial.println("\tDung xe");
    else
      Serial.println("Di chuyen tiep");
  }
}
