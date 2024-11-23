// Cam bien khoang cach

#ifndef CAR_H
#define CAR_H

#define TIME_OUT    5000    // Time_out pulseIn là 5000 uS
#define DELAY       1000    // 1s

// Out, In
void setup_mode1(int, int);
void mode_1(int, int);

void setup_mode2(int);
void mode_2(int);

float getDistance(int, int);
#endif