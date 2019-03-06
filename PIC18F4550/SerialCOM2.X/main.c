#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include <float.h>
#include "delays.h"
#include "system.h"

unsigned long millis = 0;
long freq;
int SPBRG_Register;

int main(void)
{
    SPBRG_Register = SPBRG;
    
    configuracionInicial();
    setup();
    while(1)
    {
        loop();
    }
    return 0;
}

void configuracionInicial(void)
{
    ADCConfig();
    CCPConfig();
    PORTSConfiguration();
    TMR0Config();
    TMR1Config();
}
void delay(const int milis)
{
    for(int j=0;j<milis;j++)
    {
        //Retardo de 1ms
        for(int i=0;i<400;i++)
        {
            asm("NOP");
        }
    }
}

void delayMicroseconds(const int micros)
{
    //Con un Cristal de 20MHz el retardo es en Multipos de 6.5uSegundos
    for(int i=0;i<micros;i++)
    {
        asm("NOP");
    }
    
}

void pinMode(char pin, char mode)
{
    switch(pin)
    {
        case 0:
            TRISAbits.RA4 = mode;
            break;
        case 1:
            TRISAbits.RA5 = mode;
            break;
        case 2:
            TRISCbits.RC0 = mode;
            break;
        case 3:
            TRISCbits.RC1 = mode;
            break;
        case 4:
            TRISCbits.RC2 = mode;
            break;
        case 5:
            TRISDbits.RD0 = mode;
            break;
        case 6:
            TRISDbits.RD1 = mode;
            break;
        case 7:
            TRISDbits.RD2 = mode;
            break;
        case 8:
            TRISDbits.RD3 = mode;
            break;
        case 9:
            TRISCbits.RC6 = mode;
            break;
        case 10:
            TRISCbits.RC7 = mode;
            break;
        case 11:
            TRISDbits.RD4 = mode;
            break;
        case 12:
            TRISDbits.RD5 = mode;
            break;
        case 13:
            TRISDbits.RD6 = mode;
            break;
        case 14:
            TRISDbits.RD7 = mode;
            break;
        case 15:
            TRISBbits.RB0 = mode;
            break;
        case 16:
            TRISBbits.RB1 = mode;
            break;
        case 17:
            TRISBbits.RB2 = mode;
            break;
        case 18:
            TRISBbits.RB3 = mode;
            break;
        case 19:
            TRISBbits.RB4 = mode;
            break;
        case 20:
            TRISBbits.RB5 = mode;
            break;
        case 21:
            TRISBbits.RB6 = mode;
            break;
        case 22:
            TRISBbits.RB7 = mode;
            break;
    }
}
void digitalWrite(char pin, char mode)
{
    switch(pin)
    {
       case 0:
           LATAbits.LA4 = mode;
            break;
        case 1:
            LATAbits.LA5 = mode;
            break;
        case 2:
            LATCbits.LC0 = mode;
            break;
        case 3:
            LATCbits.LC1 = mode;
            break;
        case 4:
            LATCbits.LC2 = mode;
            break;
        case 5:
            LATDbits.LD0 = mode;
            break;
        case 6:
            LATDbits.LD1 = mode;
            break;
        case 7:
            LATDbits.LD2 = mode;
            break;
        case 8:
            LATDbits.LD3 = mode;
            break;
        case 9:
            LATCbits.LC6 = mode;
            break;
        case 10:
            LATCbits.LC7 = mode;
            break;
        case 11:
            LATDbits.LD4 = mode;
            break;
        case 12:
            LATDbits.LD5 = mode;
            break;
        case 13:
            LATDbits.LD6 = mode;
            break;
        case 14:
            LATDbits.LD7 = mode;
            break;
        case 15:
            LATBbits.LB0 = mode;
            break;
        case 16:
            LATBbits.LB1 = mode;
            break;
        case 17:
            LATBbits.LB2 = mode;
            break;
        case 18:
            LATBbits.LB3 = mode;
            break;
        case 19:
            LATBbits.LB4 = mode;
            break;
        case 20:
            LATBbits.LB5 = mode;
            break;
        case 21:
            LATBbits.LB6 = mode;
            break;
        case 22:
            LATBbits.LB7 = mode;
            break;
    }
}
char digitalRead(char pin)
{
    switch(pin)
    {
       case 0:
           return PORTAbits.RA4;
            break;
        case 1:
            return PORTAbits.RA5;
            break;
        case 2:
            return PORTCbits.RC0;
            break;
        case 3:
            return PORTCbits.RC1;
            break;
        case 4:
            return PORTCbits.RC2;
            break;
        case 5:
            return PORTDbits.RD0;
            break;
        case 6:
            return PORTDbits.RD1;
            break;
        case 7:
            return PORTDbits.RD2;
            break;
        case 8:
            return PORTDbits.RD3;
            break;
        case 9:
            return PORTCbits.RC6;
            break;
        case 10:
            return PORTCbits.RC7;
            break;
        case 11:
            return PORTDbits.RD4;
            break;
        case 12:
            return PORTDbits.RD5;
            break;
        case 13:
            return PORTDbits.RD6;
            break;
        case 14:
            return PORTDbits.RD7;
            break;
        case 15:
            return PORTBbits.RB0;
            break;
        case 16:
            return PORTBbits.RB1;
            break;
        case 17:
            return PORTBbits.RB2;
            break;
        case 18:
            return PORTBbits.RB3;
            break;
        case 19:
            return PORTBbits.RB4;
            break;
        case 20:
            return PORTBbits.RB5;
            break;
        case 21:
            return PORTBbits.RB6;
            break;
        case 22:
            return PORTBbits.RB7;
            break;
    }
}
unsigned int analogRead(char pin)
{
    switch(pin)
    {
        case 0:
            ADCON0 = 0x03;
            while(ADCON0bits.GODONE != 0)
            {}
            return (ADRESH << 8)+ ADRESL;
            break;
        case 1:
            ADCON0 = 0x07;
            while(ADCON0bits.GODONE != 0)
            {}
            return (ADRESH << 8)+ ADRESL;
            break;
        case 2:
            ADCON0 = 0x0B;
            while(ADCON0bits.GODONE != 0)
            {}
            return (ADRESH << 8)+ ADRESL;
            break;
        case 3:
            ADCON0 = 0x0F;
            while(ADCON0bits.GODONE != 0)
            {}
            return (ADRESH << 8)+ ADRESL;
            break;
    }
}
void ADCConfig(void)
{
    TRISAbits.RA0 = 1;
    TRISAbits.RA1 = 1;
    TRISAbits.RA2 = 1;
    TRISAbits.RA3 = 1;
    ADCON0 = 0x01;  //Turning ON the A/D Converter
    ADCON1 = 0x0B;  //Setting the AN0,AN1, AN2, AN3 as Analog Inputs and GPIO others.
    ADCON2 = 0xAB;  //Left Justify, 12TAD, 64 TOSC

}
void ADCSetParam(char reg, char  cmd)
{
    switch(reg)
    {
        case 0:
            ADCON0 = cmd;
            break;
        case 1:
            ADCON1 = cmd;
            break;
        case 2:
            ADCON2 = cmd;
            break;
    }
}
void analogWrite(char pin,unsigned int value)
{
    switch(pin)
    {
        case 4:
            //TRISC2 = 0;
            if(value <1024)
            {
                value = ((float)value / 1023) * PWM_Max_Duty();
                CCP1CONbits.DC1B1 = value & 2;
                CCP1CONbits.DC1B0 = value & 1;
                CCPR1L = value >> 2;
            }
            break;
        case 3:
            //TRISC1 = 0;
            if(value <1024)
            {
                value = ((float)value / 1023) * PWM_Max_Duty();
                //DC2B1 = value & 2;
                CCP2CONbits.DC2B1 = value & 2;
                CCP2CONbits.DC2B0 = value & 1;
                CCPR2L = value >> 2;
            }
            break;
    }
}
void CCPConfig(void)
{
    PWM1_Init(1500);
    PWM2_Init(1500);
    PWM1_Start();
    PWM2_Start();
}
void TMR0Config(void)
{
//    //COnfiguracion para crear un desborde del registro del Timer 0 cada Milisegundo.
//    T0CON = 0x17;
//    INTCONbits.T0IE = 1;
//    //    T0CONbits.TMR0ON = 1;
//    //    T0CON = 0xC4;
//    //OpenTimer0(TIMER_INT_ON & T0_16BIT & T0_SOURCE_INT & T0_PS_1_256);
//    //WriteTimer0(0x0000); //OverLFow a 1 Segundo
//    TMR0L = 0x00;
//    TMR0H = 0x00;
//    INTCONbits.TMR0IF = 0;
//    ei();
}
double Time(void)
{
    return (millis * 1.4)+(TMR0 * 0.000021);
}

