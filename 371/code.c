#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int getSum(int a, int b){
	int res1, res2;
	while(b != 0)
	{
		res1 = a ^ b;
		res2 = (unsigned int)(a & b) << 1;
		a = res1;
		b = res2;
	}
	return a;
}

int main(int argc, char** argv){
	printf("getSum is %d\n", getSum(atoi(argv[1]), atoi(argv[2])));
	return 0;
}