#pragma once
#include <stdio.h>

typedef void (*runnableCB_t) (void);

typedef struct{
	char* name;
	uint32_t periodicityMS;
	runnableCB_t callBackFn;
}runnable_t;

void Sched_Init();
void Sched_Start();