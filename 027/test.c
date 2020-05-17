#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removeElement(int* nums, int numsSize, int val){
    int *fast, *slow;
    fast = slow = nums;
	if(numsSize == 0)
		return 0;
    while(fast < nums + numsSize)
    {
        while( fast < (nums + numsSize) && *fast == val  )
        {
            fast++;
        }
		if(fast >= (nums + numsSize)) break;
        *slow = *fast;
        slow++;
		fast++;
    }

    return (slow - nums);
}



int main(int argc, char *argv[])
{
	int nums[] = {3,2,2,3};
	printf("%d\n",removeElement(nums, 4, 3) );
	return 0;
}