#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


void reverse(int* nums, int numsSize){
	int i;
	int temp;
	for(i = 0; i < numsSize/2; i++)
	{
		temp = nums[i];
		nums[i] = nums[numsSize - i - 1];
		nums[numsSize - i - 1] = temp;
	}
}

void rotate(int* nums, int numsSize, int k){
    if(numsSize == 0 || k == 0)
        return;
	k %= numsSize;
	reverse(nums, numsSize);
	reverse(nums, k);
	reverse(nums + k, numsSize - k);
}

int main(int argc, char** argv){
	int in[] = {1, 2, 3, 4 ,5 ,6};
	rotate(in, sizeof(in)/sizeof(in[0]), 2);
	return 0;
}