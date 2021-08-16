#include "main.h"
#include "board.h"
#include "myOS.h"
#include "myStack.h"


#define MILISEC		1000


tarea g_sTarea1, g_sTarea2, g_sTarea3;

/** @brief hardware initialization function
 *	@return none
 */
static void initHardware(void)  {
	Board_Init();
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / MILISEC);		//systick 1ms
}



int main(void)  {

	initHardware();

	os_InitTarea(tarea1, &g_sTarea1);
	os_InitTarea(tarea2, &g_sTarea2);
	os_InitTarea(tarea3, &g_sTarea3);



	os_Init();

	while (1) {
	}
}

