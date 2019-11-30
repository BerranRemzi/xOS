#ifndef XOS_H
#define XOS_H

/*
 * Include the generic headers required for the FreeRTOS port being used.
 */
#include <stdint.h>
#include <stdbool.h>

#ifdef ARDUINO
#include <arduino.h>
#else
extern uint32_t millis();
#endif // ARDUINO


#ifdef __cplusplus
extern "C" {
#endif

	typedef struct Task_t {
		uint32_t period;
		uint32_t runtime;
		uint8_t priority;
		uint32_t elapsedTime;
		uint32_t previousTime;
		bool isRunning;
		void(*TaskFunction)(void);
	} Task_t;

	static bool isRunning = false;
	static uint8_t tasksNum = 0;
	static int8_t cpuLoadPin = -1;
	static Task_t *p_Task = 0;
	static uint32_t currentTime = 0;

	static uint8_t timeOutCounter = 0;

	void xLoop(void);

	void xTaskCreate(void(*_p_Input)(void), uint32_t _period, uint32_t _runtime, uint8_t _priority);

	void xInit(Task_t *_input);

#ifdef ARDUINO
	void xDebugPin(uint8_t _pin);
	static inline void ChangeDebugPinState(bool _input); 
#endif // ARDUINO
	
	inline uint32_t xMillis(void);

	bool IsRunning(void);

#ifdef __cplusplus
}
#endif

#endif /* ARDUINO_XOS_H */