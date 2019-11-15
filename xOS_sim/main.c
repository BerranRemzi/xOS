#include <stdio.h>
#include <windows.h>
#include "../src/xOS.h"

#define TICK_DELAY 100

Task_t TaskStruct[4];

uint32_t millis() {
	static uint32_t time = 0;
	time += TICK_DELAY;
	Sleep(TICK_DELAY);
	return time;
}

void Tick_One(void);
void Tick_Two(void);

int main() {
	xInit(TaskStruct);      //Struct with function parameters
	xTaskCreate(&Tick_One, 1000, 100, 0);
	xTaskCreate(&Tick_Two, 500, 100, 1);

	while (1) {
		xLoop();  //xOS task
	}

	(void)getchar();
	return 0;
}

void Tick_One(void) {
	printf("Tick_One\n");
}

void Tick_Two(void) {
	printf("	Tick_Two\n");
}