#include "xOS.h"
#include "LowPower.h"

Task_t TaskStruct[4];

void setup() {
  Serial.begin(112500);
  pinMode(LED_BUILTIN, OUTPUT);

  xInit(TaskStruct);      //Struct with function parameters
  xDebugPin(LED_BUILTIN); //CPU Load Indicator
  
  //Example use of xTaskCreate() function
  //xTaskCreate(&Function, Period, Run time, Priority);
  
  xTaskCreate(  &Tick_One,    1000,     100,        0);
  xTaskCreate(  &Tick_Two,     450,      45,        1);
  xTaskCreate(&Tick_Three,     200,      20,        2);
}

void loop() {
  xLoop();  //xOS task
  LowPower.powerDown(SLEEP_15MS, ADC_OFF, BOD_OFF);
  xPowerDown(SLEEP_15MS);
}

void Tick_One(void) {
  Serial.write("millis [%4d], wdt [%4d]\n", millis(), xMillis());
  //Serial.print("One   - ");
  //Serial.println(p_Task[0].previousTime);
  //delay(100);
}

void Tick_Two(void) {
  //Serial.print("Two   - ");
  //Serial.println(p_Task[1].previousTime);
  //delay(150);
}

void Tick_Three(void) {
  //Serial.print("Three - ");
  //Serial.println(p_Task[2].previousTime);
  //delay(150);
}
