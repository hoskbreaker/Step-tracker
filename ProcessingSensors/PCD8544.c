#include <msp430g2553.h>
#include "PCD8544.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//***************************************************************************************
//  MSP430 + PCD8544-based LCD (like Nokia 5110)
//
//  MSP430x2xx Family User's Guide      : http://www.ti.com/lit/ug/slau144j/slau144j.pdf
//  MSP430G2x53 Data Sheet              : http://www.ti.com/lit/ds/symlink/msp430g2553.pdf
//  PCD8544 Data Sheet (Nokia 5110 MCU) : https://www.sparkfun.com/datasheets/LCD/Monochrome/Nokia5110.pdf
//
//  My setup:
//
//         NOKIA 5110 LCD                                               MSP-EXP430G2
//       -----------------                                           -------------------
//      |              GND|<-- Ground ------------------------------|J6     GND         |
//      |               BL|<-- Back-light (not connected)
//      |              VCC|<-- Vcc +3..5V --------------------------|J1.1   VCC         |
//      |                 |
//      |              CLC|<-- Clock -------------------------------|J1.7   P1.4        |
//      |              DIN|<-- Data Input --------------------------|J2.15  P1.2        |
//      |               DC|<-- Data/Command (high/low) -------------|J1.3   P1.3        |
//      |               CE|<-- Chip Enable (active low) ------------|J1.2   P1.0        |
//      |              RST|<-- Reset -------------------------------|J2.16  RST
//
//
//  This example is based on the RobG's example : http://forum.43oh.com/topic/1312-nokia-5110-display
//  Changes:
//  - Removed graphics function
//  - Removed unused functions
//  + LCD test runs in the loop
//  + Added some bars animation
//
//***************************************************************************************

//variables
static volatile uint8_t step =0;
static volatile uint8_t count =1;
static volatile uint8_t stop[3]={0,0,0};



// Sets LCD address (x = 0..83, y = 0..5)
void setAddr(unsigned char xAddr, unsigned char yAddr)
{
    writeToLCD(LCD5110_COMMAND, PCD8544_SETXADDR | xAddr);
    writeToLCD(LCD5110_COMMAND, PCD8544_SETYADDR | yAddr);
}
void writeToLCD(unsigned char dataCommand, unsigned char data) {
    LCD5110_SELECT;

    if(dataCommand) {
        LCD5110_SET_DATA;
    } else {
        LCD5110_SET_COMMAND;
    }

    UCA0TXBUF = data;
    while(!(IFG2 & UCA0TXIFG));
    LCD5110_DESELECT;
}

void initLCD() {

    /*  Default settings after reset:
    *
    *   Source of the Main system clock (MCLK) and sub-main system clock (SMCLK) is
    *   Internal Digitally Controlled Oscillator Clock (DCO).
    *   MCLK is about 1 MHz.
    *   VLO is about 12 kHz.
    *
    *   Code execution begins in less then 2 us.
    *
    */

    P1OUT |= LCD5110_SCE_PIN | LCD5110_DC_PIN;  // Disable LCD, set Data mode
    P1DIR |= LCD5110_SCE_PIN | LCD5110_DC_PIN;  // Set pins to output direction

    // Setup USIA
    P1SEL |= LCD5110_SCLK_PIN | LCD5110_DN_PIN;
    P1SEL2 |= LCD5110_SCLK_PIN | LCD5110_DN_PIN;

    UCA0CTL0 |= UCCKPH | UCMSB | UCMST | UCSYNC; // 3-pin, 8-bit SPI master
    UCA0CTL1 |= UCSSEL_2;               // SMCLK
    UCA0BR0 |= 0x01;                    // 1:1
    UCA0BR1 = 0;
    UCA0CTL1 &= ~UCSWRST;               // clear SW

    __delay_cycles(500000);             //se puede quitar?

    writeToLCD(LCD5110_COMMAND, PCD8544_FUNCTIONSET | PCD8544_EXTENDEDINSTRUCTION);
    writeToLCD(LCD5110_COMMAND, PCD8544_SETVOP | 0x3F);
    writeToLCD(LCD5110_COMMAND, PCD8544_SETTEMP | 0x02);
    writeToLCD(LCD5110_COMMAND, PCD8544_SETBIAS | 0x03);
    writeToLCD(LCD5110_COMMAND, PCD8544_FUNCTIONSET);
    writeToLCD(LCD5110_COMMAND, PCD8544_DISPLAYCONTROL | PCD8544_DISPLAYNORMAL);
}

void writeCharToLCD(char c) {
    unsigned char i;
    for(i = 0; i < 5; i++) {
        writeToLCD(LCD5110_DATA, font[c - 0x20][i]);
    }
    writeToLCD(LCD5110_DATA, 0);
}

