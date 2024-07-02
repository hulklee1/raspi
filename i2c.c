#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
int main()
{
	printf("\033[2J");  // clear screen
	int fd = wiringPiI2CSetup(0x48);
	
	while(1)
	{
		wiringPiI2CWrite(fd, 00);	wiringPiI2CRead(fd); // set & clear
		int x = (wiringPiI2CRead(fd) * 80) / 255;  // 0~255
		delay(100);

		wiringPiI2CWrite(fd, 01);
		wiringPiI2CRead(fd);
		int y = (wiringPiI2CRead(fd) * 24) / 255;
		delay(100);

		//wiringPiI2CWrite(fd, 03);
		//wiringPiI2CRead(fd);
		//int v3 = wiringPiI2CRead(fd);
		//delay(100);
		printf("\033[%d;%dH(%d,%d)", y, x, x, y);
		delay(200);
	}
	
	return 0;
}
