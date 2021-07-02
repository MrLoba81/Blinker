/*
    Blinker.h - A simple non blocking and no interrupt blinking helper class
    Paolo Loberto
*/
#ifndef _BLINKER_H
#define _BLINKER_H

#include <Arduino.h>

class Blinker {
    private:
        uint8_t pin;
        unsigned long highTime;
        unsigned long lowTime;
        unsigned long lastCheck;
        int status; 

    public:
        Blinker();

        void setup(unsigned long millis, uint8_t pin);
        void setup(unsigned long highTime, unsigned long lowTime, uint8_t pin);
        void loop();

        void blink();
        void blink(unsigned long millis);
		void blink(unsigned long highTime, unsigned long lowTime);
};
#endif