void writeStringToLCD(const char *string) {
    while(*string) {
        writeCharToLCD(*string++);
    }
}

void clearLCD() {
    setAddr(0, 0);
    int i = 0;
    while(i < PCD8544_MAXBYTES) {
        writeToLCD(LCD5110_DATA, 0);
        i++;
    }
    setAddr(0, 0);
}

void clearBank(unsigned char bank) {
    setAddr(0, bank);
    int i = 0;
    while(i < PCD8544_HPIXELS) {
        writeToLCD(LCD5110_DATA, 0);
        i++;
    }
    setAddr(0, bank);
}
void exampleLCD(void) {

//    WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer
//
//    /*  Default settings after reset:
//    *
//    *   Source of the Main system clock (MCLK) and sub-main system clock (SMCLK) is
//    *   Internal Digitally Controlled Oscillator Clock (DCO).
//    *   MCLK is about 1 MHz.
//    *   VLO is about 12 kHz.
//    *
//    *   Code execution begins in less then 2 us.
//    *
//    */
    initLCD();

    int c;

    while(1) {
        clearLCD();

        setAddr(10, 2);
        writeStringToLCD("Nokia 5110");

        __delay_cycles(2000000);
        setAddr(0, 0);

        // First half of the font

        c = 0x20;
        while(c < (65 + 0x20)) {
            writeCharToLCD(c);
            c++;
        }

        __delay_cycles(2000000);
        clearLCD();

        // Second half of the font

        c = 65 + 0x20;

        while(c < (96 + 0x20)) {
            writeCharToLCD(c);
            c++;
        }

        // Horizontal bars
        // Bar length can be 0..83

        // Fill the bar left to right

        clearBank(3);
        for(c = 0; c < 84; c++) {
            writeToLCD(LCD5110_DATA, 0xFF);
            __delay_cycles(20000);
        }

        // Fill the bar left to right, then clear it backward

        clearBank(4);
        for(c = 0; c < 50; c++) {
            writeToLCD(LCD5110_DATA, 0xFF);
            __delay_cycles(20000);
        }
        for(; c-- > 0;) {
            setAddr(c, 4);
            writeToLCD(LCD5110_DATA, 0);
            __delay_cycles(20000);
        }

        // Fill the bar left to right, then clear it left to right

        clearBank(5);
        for(c = 0; c < 80; c++) {
            writeToLCD(LCD5110_DATA, 0xFF);
            __delay_cycles(20000);
        }
        setAddr(0, 5);
        for(c = 0; c < 80; c++) {
            writeToLCD(LCD5110_DATA, 0);
            __delay_cycles(20000);
        }

    } // eof while()
} // eof main

void ShowAxisValue(int x, int y, int z)
{
    char ejex[4],ejey[4],ejez[4];

    sprintf(ejex,"%d",x);
    sprintf(ejey,"%d",y);
    sprintf(ejez,"%d",z);

    clearLCD();
    setAddr(0, 0);
    writeStringToLCD("eje x:");
    setAddr(48,0);
    writeStringToLCD(ejex);
    setAddr(0, 2);
    writeStringToLCD("eje y:");
    setAddr(48,2);
    writeStringToLCD(ejey);
    setAddr(0, 4);
    writeStringToLCD("eje z:");
    setAddr(48,4);
    writeStringToLCD(ejez);
}

void punto(uint8_t fila, uint8_t columna)
{
    clearLCD();
    setAddr(fila, columna);
    writeStringToLCD("*");
}
//direccion
//      int direccion(int p, int dir)
//      {
//          if(stop[1]==0){
//              if(d>=20){
//                  stop[1] = 1;
//              }else if(d<=-20){
//                  stop[1] = 2;
//              }else{
//                  my=0;
//              }
//          }else if(stop[1] == 1){
//              if( d<=-10){
//                  stop[1] = 0;
//                  return
//                  step++;
//                  my=10;
//              }else{
//                  my=0;
//              }
//          }else if(stop[1] == 2){
//              if(d>=10){
//                  stop[1] = 0;
//                  step++;
//                  my=-10;
//              }else{
//                  my=0;
//              }
//          }
//      }
//movimiento
uint8_t direccion(int p, uint8_t d)
{

}
uint8_t paso(int p, uint8_t dir)
{
    uint8_t aux = dir;
    if(stop[2]==0){
        if(p>=20){
            stop[2] = 1;
        }
        if(p<=-20){
            stop[2] = 2;
        }
    }else if(stop[2] == 1){
        if( p<=-20){
            aux=dir + 5;
            stop[2] = 0;
        }
    }else if(stop[2] == 2){
        if (p>=20){
            aux=dir - 5;
            stop[2] = 0;
        }
    }
    return aux;
}
