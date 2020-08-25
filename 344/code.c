#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

void reverseString(char* s, int sSize){
	char * h = s;
	char * e = s + sSize - 1;
	char tmp;
	while(h < e)
	{
		tmp = *h;
		*h++ = *e;
		*e-- = tmp;
	}
	
}

int main(int argc, char** argv){
	reverseString(argv[1], strlen(argv[1]));
	printf("reverseString is %s\n", argv[1]);
	return 0;
}