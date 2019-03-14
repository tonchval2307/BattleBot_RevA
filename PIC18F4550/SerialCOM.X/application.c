#include <xc.h>
#include "system.h"
#include "USART.h"

#define Relay 	11  //RD4 27
#define PWMR 	4   //RC2 17 PWM
#define PWML	3   //RC1 16 PWM
#define M1LP	5   //RD0 19
#define M1LN	6   //RD1 20
#define M2RP	7   //RD2 21
#define M2RN	8   //RD3 22

#define ENABLE 	1
#define DISABLE	0

const char pines[5] = {Relay, M1LP,M1LN,M2RP,M2RN};
const char data[5] = {'a','b','c','d','e'};
enum ESTADOS {forward,backward,left,right,stoped,plusvel, minusvel};
int estado;
int vel = 300;

void setup(void)
{   
    pinMode(PWMR,OUTPUT);
    RobotInit();
    WeaponInit();
    ComunicationInit();
    estado = stoped;
}

void loop(void)
{
    switch(estado)
    {
        case forward:
            adelante(vel);
            if(PBRead(0) == HIGH)
            {
                delay(50);
                if(PBRead(0) == HIGH)
                {
                    estado = backward;
                }
            }
            else if(PBRead(2) == HIGH)
            {
                delay(50);
                if(PBRead(2) == HIGH)
                {
                    estado = plusvel;
                }
            }
            else if(PBRead(2) == HIGH)
            {
                delay(50);
                if(PBRead(2) == HIGH)
                {
                    estado = minusvel;
                }
            }
            else
            {
                estado = forward;
            }
            break;
        case backward:
            atras(vel);
            if(PBRead(0) == HIGH)
            {
                delay(50);
                if(PBRead(0) == HIGH)
                {
                    estado = left;
                }
            }
            else if(PBRead(2) == HIGH)
            {
                delay(50);
                if(PBRead(2) == HIGH)
                {
                    estado = plusvel;
                }
            }
            else if(PBRead(2) == HIGH)
            {
                delay(50);
                if(PBRead(2) == HIGH)
                {
                    estado = minusvel;
                }
            }
            estado = backward;
            break;
        case left:
            izquierda(vel);
            if(PBRead(0) == HIGH)
            {
                delay(50);
                if(PBRead(0) == HIGH)
                {
                    estado = right;
                }
            }
            else if(PBRead(2) == HIGH)
            {
                delay(50);
                if(PBRead(2) == HIGH)
                {
                    estado = plusvel;
                }
            }
            else if(PBRead(2) == HIGH)
            {
                delay(50);
                if(PBRead(2) == HIGH)
                {
                    estado = minusvel;
                }
            }
            else
            {
                estado = left;
            }
            break;
        case right:
            derecha(vel);
            if(PBRead(0) == HIGH)
            {
                delay(50);
                if(PBRead(0) == HIGH)
                {
                    estado = stoped;
                }
            }
            else if(PBRead(2) == HIGH)
            {
                delay(50);
                if(PBRead(2) == HIGH)
                {
                    estado = plusvel;
                }
            }
            else if(PBRead(2) == HIGH)
            {
                delay(50);
                if(PBRead(2) == HIGH)
                {
                    estado = minusvel;
                }
            }
            else
            {
                estado = right;
            }
            break;
        case stoped:
            stop();
            if(PBRead(0) == HIGH)
            {
                delay(50);
                if(PBRead(0) == HIGH)
                {
                    estado = backward;
                }
            }
            else if(PBRead(2) == HIGH)
            {
                delay(50);
                if(PBRead(2) == HIGH)
                {
                    estado = plusvel;
                }
            }
            else if(PBRead(2) == HIGH)
            {
                delay(50);
                if(PBRead(2) == HIGH)
                {
                    estado = minusvel;
                }
            }
            else
            {
                estado = stoped;
            }
            break;
        case plusvel:
            vel = 300;
            if(PBRead(0) == HIGH)
            {
                delay(50);
                if(PBRead(0) == HIGH)
                {
                    estado = backward;
                }
            }
            else if(PBRead(2) == HIGH)
            {
                delay(50);
                if(PBRead(2) == HIGH)
                {
                    estado = plusvel;
                }
            }
            else if(PBRead(2) == HIGH)
            {
                delay(50);
                if(PBRead(2) == HIGH)
                {
                    estado = minusvel;
                }
            }
            estado = backward;
            break;
        case minusvel:
            vel = 150;
            if(PBRead(0) == HIGH)
            {
                delay(50);
                if(PBRead(0) == HIGH)
                {
                    estado = backward;
                }
            }
            else if(PBRead(2) == HIGH)
            {
                delay(50);
                if(PBRead(2) == HIGH)
                {
                    estado = plusvel;
                }
            }
            else if(PBRead(2) == HIGH)
            {
                delay(50);
                if(PBRead(2) == HIGH)
                {
                    estado = minusvel;
                }
            }
            else
            {
                estado = backward;
            }
            break;
            
    }
}

void adelante(int velocidad)
{
	//Motor 1 y 2 Izquierda (Left), haca adelante
	digitalWrite(M1LP,LOW);
	digitalWrite(M1LN,HIGH);
	//Motor 3 y 4 Derecha (Right), hacia adelante
	digitalWrite(M2RP,LOW);
	digitalWrite(M2RN,HIGH);
	//Configurar l a velocidad
	//analogWrite(PWML,velocidad);
	analogWrite(PWMR,velocidad);
}

