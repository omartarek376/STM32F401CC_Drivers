#include "HAL/Scheduler.h"
#include "MCAL/SYSTICK.h"
#include "HAL/Runners_list.h"

#define TICK_TIME_MS        10


static volatile uint32_t PendingTicks = 0;
extern const runnable_t Runnables_List[_Runnables_Num];

static void Sched()
{
	uint32_t iterator = 0;
	static uint32_t TimeStamp = 0;
	for(iterator = 0 ; iterator < _Runnables_Num;iterator++)
	{
		if((Runnables_List[iterator].callBackFn) && ((TimeStamp % Runnables_List[iterator].periodicityMS) == 0))
		{
			Runnables_List[iterator].callBackFn();
		}
	}
	TimeStamp+= TICK_TIME_MS;
}

void Sched_TickCallBack(void)
{
	PendingTicks++;
}

void Sched_Init()
{
    STK_Init(SOURCE_AHB_DIV_8);
	STK_SetTimeMS(TICK_TIME_MS);
	STK_SetCallback(Sched_TickCallBack);
	STK_EnableInterrupt();
}

void Sched_Start()
{
	STK_Start(STK_MODE_PERIODIC);
	while(1)
	{
		if(PendingTicks)
		{
			PendingTicks--;
			Sched();
		}
	}
}