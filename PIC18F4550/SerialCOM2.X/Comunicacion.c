//#include "system.h"
//#include <xc.h>
//
//char Operator;
//char Terminal;
//
//char buffer = 2;
//unsigned int ADC;
//char A0 = 0;
//char PWMTerminal = 4;
//char ADCMSB,ADCLSB;
//
//char vectorIn[3];
//char vectorOut[2];
//
//unsigned int PWM;
//char PWMMSB,PWMLSB;
//
//void setup(void)
//{
//    SerialBegin(9600);
//    pinMode(4,OUTPUT);
//}
//
//void loop(void)
//{
//    if(SerialAvailable())
//    {
//        for(int i=0;i<buffer;i++)
//        {
//            vectorIn[i] = SerialRead();
//        }
//        PWMLSB = vectorIn[1];
//        PWMMSB = vectorIn[0];
//        PWM = PWMMSB;
//        PWM = PWM << 8;
//        PWM += PWMLSB;
//        analogWrite(4,PWM);
//        ADC = analogRead(0);
//        ADCMSB = cocienteEntero(ADC,256);
//        ADCLSB = residuo(ADC,256);
//        vectorOut[0] = ADCMSB;
//        vectorOut[1] = ADCLSB;
//        for(int i=0;i<buffer;i++)
//        {
//            SerialWrite(vectorOut[i]);
//        }
//        delay(100);
//    }
//}
//
//char residuo(unsigned int numerator, unsigned int denominator)
//{
//	unsigned int temp1 = numerator;
//	while(temp1 > denominator)
//	{
//		temp1 -= denominator;
//	}
//	return temp1;
//}
//
//char cocienteEntero(unsigned int numerator, unsigned int denominator)
//{
//	unsigned int cont = 0;
//	unsigned int temp1 = numerator;
//	while (temp1 > denominator)
//	{
//		temp1 -= denominator;
//		cont++;
//	}
//	return cont;
//}

/*
void setup(void)
{
    SerialBegin(9600);
    pinMode(4,OUTPUT);
}

void loop(void)
{
    if(SerialAvailable())
    {
        for(int i=0;i<buffer;i++)
        {
            vectorIn[i] = SerialRead();
        }
        PWMLSB = vectorIn[1];
        PWMMSB = vectorIn[0];
 *      PWM = PWMMSB;
 *      PWM = PWM << 8;
        PWM += PWMLSB;
 *      analogWrite(4,PWM);
        ADC = analogRead(0);
        ADCMSB = cocienteEntero(ADC,256);
        ADCLSB = residuo(ADC,256);
        vectorOut[0] = ADCMSB;
        vectorOut[1] = ADCLSB;
        for(int i=0;i<buffer;i++)
        {
            SerialWrite(vectorOut[i]);
        }
        delay(100);
    }
}
 */

/*
    void setup(void)
{
    SerialBegin(9600);
    pinMode(3,OUTPUT);
}

void loop(void)
{
    if(SerialAvailable())
    {
        for(char i=0;i<3;i++)
        {
            vectorIn[i] = SerialRead();
        }
        Operator = vectorIn[0] & 0xE0;
        Terminal = vectorIn[0] & 0x1F;
        Operator = Operator >> 5;
        switch(Operator)
        {
            case 2: //pinMode
                pinMode(Terminal,vectorIn[1]);
                break;
            case 3: //digitalWrite
                digitalWrite(Terminal,vectorIn[1]);
                break;
            case 4: //digitalRead
                vectorOut[1] = digitalRead(Terminal);
                break;
            case 5: //analogWrite
                PWMLSB = vectorIn[1];
                PWMMSB = vectorIn[2] * 256;
                PWM = PWMMSB + PWMLSB;
                analogWrite(Terminal,PWM);
                break;
            case 6: //analogRead
                ADC = analogRead(Terminal);
                ADCMSB = cocienteEntero(ADC,256);
                ADCLSB = residuo(ADC,256);
                vectorOut[1] = ADCLSB;
                vectorOut[0] = ADCMSB;
                break;
        }
        for(char i=0;i<2;i++)
        {
            SerialWrite(vectorOut[i]);
        }
        delay(100);
    }
}
 */

/*
 void setup(void)
{
    SerialBegin(9600);
    pinMode(3,OUTPUT);
}

void loop(void)
{
    if(SerialAvailable())
    {
        for(char i=0;i<2;i++)
        {
            vectorIn[i] = SerialRead();
        }
        Operator = vectorIn[0] & 0xE0;
        Operator = Operator >> 5;
        switch(Operator)
        {
            case 2: //pinMode
                Terminal = vectorIn[0] & 0x1F;
                pinMode(Terminal,vectorIn[1]);
                break;
            case 3: //digitalWrite
                digitalWrite(Terminal,vectorIn[1]);
                break;
            case 4: //digitalRead
                vectorOut[1] = digitalRead(Terminal);
                break;
            case 5: //analogWrite
                PWMMSB = vectorIn[0] & 0x1F;
                PWMLSB = vectorIn[1];
                PWM = PWMMSB;
                PWM = PWM <<8;
                PWM += PWMLSB;
                analogWrite(Terminal,PWM);
                vectorOut[0] = PWMLSB;
                vectorOut[1] = PWMMSB;
                break;
            case 6: //analogRead
                Terminal = vectorIn[0] & 0x1F;
                ADC = analogRead(Terminal);
                ADCMSB = cocienteEntero(ADC,256);
                ADCLSB = residuo(ADC,256);
                vectorOut[1] = ADCLSB;
                vectorOut[0] = ADCMSB;
                break;
        }
        for(char i=0;i<2;i++)
        {
            SerialWrite(vectorOut[i]);
        }
        delay(100);
    }
}

 */
