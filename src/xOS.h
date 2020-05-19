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

#define TASK_STOPPED 	(UINT32_MAX)

#ifdef __cplusplus
extern "C" {
#endif

	typedef struct Task_t {
		uint8_t id;
		uint32_t period;
		uint8_t priority;
		uint32_t previousTime;
		void(*TaskFunction)(void);
	} Task_t;

	void xLoop(void);

	void xTaskCreate(uint8_t _id, void(*_p_Input)(void), uint32_t _period, uint8_t _priority);

	void xInit(Task_t *_input);

	bool IsRunning(uint8_t _id);

#ifdef __cplusplus
}
#endif

#endif /* ARDUINO_XOS_H */