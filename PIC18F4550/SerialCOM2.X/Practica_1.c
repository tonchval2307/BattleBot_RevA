#include <xc.h>
#include "system.h"

void Hola_Mundo_Init(void)
{
    pinMode(16,OUTPUT);
}

void Hola_Mundo(void)
{
    digitalWrite(16,HIGH);
    __delay_ms(250);
    digitalWrite(16,LOW);
    __delay_ms(250);
}
