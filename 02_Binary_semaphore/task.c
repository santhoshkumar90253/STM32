#include "header.h"
/*
* Function Name : void taskA(void *parameter)
* Description   : Periodically transmits "Task A running" over UART every 1 second.
*/

void taskA(void *parameter)
{
    while(1)
    {
			// Take semaphore
			xSemaphoreTake(binSemaphore,portMAX_DELAY);
				// Send message
        uart_stringTransmit("Task A Take semaphore\r\n");	
			// Release semaphore
			uart_stringTransmit("Task A Release semaphore\r\n");
				xSemaphoreGive(binSemaphore);
			
			// Delay for 5 ticks			
        vTaskDelay(5); 
				// Send message
        
    }
}

/*
* Function Name : void taskB(void *parameter)
* Description   : Periodically transmits "Task B running" over UART every 1 second.
*/
void taskB(void *parameter)
{
    while(1)
    {
				// Take semaphore
				xSemaphoreTake(binSemaphore,portMAX_DELAY);
				// Send message
        uart_stringTransmit("Task B Take semaphore\r\n");               
				// Release semaphore
			uart_stringTransmit("Task B Release semaphore\r\n");
				xSemaphoreGive(binSemaphore);
				// Send message
        
				// Delay for 5 ticks
        vTaskDelay(5);
    }
}