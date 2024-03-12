#include "HAL/Runners_list.h"
#include "HAL/Scheduler.h"

extern void Runnable_APP1(void);
extern void Runnable_APP2(void);
extern void SW_Runnable(void);
extern void TrafficLights_Runnable(void);


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
        [APP2] = {
        	.name = "Control Led With Switch",
			.periodicityMS = 50,
			.callBackFn = &Runnable_APP2
        },
		[Traffic_Lights_APP] = {
		    .name = "Traffic Light",
			.periodicityMS = 1000,
			.callBackFn = &TrafficLights_Runnable
		}
};