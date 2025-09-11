#include "LPC214x.h"
#include "FreeRTOS.h"
#include "task.h"

void uart_init(void) {
    PINSEL0 |= 0x05;        // P0.0=TXD0, P0.1=RXD0
    U0LCR = 0x83;           // 8-bit, 1 stop, no parity, DLAB=1
    U0DLL = 97;             // 9600 baud @ 12 MHz
    U0DLM = 0;
    U0LCR = 0x03;           // DLAB=0
}

void uart_puts(char *s) {
    while (*s) {
        while (!(U0LSR & (1<<5)));  // wait for THR empty
        U0THR = *s++;
    }
}

void taskA(void *p) {
    while (1) {
        uart_puts("Task A running\r\n");
        vTaskDelay(1000);   // 1s
    }
}

void taskB(void *p) {
    while (1) {
        uart_puts("Task B running\r\n");
        vTaskDelay(2000);   // 2s
    }
}

int main(void) {
    uart_init();
    xTaskCreate(taskA, "TaskA", 256, NULL, 1, NULL);
    xTaskCreate(taskB, "TaskB", 256, NULL, 1, NULL);
    vTaskStartScheduler();
    while (1);
}