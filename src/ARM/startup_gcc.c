//*****************************************************************************
//
// startup_gcc.c - Startup code for use with GNU tools.
//
// Copyright (c) 2013-2014 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
// 
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
// 
// This is part of revision 2.1.0.12573 of the EK-TM4C1294XL Firmware Package.
//
//*****************************************************************************

#include <stdint.h>
#include "system_stm32f4xx.h"
//#include "inc/hw_types.h"

//*****************************************************************************
//
// Forward declaration of the default fault handlers.
//
//*****************************************************************************
void ResetISR(void);
static void NmiSR(void);
static void FaultISR(void);
static void IntDefaultHandler(void);

//*****************************************************************************
//
// External declaration for the interrupt handler used by the application.
//
//*****************************************************************************
extern void USART1_IRQHandler(void);
extern void button_irq();
extern void MemManage_Handler(void);
extern void BusFault_Handler(void);
extern void UsageFault_Handler(void);
extern void DebugMon_Handler(void);
extern void SysTick_Handler(void);
extern void EXTI2_IRQHandler(void) ;
//*****************************************************************************
//
// The entry point for the application.
//
//*****************************************************************************
extern int main(void);

//*****************************************************************************
//
// Reserve space for the system stack.
//
//*****************************************************************************
static uint32_t pui32Stack[2048];
#define BootRAM ((void *)(0xF108F85F))
//*****************************************************************************
//
// The vector table.  Note that the proper constructs must be placed on this to
// ensure that it ends up at physical address 0x0000.0000.
//
//*****************************************************************************
__attribute__ ((section(".isr_vector")))
void (* const g_pfnVectors[])(void) =
{
  (void (*)(void))((uint32_t)pui32Stack + sizeof(pui32Stack)),
   // The initial stack pointer
   ResetISR,                               // The reset handler
   NmiSR,                                  // The NMI handler
   FaultISR,                               // The hard fault handler
   MemManage_Handler,                      				// The MPU fault handler
   BusFault_Handler,                      				// The bus fault handler
   UsageFault_Handler,                      				// The usage fault handler
   0,                                      // Reserved
   0,                                      // Reserved
   0,                                      // Reserved
   0,                                      // Reserved
   IntDefaultHandler,                      // SVCall handler
   DebugMon_Handler,                      				// Debug monitor handler
   0,                                      // Reserved
   IntDefaultHandler,                      // The PendSV handler
   SysTick_Handler,                      // The SysTick handler
   IntDefaultHandler,                   /* Window WatchDog              */                                        
   IntDefaultHandler,                    /* PVD through EXTI Line detection */                        
   IntDefaultHandler,             /* Tamper and TimeStamps through the EXTI line */            
   IntDefaultHandler,               /* RTC Wakeup through the EXTI line */                      
   IntDefaultHandler,                  /* FLASH                        */                                          
   IntDefaultHandler,                    /* RCC                          */                                            
   IntDefaultHandler,                  /* EXTI Line0                   */                        
   IntDefaultHandler,                  /* EXTI Line1                   */                          
   EXTI2_IRQHandler,                 /* EXTI Line2                   */                          
   IntDefaultHandler,               /* EXTI Line3                   */                          
   IntDefaultHandler,              /* EXTI Line4                   */                          
   IntDefaultHandler,          /* DMA1 Stream 0                */                  
   IntDefaultHandler,           /* DMA1 Stream 1                */                   
   IntDefaultHandler,           /* DMA1 Stream 2                */                   
   IntDefaultHandler,           /* DMA1 Stream 3                */                   
   IntDefaultHandler,           /* DMA1 Stream 4                */                   
   IntDefaultHandler,           /* DMA1 Stream 5                */                   
   IntDefaultHandler,           /* DMA1 Stream 6                */                   
   IntDefaultHandler,                    /* ADC1, ADC2 and ADC3s         */                   
   IntDefaultHandler,                /* CAN1 TX                      */                         
   IntDefaultHandler,               /* CAN1 RX0                     */                          
   IntDefaultHandler,               /* CAN1 RX1                     */                          
   IntDefaultHandler,               /* CAN1 SCE                     */                          
   IntDefaultHandler,                /* External Line[9:5]s          */                          
   IntDefaultHandler,          /* TIM1 Break and TIM9          */         
   IntDefaultHandler,          /* TIM1 Update and TIM10        */         
   IntDefaultHandler,     /* TIM1 Trigger and Commutation and TIM11 */
   IntDefaultHandler,                /* TIM1 Capture Compare         */                          
   IntDefaultHandler,                   /* TIM2                         */                   
   IntDefaultHandler,                   /* TIM3                         */                   
   IntDefaultHandler,                   /* TIM4                         */                   
   IntDefaultHandler,                /* I2C1 Event                   */                          
   IntDefaultHandler,                /* I2C1 Error                   */                          
   IntDefaultHandler,                /* I2C2 Event                   */                          
   IntDefaultHandler,                /* I2C2 Error                   */                            
   IntDefaultHandler,                   /* SPI1                         */                   
   IntDefaultHandler,                   /* SPI2                         */                   
   IntDefaultHandler,                 /* USART1                       */                   
   IntDefaultHandler,                 /* USART2                       */                   
   IntDefaultHandler,                 /* USART3                       */                   
   IntDefaultHandler,              /* External Line[15:10]s        */                          
   IntDefaultHandler,              /* RTC Alarm (A and B) through EXTI Line */                 
   IntDefaultHandler,            /* USB OTG FS Wakeup through EXTI line */                       
   IntDefaultHandler,         /* TIM8 Break and TIM12         */         
   IntDefaultHandler,          /* TIM8 Update and TIM13        */         
   IntDefaultHandler,     /* TIM8 Trigger and Commutation and TIM14 */
   IntDefaultHandler,                /* TIM8 Capture Compare         */                          
   IntDefaultHandler,           /* DMA1 Stream7                 */                          
   IntDefaultHandler,                   /* FSMC                         */                   
   IntDefaultHandler,                   /* SDIO                         */                   
   IntDefaultHandler,                   /* TIM5                         */                   
   IntDefaultHandler,                   /* SPI3                         */                   
   IntDefaultHandler,                  /* UART4                        */                   
   IntDefaultHandler,                  /* UART5                        */                   
   IntDefaultHandler,               /* TIM6 and DAC1&2 underrun errors */                   
   IntDefaultHandler,                   /* TIM7                         */
   IntDefaultHandler,           /* DMA2 Stream 0                */                   
   IntDefaultHandler,           /* DMA2 Stream 1                */                   
   IntDefaultHandler,           /* DMA2 Stream 2                */                   
   IntDefaultHandler,           /* DMA2 Stream 3                */                   
   IntDefaultHandler,           /* DMA2 Stream 4                */                   
   IntDefaultHandler,                    /* Ethernet                     */                   
   IntDefaultHandler,               /* Ethernet Wakeup through EXTI line */                     
   IntDefaultHandler,                /* CAN2 TX                      */                          
   IntDefaultHandler,               /* CAN2 RX0                     */                          
   IntDefaultHandler,               /* CAN2 RX1                     */                          
   IntDefaultHandler,               /* CAN2 SCE                     */                          
   IntDefaultHandler,                 /* USB OTG FS                   */                   
   IntDefaultHandler,           /* DMA2 Stream 5                */                   
   IntDefaultHandler,           /* DMA2 Stream 6                */                   
   IntDefaultHandler,           /* DMA2 Stream 7                */                   
   IntDefaultHandler,                 /* USART6                       */                    
   IntDefaultHandler,                /* I2C3 event                   */                          
   IntDefaultHandler,                /* I2C3 error                   */                          
   IntDefaultHandler,         /* USB OTG HS End Point 1 Out   */                   
   IntDefaultHandler,          /* USB OTG HS End Point 1 In    */                   
   IntDefaultHandler,            /* USB OTG HS Wakeup through EXTI */                         
   IntDefaultHandler,                 /* USB OTG HS                   */                   
   IntDefaultHandler,                   /* DCMI                         */                   
   IntDefaultHandler,                   /* CRYP crypto                  */                   
   IntDefaultHandler,               /* Hash and Rng                 */
   IntDefaultHandler,                    /* FPU                          */                         
   IntDefaultHandler,                  /* UART7                        */
   IntDefaultHandler,                  /* UART8                        */
   IntDefaultHandler,                   /* SPI4                         */
   IntDefaultHandler,                   /* SPI5                         */
   IntDefaultHandler,                   /* SPI6                         */
   IntDefaultHandler,                   /* SAI1                         */
   IntDefaultHandler,                   /* LTDC                         */
   IntDefaultHandler,                /* LTDC error                   */
   IntDefaultHandler                  /* DMA2D                        */
};

