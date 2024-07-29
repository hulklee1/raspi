#include <stdio.h>
#include <wiringPi.h>

int Trig = 8;
int main(int argc, char **argv)
{
	if(argc > 1) sscanf(argv[1], "%d", &Trig);
	wiringPiSetup();
	pinMode(Trig, OUTPUT);
	while(1)
	{
		digitalWrite(Trig, 0);	
		delayMicroseconds(10);
		// Trigger signal
		digitalWrite(Trig, 1);
		delayMicroseconds(10);
		digitalWrite(Trig, 0);	
		delayMicroseconds(150); // wait
		delay(100);
	}
	return 0;
}

