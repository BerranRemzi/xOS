#include "xOS.h"

void xLoop(void) {
	currentTime = millis();

	for (uint8_t i = 0; i < tasksNum; ++i) {
		uint32_t timePassed = (uint32_t)(currentTime - p_Task[i].previousTime);
		if ((timePassed >= p_Task[i].period) && (TASK_STOPPED != p_Task[i].period)) {
			p_Task[i].previousTime = currentTime;
			if((NULL != p_Task[i].TaskFunction)){
				p_Task[i].TaskFunction();
			}			
		}
	}
}

void xTaskCreate(uint8_t _id, void(*_p_Input)(void), uint32_t _period, uint8_t _priority) {
	p_Task[_priority].id = _id;
	p_Task[_priority].period = _period;
	p_Task[_priority].priority = _priority;
	p_Task[_priority].TaskFunction = _p_Input;
	tasksNum++;
}

void xInit(Task_t *_input) {
	p_Task = _input;
}

bool IsRunning(uint8_t _id) {
	bool returnValue = true;
	if(TASK_STOPPED == p_Task[_id].period){
		returnValue = false;
	}
	return returnValue;
}