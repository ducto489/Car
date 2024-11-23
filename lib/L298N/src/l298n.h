// Modun dieu khien dong co
#ifndef L298N_H
#define L298N_H

#define MAX_SPEED       255 //từ 0-255
#define MIN_SPEED       0
#define GO_FORWARD      1
#define GO_BACKWARDS    -1

class Motor {
    private:
        /*
            IN_f la chan IN1 hoac IN3
            IN_s la chan IN2 hoac IN4
        */ 
        int IN_f, IN_s;       // Chan dieu khien

    public:
        // Constructor mac dinh
        Motor():IN_f(),IN_s() {};

        void setup_motor();

        void stop();

        //! Quay theo chieu kim dong ho
        /*
            INf: HIGH  
            INs: LOW    (0V)
        */ 
        void rotateClockwise(int speed); // Quay chieu kim dong ho
        void rotateCounterclockwise(int speed);  // Quay nguoc chieu kim dong ho

        // Const co tham so la 2 chan dieu khien
        Motor(int inf, int ins):IN_f(inf), IN_s(ins) {};
};

#endif