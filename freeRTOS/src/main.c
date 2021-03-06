/* 
 * 2021-08-16
 * Ejemplo con freeRTOS: primera aproximación 
 * de resolución de ejercicios de examen
 * Alumno: Ing. Carlos German Carreño Romano
 * 
 */

#include "main.h"

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
   //tickInit(250);

   // Crear tarea en freeRTOS
	xTaskCreate(
                myTaskLED,                     // Funcion de la tarea a ejecutar
		          (const char *)"myTask",     // Nombre de la tarea como String amigable para el usuario
					 configMINIMAL_STACK_SIZE*2, // Tama�o del stack de la tarea
					 0,                          // Parametros de tarea
					 tskIDLE_PRIORITY+2,         // Prioridad de la tarea
					 0                           // Puntero a la tarea creada en el sistema
              );

   xTaskCreate(myTaskTEC, 
      (const char *)"myTask", configMINIMAL_STACK_SIZE*2, 
      0, tskIDLE_PRIORITY+1,0
      );

	vTaskStartScheduler();

   while(1){

   }
   return 0;
}

