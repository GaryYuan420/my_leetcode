#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>


int removeDuplicates(int* nums, int numsSize){
    int *fast, *slow;
    fast = slow = nums;
    while(fast < nums + numsSize)
    {
        while( fast < (nums + numsSize - 1) && *fast == *(fast + 1)  )
        {
            fast++;
        }
        *slow = *fast;
        slow++;
		fast++;
    }

    return (slow - nums);
}



int main(void)
{
	int nums[] = {1, 1, 1, 2, 2, 4};
	
	printf("%d\n", removeDuplicates(nums, 6));
	
    return 0;
}