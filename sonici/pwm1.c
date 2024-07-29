#include <stdio.h>
#include <wiringPi.h>

#define wPi_Pin 22
int main(int n, char *s[])
{
	if(n<2) 
	{
		printf("usage : pwm1 [duty_rate(%%)] [[period]] \n\n");
		printf("        period = 10 ms if empty\n\n");
		return 1;
	}
	int dr, drh, drl, period = 10;
	sscanf(s[1],"%d",&dr);		// 70
	if(n>2)	sscanf(s[2],"%d",&period);	// 10
	drh = (dr * period) / 100;	//  7
	drl = period - drh;			//  3
	
	wiringPiSetup();  // wPi Pin numbering	
	pinMode(wPi_Pin, OUTPUT);
	
	for(int i=0;i<500;i++)
	{
		digitalWrite(wPi_Pin, 1);
		delay(drh);
		digitalWrite(wPi_Pin, 0);
		delay(drl);
	}	
	return 0;
}
