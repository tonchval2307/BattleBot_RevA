#include <xc.h>
#include "system.h"

const int analog = 0;
const int pwm = 4;
int data;
int data_out;

void setup()
{
	pinMode(analog,INPUT);
	pinMode(pwm,OUTPUT);
}

void loop(void)
{
	data = analogRead(analog);
	data_out = rescale(data,0,1023,0,650);
	analogWrite(pwm,data_out);
	delay(100);
}