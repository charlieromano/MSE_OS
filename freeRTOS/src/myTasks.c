/* 
 * 2021-08-16: tasks.c
 * Ejemplo con freeRTOS: primera aproximación 
 * de resolución de ejercicios de examen
 * Alumno: Ing. Carlos German Carreño Romano
 * 
 */

#include "myTasks.h"		//Api de control de tareas y temporizaciÃ³n

#define ANTIREBOTE_MS 20
#define CANT_LEDS 4

void myTask( void* taskParmPtr ){
	//tick_t counter;
	while(1)
   {
		gpioToggle( LEDB );
		vTaskDelay( 500 / portTICK_RATE_MS );
	}
}


void myTaskLED( void* taskParmPtr ){

	while(1)
   {
		gpioToggle( LEDG );
		gpioToggle( LEDB );
		vTaskDelay( 500 / portTICK_RATE_MS );
	}
}


void myTaskTEC( void* taskParmPtr ){

	while(1)
   {
		if(!gpioRead(TEC3))
			gpioToggle( LED2 );
		vTaskDelay( 1 / portTICK_RATE_MS );
	}
}

