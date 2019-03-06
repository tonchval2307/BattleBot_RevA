//#include "system.h"
//#include <xc.h>
//
//enum comunicacion {inicio, enviar, recibir};
//int estado;
//
//char vectorIn[5];
//char vectorOut[5];
//unsigned int buffer = 5;
//unsigned int PWMMSB = 0;
//unsigned int PWMLSB = 0;
//unsigned int PWM = 0;
//
//unsigned int ADCMSB = 0;
//unsigned int ADCLSB = 0;
//unsigned int ADC = 0;
//
//// vectorIn/Out = { <SYNC> , <OPERATOR> , <pin> , <Data LSB> , <Data MSB> }
// 
//void setupComunication(void)
//{
//    estado = inicio;
//    SerialBegin(9600);
//}
//
//void ComunicationProcess(void)
//{
//    if(SerialAvailable())
//    {
//        switch(estado)
//        {
//            case inicio:
//                SerialWrite(0x01);
//                estado = recibir;
//                break;
//            case enviar:
//                for(int i=0;i<buffer;i++)
//                {
//                    SerialWrite(vectorOut[i]);
//                }
//                estado = recibir;
//                break;
//            case recibir:
//                for(int i=0;i<buffer;i++)
//                {
//                    vectorIn[i] = SerialRead();
//                }
//                switch(vectorIn[1])
//                {
//                    case 2: //pinMode()
//                        pinMode(vectorIn[2],vectorIn[3]);
//                        break;
//                    case 3: //digitalWrite()
//                        digitalWrite(vectorIn[2],vectorIn[3]);
//                        break;
//                    case 4: //digitalRead()
//                        vectorOut[3] = digitalRead(vectorIn[2]);
//                        break;
//                    case 5: //analogWrite()
//                        PWMMSB = vectorIn[4];
//                        PWMLSB = vectorIn[3];
//                        PWM = (256 * PWMMSB) + PWMLSB;
//                        if(PWM >= 1000)
//                        {
//                            PWM = 1000;
//                        }
//                        analogWrite(vectorIn[2],PWM);                         
//                        break;
//                    case 6: //analogRead()
//                        ADC = analogRead(vectorIn[2]);
//                        ADCMSB = ADC / 256;
//                        ADCLSB = ADC - (ADCMSB * 256);
//                        vectorOut[4] = ADCMSB;
//                        vectorOut[3] = ADCLSB;
//                        break;
//                }
//                estado = enviar;
//                break;
//        }
//    }
//}

