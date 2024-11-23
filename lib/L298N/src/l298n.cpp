#include "l298n.h"
#include <Arduino.h>

// Goi trong ham setup nghe
void Motor::setup_motor() {
    pinMode(IN_f, OUTPUT);
    pinMode(IN_s, OUTPUT);
}

// Ham stop dung de dung dong co
void Motor::stop() {
    digitalWrite(IN_f, LOW);
    digitalWrite(IN_s, LOW);
}

void Motor::rotateClockwise(int speed) {
    speed = constrain(speed, MIN_SPEED, MAX_SPEED);

    digitalWrite(IN_f, HIGH);
    analogWrite(IN_s, 255-speed); //PWM
}

void Motor::rotateCounterclockwise(int speed) {
    speed = constrain(speed, MIN_SPEED, MAX_SPEED);

    digitalWrite(IN_f, LOW);
    analogWrite(IN_s, speed); // PWM
}

