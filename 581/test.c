#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>

#define ArraySize(a) sizeof(a)/sizeof(a[0])

int compar(const void *a, const void *b)
{
	return *((int*)a) - *((int*)b);
}

int findUnsortedSubarray(int* nums, int numsSize){
	int f_pos = 0, b_pos = 0, i, *tmp;
	tmp = malloc(numsSize * sizeof(int));
	memcpy(tmp, nums, numsSize*(sizeof(int)));
	qsort(tmp, numsSize, sizeof(int), compar);
	for(i = 0;i < numsSize; i++)
	{
		if(nums[i] != tmp[i])
		{
			f_pos = i;
			break;
		}
	}
	if(i == numsSize)
		return 0;
	for(i = numsSize - 1; i >= 0; i--)
	{
		if(nums[i] != tmp[i])
		{
			b_pos = i;
			break;
		}
	}
	return (b_pos - f_pos + 1);
	
}


int main(void)
{
	int nums[] = {1};
	printf("%d\n", findUnsortedSubarray(nums, ArraySize(nums)));
	
    return 0;
}