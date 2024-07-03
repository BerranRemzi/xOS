#include "Arduino.h"
#include "xOS.h"

Task_t TaskStruct[2];

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  xInit(TaskStruct);
  
  xTaskCreate(&TickOne, 1000u);
  xTaskCreate(&TickTwo, 500u);
}

void loop() {
  xLoop();
}

void TickOne(void) {
  Serial.print("One   - ");
  Serial.println(millis());
}

void TickTwo(void) {
  Serial.print("Two   - ");
  Serial.println(millis());
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}
