/* 
 * 2021-08-16
 * Ejemplo con freeRTOS: primera aproximación 
 * de resolución de ejercicios de examen
 * Alumno: Ing. Carlos German Carreño Romano
 * 
 */

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include "sapi.h"        // <= sAPI header

DEBUG_PRINT_ENABLE;

void myTask( void* taskParmPtr );

int main(void)
{
   boardConfig();

   // UART for debug messages
   debugPrintConfigUart( UART_USB, 115200 );
   debugPrintlnString( "Blinky con freeRTOS y sAPI." );

   // Led monitor
   gpioWrite( LED3, ON );

   // Crear tarea en freeRTOS
	xTaskCreate(
                myTask,                     // Funcion de la tarea a ejecutar
		          (const char *)"myTask",     // Nombre de la tarea como String amigable para el usuario
					 configMINIMAL_STACK_SIZE*2, // Tama�o del stack de la tarea
					 0,                          // Parametros de tarea
					 tskIDLE_PRIORITY+1,         // Prioridad de la tarea
					 0                           // Puntero a la tarea creada en el sistema
              );

   // Iniciar scheduler
	vTaskStartScheduler();

   // ---------- REPETIR POR SIEMPRE --------------------------
   while( TRUE )
   {
      // Si cae en este while 1 significa que no pudo iniciar el scheduler
   }
   return 0;
}



void myTask( void* taskParmPtr )
{
	while(1)
   {
		gpioToggle( LEDB );
		vTaskDelay( 500 / portTICK_RATE_MS );
	}
}

