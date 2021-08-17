/* 
 * 2021-08-16: tasks.h
 * Ejemplo con freeRTOS: primera aproximación 
 * de resolución de ejercicios de examen
 * Alumno: Ing. Carlos German Carreño Romano
 * 
 */

#include "FreeRTOS.h"
#include "sapi.h"
#include "task.h"

#define ANTIREBOTE_MS 20

void myTask( void* taskParmPtr );
void myTaskLED( void* taskParmPtr );
void myTaskTEC( void* taskParmPtr );



