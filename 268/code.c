#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>


int missingNumber(int* nums, int numsSize){
	int i;
	int miss = 0;
	for(i = 0; i < numsSize; i++)
	{
		miss ^= nums[i] ^ i;
	}
	miss ^= numsSize;
	return miss;
}

int main(int argc, char** argv){
	int in[] = {0,1,2,3,4,5,7};
	printf("missingNumber is %d\n", missingNumber(in, sizeof(in)/sizeof(in[0])));
	return 0;
}