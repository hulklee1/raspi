#include <wiringPi.h>
#include <stdio.h>

#define RED		8
#define GREEN	9
#define YELLOW  7
#define SW 		2

int mode = 0;
int intv = 0;	// 0 ~ 8 
int tim;		// delay time interval (ms)
int ps[40];  // pin number : 40, pin status : default 0

void Toggle(int pin)
{
	ps[pin] = !ps[pin];
	digitalWrite(pin,ps[pin]);
}

void gpioisr()
{
	if(++intv > 8) intv = 0;
	printf("GPIO interrupt occured...\n");
}

int main()
{
	wiringPiSetup();	// Pin number use case (wPi)
	pinMode(RED, OUTPUT); //  8,9,7 : OUT   2 : IN
	pinMode(GREEN, OUTPUT); 
	pinMode(YELLOW, OUTPUT); 
	pinMode(SW, INPUT); 
	wiringPiISR(SW, INT_EDGE_FALLING, gpioisr);  // registration GPIO ISR 

	for(;;) //while(1)
	{	
		tim = (9-intv)*100;
		if(mode)
		{
			Toggle(8);	delay(tim);
			Toggle(9);	delay(tim);
			Toggle(7);	delay(tim);
		}
		else
		{
			Toggle(7);	delay(tim);
			Toggle(9);	delay(tim);
			Toggle(8);	delay(tim);
		}
	}
	return 0;
}
