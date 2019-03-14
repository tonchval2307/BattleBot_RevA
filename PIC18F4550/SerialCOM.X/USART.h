#ifndef USART_HEADER_FILE_H
#define	USART_HEADER_FILE_H

#define F_CPU 24000000
//#define Baud_value(baud_rate) (((float)(F_CPU)/(float)baud_rate)-1)
#define Baud_value (((float)(F_CPU)/(float)baud_rate)-1)

void USART_Init(long);
void USART_TransmitChar(char);
void USART_SendString(const char *);
void MSdelay(unsigned int val);
char USART_ReceiveChar(void);

#endif	/* USART_HEADER_FILE_H */

