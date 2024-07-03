#include "xOS.h"

/**
 * @brief This variable keeps track of the number of tasks that have been created.
 */
static uint8_t tasksNum = 0;

/**
 * @brief This is a pointer to the array of tasks.
 */
static Task_t* p_Task = 0;

/**
 * @brief This function loops through all tasks and executes them if their period has passed.
 */
void xLoop(void) {
	uint32_t currentTime = millis();

	for (uint8_t i = 0; i < tasksNum; i++) {
		uint32_t timePassed = (uint32_t)(currentTime - p_Task[i].previousTime);
		if ((timePassed >= p_Task[i].period) && (TASK_STOPPED != p_Task[i].period)) {
			p_Task[i].previousTime = currentTime;
			if((NULL != p_Task[i].TaskFunction)){
				p_Task[i].TaskFunction();
			}			
		}
	}
}

/**
 * @brief This function creates a new task with the given function pointer and period.
 * @param _p_Input Function pointer to the task function.
 * @param _period Period of the task in milliseconds.
 */
void xTaskCreate(void(*_p_Input)(void), uint32_t _period) {
	p_Task[tasksNum].period = _period;
	p_Task[tasksNum].TaskFunction = _p_Input;
	tasksNum++;
}

/**
 * @brief This function initializes the task array with the given input.
 * @param _input Pointer to the array of tasks.
 */
void xInit(Task_t *_input) {
	p_Task = _input;
}
