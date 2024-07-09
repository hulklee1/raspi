#include <stdio.h>
#include <wiringPi.h>

#define SERVO_PIN 1  // wPi number (12)
int main(int argc, char **argv)
{
	wiringPiSetup();
	pinMode(SERVO_PIN, OUTPUT);
	
	for(int j = 0;j<10;j++)
	{
		for(int i=0;i<100;i++)
		{
			digitalWrite(SERVO_PIN, 1);
			delayMicroseconds(1000);
			digitalWrite(SERVO_PIN, 0);
			delayMicroseconds(19000);
		}
		for(int i=0;i<100;i++)
		{
			digitalWrite(SERVO_PIN, 1);
			delayMicroseconds(2000);
			digitalWrite(SERVO_PIN, 0);
			delayMicroseconds(18000);
		}
	}	
	return 0;
}

