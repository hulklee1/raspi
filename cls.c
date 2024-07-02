#include <stdio.h>
int main()
{
	int x = 10, y = 20;
	printf("\033[2J");
	while(1)
	{
		printf("\033[%d;%dH ", y, x); // [x;yH
	}
	return 0;
}