//*****************************************************************************
//
// The following are constructs created by the linker, indicating where the
// the "data" and "bss" segments reside in memory.  The initializers for the
// for the "data" segment resides immediately following the "text" segment.
//
//*****************************************************************************
//extern uint32_t _etext;
//extern uint32_t _data;
//extern uint32_t _edata;
//extern uint32_t _bss;
//extern uint32_t _ebss;

extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;




//*****************************************************************************
//
// This is the code that gets called when the processor first starts execution
// following a reset event.  Only the absolutely necessary set is performed,
// after which the application supplied entry() routine is called.  Any fancy
// actions (such as making decisions based on the reset cause register, and
// resetting the bits in that register) are left solely in the hands of the
// application.
//
//*****************************************************************************
	void
ResetISR(void)
{
	uint32_t *pui32Src, *pui32Dest;

	//
	// Copy the data segment initializers from flash to SRAM.
	//
	pui32Src = &_sidata;
	for(pui32Dest = &_sdata; pui32Dest < &_edata; )
	{
		*pui32Dest++ = *pui32Src++;
	}

	//
	// Zero fill the bss segment.
	//
	for(pui32Dest = &_sbss; pui32Dest < &_ebss; )
	{
		*pui32Dest++ = 0;
	}

	//
	// Call the application's entry point.
	//
	SystemInit();
	main();
}

//*****************************************************************************
//
// This is the code that gets called when the processor receives a NMI.  This
// simply enters an infinite loop, preserving the system state for examination
// by a debugger.
//
//*****************************************************************************
	static void
NmiSR(void)
{
	//
	// Enter an infinite loop.
	//
	while(1)
	{
	}
}

//*****************************************************************************
//
// This is the code that gets called when the processor receives a fault
// interrupt.  This simply enters an infinite loop, preserving the system state
// for examination by a debugger.
//
//*****************************************************************************
	static void
FaultISR(void)
{
	//
	// Enter an infinite loop.
	//
	while(1)
	{
	}
}

//*****************************************************************************
//
// This is the code that gets called when the processor receives an unexpected
// interrupt.  This simply enters an infinite loop, preserving the system state
// for examination by a debugger.
//
//*****************************************************************************
	static void
IntDefaultHandler(void)
{
	//
	// Go into an infinite loop.
	//
	while(1)
	{
	}
}
