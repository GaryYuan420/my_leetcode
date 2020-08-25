#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int cmp(const void *p1, const void *p2)
{
   return *(int*)p1 - *(int*)p2;
}

bool containsDuplicate(int* nums, int numsSize){
	int i;
	if(numsSize < 2)
		return false;
	qsort(nums, numsSize, sizeof(int), cmp);
	for(i = 0;i < numsSize - 1; i++)
	{
		if(nums[i] == nums[i+1])
			return true;
	}
	return false;
}
int main(int argc, char** argv){
	int in[] = {1,1};
	printf("containsDuplicate is %s\n", containsDuplicate(in, sizeof(in)/sizeof(in[0])) ? "true" : "false");
	return 0;
}