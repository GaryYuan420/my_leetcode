#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define uint32_t unsigned int 

uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
	int tmp;
	int i;
	for(i = 0; i < 32; i++)
	{
		tmp = n % 2;
		n = n/2;
		res = res * 2 + tmp;
	}
	return res;
}

int main(int argc, char** argv){
	int in = atoi(argv[1]);
	int res = reverseBits(in);
	return 0;
}