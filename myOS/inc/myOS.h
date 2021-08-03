/*
 * myOS.h
 *
 *  Created on: 02 Aug. 2021
 *      Author: Ing. Carlos German Carreno Romano
 */
#ifndef MSE_OS_INC_MY_OS_H_
#define MSE_OS_INC_MY_OS_H_

#include 	<stdint.h>
#include 	<stdbool.h>
#include 	"board.h"



#define 	DEFAULT_SIZE 	20
#define		STACK_SIZE				32
#define		STACK_FRAME_SIZE		8
#define 	FULL_STACKING_SIZE		17	//16 core registers + valor previo de LR

/************************************************************************************
 * 	Tasks
 ***********************************************************************************/

#define		TASK_NAME_LEN			10	// length of task name 
#define 	TASK_MAX_LEN			8	// lenght of tasks list
#define 	TASK_MAX_LEN_W_IDLE		TASK_MAX_LEN+1	// lenght of tasks list plus idle task
#define		TASK_PRIORITY_MAX		0
#define 	TASK_PRIORITY_MIN		3

typedef enum 	myTaskState {
	TASK_READY,
	TASK_RUNNING,
	TASK_BLOCKED,
	TASK_SUSPENDED
};
typedef enum _myTaskState myTaskState;

typedef struct  _myTask {

	uint8_t 	id;
	uint32_t 	stack[STACK_SIZE/4];
	uint32_t 	sp;
	void 		*entry_point;
	myTaskState	state;
	uint8_t		priority;
	uint32_t 	blocked_ticks;
	char		name[DEFAULT_SIZE]

};
typedef struct 	_myTask 	myTask;


/************************************************************************************
 * 	OS Control Structure 
 ***********************************************************************************/

/*	Registers  */
#define XPSR			1
#define PC_REG			2
#define LR				3
#define LR_PREV_VALUE	9
#define R0				8
#define R1				7
#define R2				6
#define R3				5
#define R4				10
#define R5				11
#define R6				12
#define R7				13
#define R8				14
#define R9				15
#define R10 			16
#define R11 			17
#define R12				4

#define INIT_XPSR 	1 << 24				//xPSR.T = 1
#define EXEC_RETURN	0xFFFFFFF9			//retornar a modo thread con MSP, FPU no utilizada

#define ERR_OS_TASK_NUM		-1
#define ERR_OS_SCHEDULING	-2

typedef enum 	_myOSState {
	OS_RUN,
	OS_RESET
};

typedef enum 	_myOSState myOSState;

typedef struct 	_myOSControl {
	myOSState 	state;
	bool 		schedulerIRQ;
	myTask 		*task;
	myTask  	*nextTask;
	int32_t 	error;

	uint8_t 	myTaskLen;
	void 		*myTaskList[TASK_MAX_LEN_W_IDLE];

};
typedef struct 	_myOSControl 	myOSControl;


/*==================[definicion de prototipos]=================================*/

void os_InitTarea(void *entryPoint, tarea *task);
void os_Init(void);
int32_t os_getError(void);

#endif /* MSE_OS_INC_MY_OS_H_ */