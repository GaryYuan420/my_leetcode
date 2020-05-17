#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

void moveZeroes(int* nums, int numsSize){
	int *fast, *slow;
	fast = slow = nums;
	
	if(numsSize == 0)
		return;
	
	while(fast < (nums+numsSize))
	{
		while(fast < (nums+numsSize) && *fast == 0)
		{
			fast++;
		}
		if(fast < (nums+numsSize))
		{
			*slow = *fast;
			slow++;
			fast++;
		}
	}
	while(slow < (nums+numsSize))
	{
		*slow++ = 0;
	}
	return;
}

void printA(int * nums, int numsSize)
{
	int i;
	for(i = 0; i < numsSize; i++)
	{
		printf("%d\t", *(nums+i));
	}
	printf("\n");
	return;
}

int main(void)
{
	int nums[] = {1,2,3,0,9,0,5};
	printA(nums, sizeof(nums)/sizeof(nums[0]));
	moveZeroes(nums, sizeof(nums)/sizeof(nums[0]));
	printA(nums, sizeof(nums)/sizeof(nums[0]));
    return 0;
}