#include <Arduino.h>
#include "../lib/L298N/src/l298n.h"
#include "../lib/SRF05/src/srf05.h"
#include <cstdlib> 
#include <ctime>

int previousTurn = 0; 

#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 10
#define TURNSPEED 125

void goStraight() {
    MotorLeft.rotateCounterclockwise(TURNSPEED);
    MotorRight.rotateClockwise(TURNSPEED);
}

void turnLeft() {
    MotorLeft.rotateClockwise(TURNSPEED);
    MotorRight.rotateClockwise(TURNSPEED);
}

void turnRight() {
    MotorLeft.rotateCounterclockwise(TURNSPEED);
    MotorRight.rotateCounterclockwise(TURNSPEED);
}

void setup() {
    Motor MotorLeft(IN1, IN2);
    Motor MotorRight(IN3, IN4);
    MotorLeft.setup_motor();
    MotorRight.setup_motor();    

    # Setup random function
    srand(time(0));
}

void turn(){
    if (previousTurn == 0) {
        previousTurn = rand() % 2 + 1;
    }

    if (previousTurn == 1) {
        turnLeft();
    } else if (previousTurn == 2) {
        turnRight();
    }
}

void loop() {
    distance = getDistance()
    if (distance < 20) {
        turn()
    }
    else {
        previousTurn = 0;
        goStraight();
    }
}


