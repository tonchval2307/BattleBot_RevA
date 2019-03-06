
#define Relay 	8
#define PWMR 	6
#define PWML	5
#define M1LP	2
#define M1LN	3
#define M2RP	4
#define M2RN	7

#define ENABLE 	1
#define DISABLE	0

const char data[5] = {'a','b','c','d','e'};
enum ESTADOS {forward,backward,left,right,stoped,test};
int estado;

void setup(void)
{
	ComunicationInit();
	RobotInit();
	WeaponInit();
	stop();
	Attack(DISABLE);
    estado = stoped;
}

void loop(void)
{
	if(Serial.available())
	{
		switch(estado)
		{
			case forward:
                if(BTData() == data[0])
                {
                    
                }
                else if(BTData() == data[1])
                {
                    
                }
                else if(BTData() == data[2])
                {
                    
                }
                else if(BTData() == data[3])
                {
                    
                }
                else if(BTData() == data[4])
                {
                    
                }
                else
                {
                    estado = forward;
                }
                break;
            case backward:
                if(BTData() == data[0])
                {
                    
                }
                else if(BTData() == data[1])
                {
                    
                }
                else if(BTData() == data[2])
                {
                    
                }
                else if(BTData() == data[3])
                {
                    
                }
                else if(BTData() == data[4])
                {
                    
                }
                else
                {
                    estado = backward;
                }
                break;
            case left:
                if(BTData() == data[0])
                {
                    
                }
                else if(BTData() == data[1])
                {
                    
                }
                else if(BTData() == data[2])
                {
                    
                }
                else if(BTData() == data[3])
                {
                    
                }
                else if(BTData() == data[4])
                {
                    
                }
                else
                {
                    estado = left;
                }
                break;
            case right:
                if(BTData() == data[0])
                {
                    
                }
                else if(BTData() == data[1])
                {
                    
                }
                else if(BTData() == data[2])
                {
                    
                }
                else if(BTData() == data[3])
                {
                    
                }
                else if(BTData() == data[4])
                {
                    
                }
                else
                {
                    estado = right;
                }
                break;
            case stoped:
                stop();
                if(BTData() == data[0])
                {
                    
                }
                else if(BTData() == data[1])
                {
                    
                }
                else if(BTData() == data[2])
                {
                    
                }
                else if(BTData() == data[3])
                {
                    
                }
                else if(BTData() == data[4])
                {
                    
                }
                else
                {
                    estado = stoped;
                }
                break;
            case test:
                testing();
                estado = test;
                break;
		}
	}
	else
	{
		stop();
		Attack(DISABLE);
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
	analogWrite(PWML,velocidad);
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
	analogWrite(PWML,velocidad);
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
	analogWrite(PWML,velocidad);
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
	analogWrite(PWML,velocidad);
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
	return Serial.read();
}

void ComunicationInit(void)
{
	Serial.begin(38400);
	delay(100);
}

void testing(void)
{
    for(int i=2;i<=8;i++)
    {
        digitalWrite(i,HIGH);
        delay(800);
        digitalWrite(i,LOW);
        delay(800);
    }
}