void __interrupt() TimerOverflow(void)
{
    if(INTCONbits.TMR0IF == 1)
    {
        /* Procedure */
        millis++;
        INTCONbits.TMR0IF = 0;
        TMR0L = 0x00;
        TMR0H = 0x00;
        //WriteTimer0(0x0000); //  Overflow a 1 segundo
    }
}
void TMR1Config(void)
{
    T1CON = 0xB6;
}
double PulseIn(char pin)
{
    double dtime;
    double now = Time();
    while(digitalRead(pin) == 1)
    {
        
    }
    dtime = Time() - now;
    return dtime;
}
double Frequency(void)
{
    double now, lastTime, dtime, dData, freq;
    int nowData, lastData;
    double HighFrqK = 1.175;
    lastTime = now;
    now = Time();
    T1CONbits.TMR1ON = 1;
    delay(100);
    T1CONbits.TMR1ON = 0;
    nowData = TMR1L;
    nowData += TMR1H * 256;
    dData = lastData - nowData;
    dtime = now - lastTime;
    lastData = nowData;
    freq = dData / dtime;
    if(freq < 0)
    {
        return -HighFrqK * freq;
    }
    else
    {
           return HighFrqK * freq; 
    }
}

void TMR2Config(void)
{

}
void TMR3Config(void)
{

}
void PORTSConfiguration(void)
{
    TRISA = 0x3F;
    TRISB = 0xFF;
    TRISC = 0xCF;
    TRISD = 0xFF;
    TRISEbits.RE0 = 1;
    TRISEbits.RE1 = 1;
    TRISEbits.RE2 = 1;
}
char PBRead(char pin)
{
    switch(pin)
    {
        case 0:
            return PORTEbits.RE0;
            break;
        case 1:
            return PORTEbits.RE1;
            break;
        case 2:
            return PORTEbits.RE2;
            break;
    }
}
int PWM_Max_Duty(void)
{
    return (_XTAL_FREQ / (freq * TMR2PRESCALE));
}
void PWM1_Init(long fre)
{
    PR2 = (_XTAL_FREQ / (fre * 4 * TMR2PRESCALE)) - 1;
    freq = fre;
}
void PWM2_Init(long fre)
{
    PR2 = (_XTAL_FREQ / (fre * 4 * TMR2PRESCALE)) - 1;
    freq = fre;
}
void PWM1_Start(void)
{
    CCP1M3 = 1;
    CCP1M2 = 1;
#if TMR2PRESCALE == 1
    T2CKPS0 = 0;
    T2CKPS1 = 0;
#elif TMR2PRESCALE == 4
    T2CKPS0 = 1;
    T2CKPS1 = 0;
#elif TMR2PRESCALE == 16
    T2CKPS0 = 1;
    T2CKPS1 = 1;
#endif
    TMR2ON = 1;
    
}
void PWM1_Stop(void)
{
    CCP1M3 = 0;
    CCP1M2 = 0;
}
void PWM2_Start(void)
{
    CCP2M3 = 1;
    CCP2M2 = 1;
#if TMR2PRESCALE == 1
    T2CKPS0 = 0;
    T2CKPS1 = 0;
#elif TMR2PRESCALE == 4
    T2CKPS0 = 1;
    T2CKPS1 = 0;
#elif TMR2PRESCALE == 16
    T2CKPS0 = 1;
    T2CKPS1 = 1;
#endif
    TMR2ON = 1;
    
}
void PWM2_Stop(void)
{
    CCP2M3 = 0;
    CCP2M2 = 0;
}
double rescale(double x, double in_min, double in_max, double out_min, double out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

char SerialBegin(const long int baudRate)
{
    unsigned long int x;
    SYNC = 0;
    SPEN = 1;
    TRISC6 = 1;
    TRISC7 = 1;
    CREN = 1;
    TXEN = 1;
    if(baudRate == 9600)
    {
        SPBRG = 38;
    }
    else if(baudRate == 2400)
    {
        SPBRG = 155;
    }
    else if(baudRate == 115200)
    {
        SPBRG = 3;
    }
    //x = (_XTAL_FREQ >> 13) && (0xFE);
    //x = ((_XTAL_FREQ / baudRate)/64) - 1;
    if(x > 255)
    {
        x = ((_XTAL_FREQ / baudRate)/16) - 1;
        BRGH = 1;
    }
//    if(x < 256)
//    {
//        SPBRG = x;
//        SYNC = 0;
//        SPEN = 1;
//        TRISC6 = 1;
//        TRISC7 = 1;
//        CREN = 1;
//        TXEN = 1;
//        return 1;
//    }
    return 0;
}
char TxRegisterFull(void)
{
    return TRMT;
}
char SerialErrors(void)
{
    if((FERR == 1) && (FERR || OERR)) //Framing Error
    {
        return 1;
    }
    else if((OERR == 1) && (FERR || OERR)) //OverRun Error
    {
        return 2;
    }
    else if(OERR && FERR) 
    {
        return 3;
    }
    else
    {
        return 0;
    }
}
char RxIdle(void)
{
    return RCIDL; // 1 ---> reciver Operation is in IDLE
}
void SerialWrite(char dataWrite)
{
    TXREG = dataWrite;
}

char SerialWriteText(char *dataText)
{
    unsigned int i;
    for(i=0;dataText[i]!='\0';i++)
    {
       SerialWrite(dataText[i]); 
    }
}
char SerialAvailable(void)
{
    return RCIF || TRMT;
}

char SerialRead(void)
{
    while(!RCIF);
    return RCREG;
}

void SerialReadText(char *Output, unsigned int lenght)
{
    unsigned int i;
    for(i=0;i<lenght;i++)
    {
        Output[i] = SerialRead();
    }
}


