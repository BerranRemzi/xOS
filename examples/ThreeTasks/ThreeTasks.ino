#include "xOS.h"

enum Tasks{
  TASK_TickOne,
  TASK_TickTwo,
  TASK_TickThree
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
  
  xTaskCreate(TASK_TickOne,     &TickOne,    1000,     0);
  xTaskCreate(TASK_TickTwo,     &TickTwo,     450,     1);
  xTaskCreate(TASK_TickThree, &TickThree,     200,     2);
}

void loop() {
  xLoop();  //xOS task
}

void TickOne(void) {
  Serial.print("One   - ");
  Serial.println(p_Task[0].previousTime);
}

void TickTwo(void) {
  Serial.print("Two   - ");
  Serial.println(p_Task[1].previousTime);
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}

void TickThree(void) {
  Serial.print("Three - ");
  Serial.println(p_Task[2].previousTime);
}
