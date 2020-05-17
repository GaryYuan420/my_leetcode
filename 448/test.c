#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
	int i, count = 0;
	int *res = NULL;
    if(numsSize == 0)
    {
        * returnSize = 0;
        return NULL;
    }
	for(i = 0; i < numsSize; i++)
	{
		if(nums[abs(nums[i]) - 1] > 0)
			nums[abs(nums[i]) - 1] *= -1;
	}
	
	for(i = 0; i < numsSize; i++)
	{
		if(nums[i] > 0)
		{
			count++;
		}
	}
	
	if(count == 0)
    {
        * returnSize = 0;
        return NULL;
    }

	res = malloc(count * sizeof(int));
	count = 0;
	for(i = 0; i < numsSize; i++)
	{
		if(nums[i] > 0)
		{
			count++;
			res[count - 1] = i + 1;
		}
	}

	*returnSize = count;
	return res;
}
int main(void)
{
	int nums[] = {4,3,2,7,8,2,3,1};
	int* res;
	int returnSize;
	int i;
	res = findDisappearedNumbers(nums, sizeof(nums)/sizeof(nums[0]), &returnSize);
	printf("%d\n", returnSize);
	for(i = 0; i < returnSize; i++)
	{
		printf("%d\t", res[i]);
	}
	printf("\n");
	
    return 0;
}