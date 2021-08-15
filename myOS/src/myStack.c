/*
 * myStack.c
 *
 *  Created on: 02 Aug. 2021
 *      Author: Ing. Carlos German Carreno Romano
 */

#include "myStack.h"
/*************************************************************************************************
     *  @brief myTaskInit set up a stack with predefined size and stucture
     *
     *  @param *myTask           Puntero a la tarea que se desea inicializar.
     *  @param *myStack          Puntero al espacio reservado como stack para la tarea.
     *  @param *myStackPointer   Puntero a la variable que almacena el stack pointer de la tarea.
     *  @return     None.
***************************************************************************************************/
void myTaskInit(void *myTask, uint32_t *myStack, uint32_t *myStackPointer)
{
    myStack[STACK_SIZE/4 - XPSR] = 1 << THUMB_MODE_BIT; 
    myStack[STACK_SIZE/4 - PC]   = (uint32_t)myTask; /* this is the stack entry point of the task */
    *myStackPointer = (uint32_t)(myStack + STACK_SIZE/4 - STACK_FRAME_SIZE);
}
