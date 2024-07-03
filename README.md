# xOS - Task Scheduler

This is a simple task scheduler written in C. It allows you to create tasks that run at specified intervals.

## Functions

- `xLoop()`: This function loops through all tasks and executes them if their period has passed.
- `xTaskCreate(void(*_p_Input)(void), uint32_t _period)`: This function creates a new task with the given function pointer and period.
- `xInit(Task_t *_input)`: This function initializes the task array with the given input.

## Usage

1. Initialize the task array with `xInit()`.
2. Create tasks with `xTaskCreate()`.
3. Call `xLoop()` in your main loop to run the tasks.

## Example

Here is an example of how to use this task scheduler:

```c
#include "Arduino.h"
#include "xOS.h"

Task_t TaskStruct[2];

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  xInit(TaskStruct);
  
  xTaskCreate(&TickOne, 1000u);
  xTaskCreate(&TickTwo, 500u);
}

void loop() {
  xLoop();
}

void TickOne(void) {
  Serial.print("One   - ");
  Serial.println(millis());
}

void TickTwo(void) {
  Serial.print("Two   - ");
  Serial.println(millis());
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}
```

## Contributing

Just to let you know, pull requests are welcome. For major changes, please open an issue first to discuss what you want to change.

## Acknowledgements

This code is based on the work of Frank Vahid, Bailey Miller, and Tony Givargis, available at [UCLA - Computer Science - RIOS](https://www.cs.ucr.edu/~vahid/rios/)

## License

MIT