void atras(int velocidad)
{
	digitalWrite(M1LP,HIGH);
	digitalWrite(M1LN,LOW);
	//Motor 3 y 4 Derecha (Right), hacia adelante
	digitalWrite(M2RP,HIGH);
	digitalWrite(M2RN,LOW);
	//Configurar l a velocidad
	//analogWrite(PWML,velocidad);
	analogWrite(PWMR,velocidad);
}

void izquierda(const int velocidad)
{
	digitalWrite(M1LP,LOW);
	digitalWrite(M1LN,HIGH);
	//Motor 3 y 4 Derecha (Right), hacia adelante
	digitalWrite(M2RP,HIGH);
	digitalWrite(M2RN,LOW);
	//Configurar l a velocidad
	//analogWrite(PWML,velocidad);
	analogWrite(PWMR,velocidad);
}

void derecha(const int velocidad)
{
	digitalWrite(M1LP,HIGH);
	digitalWrite(M1LN,LOW);
	//Motor 3 y 4 Derecha (Right), hacia adelante
	digitalWrite(M2RP,LOW);
	digitalWrite(M2RN,HIGH);
	//Configurar l a velocidad
	//analogWrite(PWML,velocidad);
	analogWrite(PWMR,velocidad);
}

void RobotInit(void)
{
	pinMode(M1LN,OUTPUT);
	pinMode(M1LP,OUTPUT);
	pinMode(M2RN,OUTPUT);
	pinMode(M2RP,OUTPUT);
}

void stop(void)
{
	digitalWrite(M1LP,LOW);
	digitalWrite(M1LN,LOW);
	//Motor 3 y 4 Derecha (Right), hacia adelante
	digitalWrite(M2RP,LOW);
	digitalWrite(M2RN,LOW);
	//Configurar l a velocidad
	analogWrite(PWML,0);
	analogWrite(PWMR,0); //ciclo de trabajo 0 - 255 (0 - LOW), (255 - HIGH)
}

void WeaponInit(void)
{
	pinMode(Relay,OUTPUT);
	digitalWrite(Relay,LOW);
}

void Attack(const int mode)
{
	if(mode == ENABLE)
	{
		digitalWrite(Relay,HIGH);
	}
	else if(mode == DISABLE)
	{
		digitalWrite(Relay,LOW);
	}
	else
	{
		digitalWrite(Relay,LOW);
	}
}

char BTData(void)
{
	return USART_ReceiveChar();
}

void ComunicationInit(void)
{
	USART_Init(38400);
	delay(100);
}

void testing(void)
{
    for(int i=0;i<5;i++)
    {
        digitalWrite(pines[i],HIGH);
        delay(150);
        digitalWrite(pines[i],LOW);
        delay(150);
    }
}

//void runit(void)
//{
//    if(1 == 1)//(!SerialAvailable())
//	{
//		switch(estado)
//		{
//			case forward:
//                if(BTData() == data[0])
//                {
//                    
//                }
//                else if(BTData() == data[1])
//                {
//                    
//                }
//                else if(BTData() == data[2])
//                {
//                    
//                }
//                else if(BTData() == data[3])
//                {
//                    
//                }
//                else if(BTData() == data[4])
//                {
//                    
//                }
//                else
//                {
//                    estado = forward;
//                }
//                break;
//            case backward:
//                if(BTData() == data[0])
//                {
//                    
//                }
//                else if(BTData() == data[1])
//                {
//                    
//                }
//                else if(BTData() == data[2])
//                {
//                    
//                }
//                else if(BTData() == data[3])
//                {
//                    
//                }
//                else if(BTData() == data[4])
//                {
//                    
//                }
//                else
//                {
//                    estado = backward;
//                }
//                break;
//            case left:
//                if(BTData() == data[0])
//                {
//                    
//                }
//                else if(BTData() == data[1])
//                {
//                    
//                }
//                else if(BTData() == data[2])
//                {
//                    
//                }
//                else if(BTData() == data[3])
//                {
//                    
//                }
//                else if(BTData() == data[4])
//                {
//                    
//                }
//                else
//                {
//                    estado = left;
//                }
//                break;
//            case right:
//                if(BTData() == data[0])
//                {
//                    
//                }
//                else if(BTData() == data[1])
//                {
//                    
//                }
//                else if(BTData() == data[2])
//                {
//                    
//                }
//                else if(BTData() == data[3])
//                {
//                    
//                }
//                else if(BTData() == data[4])
//                {
//                    
//                }
//                else
//                {
//                    estado = right;
//                }
//                break;
//            case stoped:
//                stop();
//                if(BTData() == data[0])
//                {
//                    
//                }
//                else if(BTData() == data[1])
//                {
//                    
//                }
//                else if(BTData() == data[2])
//                {
//                    
//                }
//                else if(BTData() == data[3])
//                {
//                    
//                }
//                else if(BTData() == data[4])
//                {
//                    
//                }
//                else
//                {
//                    estado = stoped;
//                }
//                break;
//		}
//	}
//	else
//	{
//		stop();
//		Attack(DISABLE);
//	}
//}