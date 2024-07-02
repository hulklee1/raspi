#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define wPi_Pin 22
int main(int n, char *s[])
{
	if(n<2) 
	{
		printf("usage : pwm2 [duty_rate(%%)] [[period]] \n\n");
		printf("        period = 10 ms if empty\n\n");
		return 1;
	}
	int dr, drh, period = 10;
	sscanf(s[1],"%d",&dr);		// 70
	if(n>2)	sscanf(s[2],"%d",&period);	// 10
	drh = (dr * period) / 100;	//   Mark time : 7
	//drl = period - drh;			//  Space time : 3

	wiringPiSetup();  // wPi Pin numbering
	pinMode(wPi_Pin, OUTPUT);
	
	pwmSetMode(PWM_MODE_MS);
	softPwmCreate(wPi_Pin, drh, period);
	//softPwmWrite(wPi_Pin, 70);
	
	delay(5000);
	softPwmStop(wPi_Pin);
	return 0;
}
