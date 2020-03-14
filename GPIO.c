#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "GPIO.h"

void InitPortA(uint8_t dir,uint8_t en,uint8_t pull,uint8_t cr)
{
uint32_t delay;
SYSCTL_RCGCGPIO_R |=0x01;
while(SYSCTL_PRGPIO_R&&0x01==0);
GPIO_PORTA_AFSEL_R &=0;
GPIO_PORTA_PCTL_R &=0;
GPIO_PORTA_AMSEL_R &=0;
GPIO_PORTA_DIR_R |=dir;
GPIO_PORTA_DEN_R |=en;
GPIO_PORTA_PUR_R|=pull;
GPIO_PORTA_LOCK_R|=0x4C4F434B;
GPIO_PORTA_CR_R |=cr;
}
void InitPortB(uint8_t dir,uint8_t en,uint8_t pull,uint8_t cr)
{
uint32_t delay;
SYSCTL_RCGCGPIO_R |=0x02;
delay=100;
while(SYSCTL_PRGPIO_R&&0x02==0);
GPIO_PORTB_AFSEL_R &=0;
GPIO_PORTB_PCTL_R &=0;
GPIO_PORTB_AMSEL_R &=0;
GPIO_PORTB_DIR_R |=dir;
GPIO_PORTB_DEN_R |=0x1F;
GPIO_PORTB_PUR_R|=0x11;
GPIO_PORTB_LOCK_R|=0x4C4F434B;
GPIO_PORTB_CR_R |=0x1F;
}
void InitPortC(uint8_t dir,uint8_t en,uint8_t pull,uint8_t cr)
{
uint32_t delay;
SYSCTL_RCGCGPIO_R |=0x04;
delay=100;
while(SYSCTL_PRGPIO_R&&0x04==0);
GPIO_PORTC_AFSEL_R &=0;
GPIO_PORTC_PCTL_R &=0;
GPIO_PORTC_AMSEL_R &=0;
GPIO_PORTC_DIR_R |=dir;
GPIO_PORTC_DEN_R |=en;
GPIO_PORTC_PUR_R|=pull;
GPIO_PORTC_LOCK_R|=0x4C4F434B;
GPIO_PORTC_CR_R |=cr;
}
void InitPortD(uint8_t dir,uint8_t en,uint8_t pull,uint8_t cr)
{
uint32_t delay;
SYSCTL_RCGCGPIO_R |=0x08;
delay=100;
while(SYSCTL_PRGPIO_R&&0x08==0);
GPIO_PORTD_AFSEL_R &=0;
GPIO_PORTD_PCTL_R &=0;
GPIO_PORTD_AMSEL_R &=0;
GPIO_PORTD_DIR_R |=dir;
GPIO_PORTD_DEN_R |=en;
GPIO_PORTD_PUR_R|=pull;
GPIO_PORTD_LOCK_R|=0x4C4F434B;
GPIO_PORTD_CR_R |=cr;
}
void InitPortE(uint8_t dir,uint8_t en,uint8_t pull,uint8_t cr)
{
uint32_t delay;
SYSCTL_RCGCGPIO_R |=0x10;
delay=100;
while(SYSCTL_PRGPIO_R&&0x10==0);
GPIO_PORTE_AFSEL_R &=0;
GPIO_PORTE_PCTL_R &=0;
GPIO_PORTE_AMSEL_R &=0;
GPIO_PORTE_DIR_R |=dir;
GPIO_PORTE_DEN_R |=en;
GPIO_PORTE_PUR_R|=pull;
GPIO_PORTE_LOCK_R|=0x4C4F434B;
GPIO_PORTE_CR_R |=cr;
}
void InitPortF(uint8_t dir,uint8_t en,uint8_t pull,uint8_t cr)
{
uint32_t delay;
SYSCTL_RCGCGPIO_R |=0x20;
delay=100;
while(SYSCTL_PRGPIO_R&&0x20==0);
GPIO_PORTF_AFSEL_R &=0;
GPIO_PORTF_PCTL_R &=0;
GPIO_PORTF_AMSEL_R &=0;
GPIO_PORTF_DIR_R |=dir;
GPIO_PORTF_DEN_R |=en;
GPIO_PORTF_PUR_R|=pull;
GPIO_PORTF_LOCK_R|=0x4C4F434B;
GPIO_PORTF_CR_R |=cr;
}
