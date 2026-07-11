/******************************************************************************
 * @file    startup_stm32f103c8t6.s
 * @brief   Startup File for STM32F103C8T6
 *
 * @author  S.I. SYED ARSHAD
 ******************************************************************************/

.syntax unified
.cpu cortex-m3
.thumb
.global Reset_Handler
.global Default_Handler
.global g_pfnVectors

.extern _estack
.extern main

/******************************************************************************
 * Vector Table
 ******************************************************************************/

.section .isr_vector, "a", %progbits

.type g_pfnVectors, %object

g_pfnVectors:

.word _estack          /* Initial Stack Pointer */
.word Reset_Handler    /* Reset Handler */
.word Default_Handler  /* NMI Handler */
.word Default_Handler  /* Hard Fault Handler */
.word Default_Handler  /* Memory Management */
.word Default_Handler  /* Bus Fault */
.word Default_Handler  /* Usage Fault */
.word 0                /* Reserved */
.word 0                /* Reserved */
.word 0                /* Reserved */
.word 0                /* Reserved */
.word Default_Handler  /* SVCall */
.word Default_Handler  /* Debug Monitor */
.word 0                /* Reserved */
.word Default_Handler  /* PendSV */
.word Default_Handler  /* SysTick */



/******************************************************************************
 * Reset Handler
 ******************************************************************************/

.section .text.Reset_Handler

.type Reset_Handler, %function

Reset_Handler:

    /* Copy initialized data from FLASH to RAM */
    ldr r0, =_sidata
    ldr r1, =_sdata
    ldr r2, =_edata

CopyData:
    cmp r1, r2
    bge ClearBSS

    ldr r3, [r0], #4
    str r3, [r1], #4

    b CopyData


    /* Clear .bss section */
ClearBSS:
    ldr r1, =_sbss
    ldr r2, =_ebss
    movs r3, #0

ZeroBSS:
    cmp r1, r2
    bge CallMain

    str r3, [r1], #4

    b ZeroBSS


CallMain:
    bl main


LoopForever:
    b LoopForever
/******************************************************************************
 * Default Handler
 ******************************************************************************/

.type Default_Handler, %function

Default_Handler:
    b Default_Handler
