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


	static const uint32_t wdtDelay[10] = {
	15,31,60,126,250,500,1000,2000,4000,8000
	};

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
	static uint32_t wdtTime = 0;

	void xLoop(void);

	void xTaskCreate(void(*_p_Input)(void), uint32_t _period, uint32_t _runtime, uint8_t _priority);

	void xInit(Task_t *_input);

	void xDebugPin(uint8_t _pin);

	static inline void ChangeDebugPinState(bool _input);

	void xPowerDown(uint8_t _period);

	inline uint32_t xMillis(void);

	bool IsRunning(void);

	bool xIsPowerDownReady(void);

	uint32_t xWDT();

#ifdef __cplusplus
}
#endif

#endif /* ARDUINO_XOS_H */