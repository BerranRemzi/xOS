#include "xOS.h"

void xLoop(void) {
	currentTime = millis();

	for (uint8_t i = 0; i < tasksNum; ++i) {
		if (currentTime >= p_Task[i].previousTime + p_Task[i].period && !isRunning) {
#ifdef DEBUG
			ChangeDebugPinState(HIGH);
#endif // DEBUG

			p_Task[i].previousTime = currentTime;
			p_Task[i].elapsedTime = p_Task[i].previousTime + p_Task[i].runtime;
			p_Task[i].isRunning = true;
			isRunning = true;
			p_Task[i].TaskFunction();
		}
		if (currentTime >= p_Task[i].elapsedTime && p_Task[i].isRunning) {
#ifdef DEBUG
			ChangeDebugPinState(HIGH);
#endif // DEBUG
			p_Task[i].isRunning = false;
			isRunning = false;
		}
	}
}

void xTaskCreate(void(*_p_Input)(void), uint32_t _period, uint32_t _runtime, uint8_t _priority) {
	p_Task[_priority].period = _period;
	p_Task[_priority].runtime = _runtime;
	p_Task[_priority].priority = _priority;
	p_Task[_priority].TaskFunction = _p_Input;
	tasksNum++;
}

void xInit(Task_t *_input) {
	p_Task = _input;
}

#ifdef ARDUINO
static inline void ChangeDebugPinState(bool _input) {
	digitalWrite(cpuLoadPin, _input);
}

void xDebugPin(uint8_t _pin) {
	cpuLoadPin = _pin;
}
#endif // ARDUINO

bool IsRunning(void) {
	for (uint8_t i = 0; i < tasksNum; ++i) {
		if (p_Task[i].isRunning == true) {
			return true;
		}
	}
	return false;
}