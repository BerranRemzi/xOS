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
		void(*TaskFunction)(void);
		uint32_t period;
		uint32_t previousTime;
	} Task_t;

	/**
	 * @brief This function loops through all tasks and executes them if their period has passed.
	 */
	void xLoop(void);

	/**
	 * @brief This function creates a new task with the given function pointer and period.
	 * @param _p_Input Function pointer to the task function.
	 * @param _period Period of the task in milliseconds.
	 */
	void xTaskCreate(void(*_p_Input)(void), uint32_t _period);
	
	/**
	 * @brief This function initializes the task array with the given input.
	 * @param _input Pointer to the array of tasks.
	 */
	void xInit(Task_t *_input);

#ifdef __cplusplus
}
#endif

#endif /* XOS_H */