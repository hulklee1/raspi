#include <stdio.h>
#include <string.h>
#include <wiringPi.h>
#include <pthread.h>

#define TRIG 1
#define ECHO 9

extern void TriggerEx();
extern void usisr();
extern double Dist();
extern double dist;
extern int t1;

void *usThread(void *a)
{
	while(1)
	{
		Dist(); delay(70);
	}
}

int main(int n, char *v[])
{
	pthread_t th;
	wiringPiSetup();
	pinMode(ECHO, INPUT);

	if((n > 1) && (strcmp(v[1],"-i") == 0))
	{
		pinMode(TRIG, PWM_OUTPUT);
		TriggerEx();
		wiringPiISR(ECHO, INT_EDGE_BOTH, usisr);
	}
	else
	{
		pinMode(TRIG, OUTPUT);
		pthread_create(&th, NULL, usThread, NULL);
	}
	
	while(1)
	{
		printf("Distance : %.2f  (%d)   \r", dist,t1);
	}
}
