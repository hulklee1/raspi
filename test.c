#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wiringPi.h>

#define wPin	29

char* GetToken(char* str, char c, int n) // str:대상문자열, c:구분자, n:요소번호
{   //00 & 11 & 22 & 33 & 44     value=123   &    button=submit1    &    button=submit2&button=submit
	int i, i1 = 0, i2 = 0, cnt = 0;
	char* ret = (char*)malloc(50);
	for(i=0; i<strlen(str); i++)
	{
		if(str[i] == c) 
		{
			cnt++;
			if(cnt == n) 
			{
				i1 = i;  // 구분자 위치
			}
			else if(cnt == n+1)
			{
				i2 = i; // 
				if(i1) i1++;
				strncpy(ret,str+i1,i2-i1);
				return ret;
			}
		}
	}
	if(cnt < n) return NULL;

	i2 = i;//strlen(str); // 
	if(i1) i1++;
	strncpy(ret,str+i1,i2-i1);
	return ret;
}

int main(int argc, char **argv)
{
	char *ra = getenv("REMOTE_ADDR");
	char *qs = getenv("QUERY_STRING");	
	char *qs1 = GetToken(qs, '&', 0);  // value=11

	printf("Content-type: text/html\n\n");
	printf("<html>\n\n"); 	 
	printf("<h1>CGI controlled LED ON...</h1>\n");
	printf("<p>Remote Address : %s</p>\n", ra);
	printf("<p>Query String   : %s</p>\n", qs);
	printf("<p>QS[0] : %s</p>", GetToken(qs, '&', 0));
	printf("<p>QS[0,0] : %s</p>", GetToken(qs1, '=', 0));	// value
	printf("<p>QS[0,1] : %s</p>", GetToken(qs1, '=', 1));	// 11
	printf("<p>QS[1] : %s</p>", GetToken(qs, '&', 1));
	printf("</html>\n\n"); 
	
	
	wiringPiSetup();
	pinMode(wPin, OUTPUT);
	digitalWrite(wPin, 1);
	return 0;
}

