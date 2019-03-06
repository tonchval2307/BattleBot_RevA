#include <xc.h>
#include "system.h"

char control1 = 5;
char control2 = 6;
char control3 = 7;
char control4 = 8;
char PWM = 3;

char SensorIzq = 22;
char SensorDer = 21;

enum rotaciones{FWD,BWD,CW,CCW};
int estado;
void setup(void)
{
    /* Terminales de los Motores*/
	pinMode(control1,OUTPUT);
	pinMode(control2,OUTPUT);
	pinMode(control3,OUTPUT);
	pinMode(control4,OUTPUT);
	pinMode(PWM,OUTPUT);
    /* Sensores de Linea*/
    pinMode(SensorIzq,INPUT);
    pinMode(SensorDer,INPUT);
}

void loop(void)
{
    if((digitalRead(SensorIzq) == LOW) && (digitalRead(SensorDer) == LOW))
    {
        RobotAdelante(750);
    }
    else if((digitalRead(SensorIzq) == HIGH) && (digitalRead(SensorDer) == LOW))
    {
        RobotCW(500);
    }
    else if((digitalRead(SensorIzq) == LOW) && (digitalRead(SensorDer) == HIGH))
    {
        RobotCCW(500);
    }
    else
    {
        RobotAdelante(0);
    }
}

void M1Adelante(void)
{
	digitalWrite(control1,HIGH);
	digitalWrite(control2,LOW);
}

void M1Atras(void)
{
	digitalWrite(control1,LOW);
	digitalWrite(control2,HIGH);
}

void M2Adelante(void)
{
	digitalWrite(control3,HIGH);
	digitalWrite(control4,LOW);
}

void M2Atras(void)
{
	digitalWrite(control3,LOW);
	digitalWrite(control4,HIGH);
}

void RobotAdelante(int velocidad)
{
	M1Adelante();
	M2Adelante();
	analogWrite(PWM,velocidad);
}

void RobotAtras(int velocidad)
{
	M1Atras();
	M2Atras();
	analogWrite(PWM,velocidad);
}

void RobotCCW(int velocidad)
{
	M1Adelante();
	M2Atras();
	analogWrite(PWM,velocidad);
}

void RobotCW(int velocidad)
{
	M1Atras();
	M2Adelante();
	analogWrite(PWM,velocidad);
}

