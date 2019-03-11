/*
 * Pinout de placa BMCShield_Rev_A
 */
#define Relay 8
#define PWMR 6
#define PWML 5
#define M1LP 2
#define M1LN 3
#define M2RP 4
#define M2RN 7

#define ENABLE 1
#define DISABLE 0
#define WIFI 1
#define BT 0

int state = 0;
int vel = 255;
void setup() {
  // put your setup code here, to run once:
  ComunicationInit(BT);
  RobotInit();
}

void loop() {
  if(Serial.available())
  {
    state = Serial.read();
  }
  else
  {
    state = Serial.read();
  }
  switch(state)
  {
    case 'w':
      Serial.println("adelabnte");
      adelante(vel);
    break;
    case 's':
      Serial.println("atras");
      atras(vel);
    break;
    case 'a':
      Serial.println("izquierda");
      izquierda(vel);
    break;
    case 'd':
      Serial.println("derecha");
      derecha(vel);
    break;
    case 'o':
      vel = 255;
      Serial.print("Valocidad = ");
      Serial.println(vel);
      state = 0;
    break;
    case 'p':
      vel = 128;
      Serial.print("Valocidad = ");
      Serial.println(vel);
      state = 0;
    break;
    case 'l':
      Attack(ENABLE);
      Serial.println("Atacando");
    break;
    case 'k':
      Attack(DISABLE);
      Serial.println("No atacando");
    break;
    case 'n':
      detener();
    break;
  }
}

void Attack(char mode)
{
  switch(mode)
  {
    case 1:
      digitalWrite(Relay,HIGH);
    break;
    case 0:
      digitalWrite(Relay,LOW);
    break;
  }
}
void run_int(void)
{
   adelante(128);
  digitalWrite(Relay,HIGH);
  delay(1000);
  atras(128);
  digitalWrite(Relay,LOW);
  delay(1000);
}
void RobotInit(void)
{
  pinMode(Relay, OUTPUT);
  pinMode(PWMR,OUTPUT);
  pinMode(PWML,OUTPUT);
  pinMode(M1LP,OUTPUT);
  pinMode(M1LN,OUTPUT);
  pinMode(M2RP,OUTPUT);
  pinMode(M2RN,OUTPUT);

  digitalWrite(Relay,LOW);
  digitalWrite(M1LP,LOW);
  digitalWrite(M1LN,LOW);
  digitalWrite(M2RN,LOW);
  digitalWrite(M2RP,LOW);

  analogWrite(PWML,0);
  analogWrite(PWMR,0);
}

void adelante(int velocidad)
{
 digitalWrite(M1LP,HIGH);
 digitalWrite(M1LN,LOW);
 digitalWrite(M2RN,HIGH);
 digitalWrite(M2RP,LOW);
 analogWrite(PWML,velocidad); 
 analogWrite(PWMR,velocidad);
}

void atras(int velocidad)
{
   digitalWrite(M1LP,LOW);
   digitalWrite(M1LN,HIGH);
   digitalWrite(M2RN,LOW);
   digitalWrite(M2RP,HIGH);
   analogWrite(PWML,velocidad); 
   analogWrite(PWMR,velocidad);
}

void izquierda(int velocidad)
{
   digitalWrite(M1LP,LOW);
   digitalWrite(M1LN,HIGH);
   digitalWrite(M2RN,HIGH);
   digitalWrite(M2RP,LOW);
   analogWrite(PWML,velocidad); 
   analogWrite(PWMR,velocidad);
  
}

void derecha(int velocidad)
{
   digitalWrite(M1LP,HIGH);
   digitalWrite(M1LN,LOW);
   digitalWrite(M2RN,LOW);
   digitalWrite(M2RP,HIGH);
   analogWrite(PWML,velocidad); 
   analogWrite(PWMR,velocidad);
}

void detener(void)
{
   digitalWrite(M1LP,LOW);
   digitalWrite(M1LN,LOW);
   digitalWrite(M2RN,LOW);
   digitalWrite(M2RP,LOW);
   analogWrite(PWML,0); 
   analogWrite(PWMR,0);
}

void ComunicationInit(char mode)
{
  if(mode == WIFI)
  {
    
  }
  else if(mode == BT)
  {
    Serial.begin(9600);
  }
}

void try1(void)
{
  if(Serial.available() >0 )
  {
    state = Serial.read();
  }
  if(state == '0')
  {
    Serial.println("OFF");
    Attack(DISABLE);
    state = 0;
  }
  else if(state == '1')
  {
    Serial.println("ON");
    Attack(ENABLE);
    state = 0;
  }
}
