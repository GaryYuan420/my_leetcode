#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define max(a,b) (a) > (b) ? (a) : (b)

int rob(int* nums, int numsSize){
    if(numsSize == 0)
        return 0;
    if(numsSize == 1)
        return nums[0];
    if(numsSize == 2)
        return max(nums[0],nums[1]);
    int *steal = malloc(sizeof(int)*numsSize);
	int i;
	steal[0] = nums[0];
	steal[1] = max(nums[0],nums[1]);
	for(i = 2; i < numsSize; i++)
	{
		steal[i] = max(steal[i-2]+nums[i], steal[i-1]);
	}
	
	return steal[numsSize - 1];
}
int main(void)
{
	int nums[14] = {82,217,170,215,153,55,185,55,185,232,69,131,130,102};
	printf("%d\n", rob(nums, 14));
    return 0;
}