#include "xOS.h"

enum Tasks{
  TASK_TICK_ONE,
  TASK_TICK_TWO,
  TASK_TICK_THREE
};

Task_t TaskStruct[4];

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Native USB only
  }

  pinMode(LED_BUILTIN, OUTPUT);

  xInit(TaskStruct);      //Struct with function parameters
  
  //Example use of xTaskCreate() function
  //xTaskCreate(ID,            &Function,  Period, Priority);
  
  xTaskCreate(TASK_TICK_ONE,     &TickOne,    1000,     0);
  xTaskCreate(TASK_TICK_TWO,     &TickTwo,     450,     1);
  xTaskCreate(TASK_TICK_THREE, &TickThree,     200,     2);
}

void loop() {
  xLoop();  //xOS task
}

void TickOne(void) {
  Serial.print("One   - ");
  Serial.println(millis());
}

void TickTwo(void) {
  Serial.print("Two   - ");
  Serial.println(millis());
}

void TickThree(void) {
  Serial.print("Three - ");
  Serial.println(millis());
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}
