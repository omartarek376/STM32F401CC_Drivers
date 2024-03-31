#include "HAL/Runners_list.h"
#include "HAL/Scheduler.h"

extern void Runnable_APP1(void);
extern void SW_Runnable(void);
extern void LCD_RunnerTask(void);


const runnable_t Runnables_List[_Runnables_Num] =
{
        [APP1] = {
            .name = "Toggle Led For 1 Second",
            .periodicityMS = 250,
            .callBackFn = &Runnable_APP1
        },
        [Switches_Runner] = {
        	.name = "Switch Debouncer",
        	.periodicityMS = 10,
			.callBackFn = &SW_Runnable
        },
		[LCD_Runner] = {
		    .name = "LCD Runner",
			.periodicityMS = 1,
			.callBackFn = &LCD_RunnerTask
		}
};