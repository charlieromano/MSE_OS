/* 
 * 2021-08-16: tasks.c
 * Ejemplo con freeRTOS: primera aproximación 
 * de resolución de ejercicios de examen
 * Alumno: Ing. Carlos German Carreño Romano
 * 
 */

#include "FreeRTOS.h"
#include "task.h"
#include "sapi.h"
#include "myTasks.h"		//Api de control de tareas y temporizaciÃ³n

#define ANTIREBOTE_MS 20
#define CANT_LEDS 4

void myTask( void* taskParmPtr ){
	while(1)
   {
		gpioToggle( LEDB );
		vTaskDelay( 500 / portTICK_RATE_MS );
	}
}

