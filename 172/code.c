#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int trailingZeroes(int n){
	int count = 0;
	while(n > 0)
	{
		count += n/5;
		n /= 5;
	}
	return count;
}

int main(int argc, char** argv){
	printf("titleToNumber %d\n", trailingZeroes(atoi(argv[1])));
	return 0;
}