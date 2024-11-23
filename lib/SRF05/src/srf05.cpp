#include <Arduino.h>
#include "srf05.h"

void setup_mode1(int TRIGPIN, int ECHOPIN) {
    pinMode(TRIGPIN, OUTPUT);  // Trig ~ output
    pinMode(ECHOPIN, INPUT);   // Echo ~ input
}

void mode_1(int TRIGPIN, int ECHOPIN) {
    float distanceCm = getDistance_mode1(TRIGPIN, ECHOPIN);
    
    Serial.print("Khoang cach hien tai (cm): ");
    Serial.println(distanceCm);
    Serial.print("\n");
}

void setup_mode2(int MODEPIN) {
    pinMode(MODEPIN, OUTPUT); 
}

void mode_2(int MODEPIN) {
    long duration;
    int distance;

    // Phat tin hieu
    digitalWrite(MODEPIN, LOW);
    delayMicroseconds(2);
    digitalWrite(MODEPIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(MODEPIN, LOW);

    // Chuyen sang INPUT de nhan tin hieu phan hoi
    pinMode(MODEPIN, INPUT);
    duration = pulseIn(MODEPIN, HIGH); 

    distance = duration * 0.034 / 2;

    // In kết quả ra Serial Monitor
    Serial.print("Khoang cach: ");
    Serial.print(distance);
    Serial.println(" cm");

    pinMode(MODEPIN, OUTPUT);
}

float getDistance_mode1(int TRIGPIN, int ECHOPIN) {
    long duration;
    float distanceCm;
    // Phat 1 xung 10uS tu chan Trig 
    digitalWrite(TRIGPIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGPIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGPIN, LOW);
    // Thoi gian tin hieu phan hoi o cho ECHOPIN
    duration = pulseIn(ECHOPIN, HIGH);
    
    // khoang cach
    distanceCm = duration * 0.034 / 2; 
    return distanceCm;
}