#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define max(a, b) (a > b ? a : b)

int maxSubArray(int* nums, int numsSize){
	int sum = INT_MIN, res_max = INT_MIN;
	int i;
	for(i = 0;i < numsSize; i++)
	{
		if(sum < 0)
		{
			sum = nums[i];
			res_max = max(res_max, sum);
		}
		else
		{
			sum += nums[i];
			res_max = max(res_max, sum);
		}
	}
	
	return res_max;
}

int main(int argc, char *argv[])
{
	int num[9] = {-2,1,-3,4,-1,2,1,-5,4};
	printf("%d\n", maxSubArray(num, 9));
	return 0;
}