#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
int main()
{
	int fd = wiringPiI2CSetup(0x48);
	
	while(1)
	{
		wiringPiI2CWrite(fd, 00);
		wiringPiI2CRead(fd);
		int v1 = wiringPiI2CRead(fd);
		delay(100);

		wiringPiI2CWrite(fd, 01);
		wiringPiI2CRead(fd);
		int v2 = wiringPiI2CRead(fd);
		delay(100);

		wiringPiI2CWrite(fd, 03);
		wiringPiI2CRead(fd);
		int v3 = wiringPiI2CRead(fd);
		delay(100);
		
		printf("ADC values : %d   %d   %d\n", v1, v2, v3);
	}
	
	return 0;
}
