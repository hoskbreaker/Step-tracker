#ifndef UART_H
#define UART_H

#include <msp430.h>
#include <stdarg.h>

void init_uart(void);
void putchar_uart(char);
void print_uart(char *);
void printf_uart(char *, ...);
//-----------------añadidas para acelerometro-------------------------//
void UARTSendArray(unsigned char *TxArray, unsigned char ArrayLength);
void UARTSendInt(unsigned int x);
//--------------------------------------------------------------------//
#endif
