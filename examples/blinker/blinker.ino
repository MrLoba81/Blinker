#include "Blinker.h"

Blinker blinker_sync;
Blinker blinker_async;

unsigned long lastTimeCheck;
boolean toDo = true;

void setup() {
   // Classic blink on PIN 12: On/Off time is the same, 500ms 
  blinker_sync.setup(500, 12);
  
  // Asyncronus blink on PIN 13: On for 125ms - Off for 500ms
  blinker_async.setup(125, 500, 13);
}

void loop() {
  blinker_sync.loop();
  blinker_async.loop();

  // After 5 seconds turns blinker_async to 1 second sync blink
  if (toDo)
  {
    unsigned long currMillis = millis();
    
    if (currMillis - lastTimeCheck >= 5000) 
    {
      // Set On/Off time to 1s and blink immediately
      blinker_async.blink(1000);
      lastTimeCheck = currMillis;
      toDo = false;
    }
  }
}
