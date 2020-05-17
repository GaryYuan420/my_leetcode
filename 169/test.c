#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

int compar(const void* a, const void *b)
{
	return *(int *)a - *(int*)b;
}

int majorityElement(int* nums, int numsSize){
	
	qsort(nums, numsSize, sizeof(int), compar);
    return *(nums + numsSize/2);
}

int main(void)
{
	int nums[5] = {1, 4, 3, 4, 4};
	printf("%d\n", majorityElement(nums, 5));
    return 0;
}