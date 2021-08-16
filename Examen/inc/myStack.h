/*
 * myStack.h
 *
 *  Created on: 14 Aug. 2021
 *      Author: Ing. Carlos German Carreno Romano
 */

#ifndef MSE_OS_INC_MY_STACK_H_
#define MSE_OS_INC_MY_STACK_H_

#include <stdint.h>

#define     STACK_SIZE      256
#define     STACK_FRAME_SIZE 8 

#define     XPSR            1
#define     PC              2
#define     LR              3
#define     R12             4
#define     R3              5
#define     R2              6
#define     R1              7
#define     R0              8
#define     LR_IRQ          9
#define     LR_IRQ_VALUE    0XFFFFFFF9
#define     THUMB_MODE_BIT  24      

uint32_t myStack1[STACK_SIZE/4];
uint32_t myStack2[STACK_SIZE/4];
uint32_t myStack3[STACK_SIZE/4];
uint32_t myStack4[STACK_SIZE/4];
uint32_t myStack5[STACK_SIZE/4];
uint32_t myStack6[STACK_SIZE/4];
uint32_t myStack7[STACK_SIZE/4];
uint32_t myStack8[STACK_SIZE/4];

void myTaskInit(void *myTask, uint32_t *myStack, uint32_t *myStackPointer);

#endif /* MSE_OS_INC_MY_STACK_H_ */
