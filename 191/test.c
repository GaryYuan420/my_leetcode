#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define uint32_t unsigned long

int hammingWeight(uint32_t n) {
    int i;
	int count = 0;
	for(i = 0; i < 32; i++)
	{
		if(n & 1)
			count++;
		n = n >> 1;
	}
	return count;
}

int main(int argc, char ** argv)
{
	uint32_t nums = atoi(argv[1]);
	printf("hammingWeight %d\n", hammingWeight(nums));
    return 0;
}