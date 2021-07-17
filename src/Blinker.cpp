/*
    Blinker.h - A simple non blocking and no interrupt blinking helper class
    Paolo Loberto
*/
#include "Blinker.h"

Blinker::Blinker()
{
    this->highTime = 0;
    this->lowTime = 0;
    this->lastCheck = 0;
    this->status = LOW;
    this->pin = 255;
}

void Blinker::setup(unsigned long millis, uint8_t pin)
{
    this->setup(millis, millis, pin);
}

void Blinker::setup(unsigned long highTime, unsigned long lowTime, uint8_t pin)
{
    this->highTime = highTime;
    this->lowTime = lowTime;
    this->pin = pin;
    pinMode(pin, OUTPUT);
}

void Blinker::loop()
{
    unsigned long elapsed = millis() - this->lastCheck;

    if (this->pin != 255)
    {
        if (this->highTime == 0 || this->lowTime == 0)
            this->status = 2;

        switch (this->status)
        {
        case 0: // HighCheck
            if (elapsed >= this->highTime)
                this->status = 2;
            break;
        case 1: // LowCheck
            if (elapsed >= this->lowTime)
                this->status = 3;
            break;
        case 2: // Low
            this->lastCheck = millis();
            digitalWrite(this->pin, LOW);
            this->status = 1;
            break;
        case 3: // High
            this->lastCheck = millis();
            digitalWrite(this->pin, HIGH);
            this->status = 0;
            break;
        }
    }
}

void Blinker::blink()
{
    this->status = 3;
}

void Blinker::blink(unsigned long millis)
{
    this->blink(millis, millis);
}

void Blinker::blink(unsigned long highTime, unsigned long lowTime)
{
    this->highTime = highTime;
    this->lowTime = lowTime;
    this->blink();
}
