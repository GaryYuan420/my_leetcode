#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int titleToNumber(char * s){
	long res = 0;
	int i;
    if(s == NULL)
        return 0;
	for(i = 0; s[i] != '\0'; i++)
	{
		res = res * 26 + s[i] - 'A' + 1;
	}
	return res;
}
int main(int argc, char** argv){
	printf("titleToNumber %d\n", titleToNumber(argv[1]));
	return 0;
}