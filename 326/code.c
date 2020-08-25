#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

bool isPowerOfThree(int n){
	if(n < 1)
		return false;
	double res = log10(n) / log10(3);
	return res == floor(res);
}

int main(int argc, char** argv){
	printf("isPowerOfThree is %s\n", isPowerOfThree(atoi(argv[1])) ? "true" : "false");
	return 0;
}