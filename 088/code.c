#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	int *p, *p1, *p2;
	int i;
	p = nums1 + nums1Size - 1;
	p1 = nums1 + m - 1;
	p2 = nums2 + n - 1;
	while(p1 >= nums1 && p2 >= nums2)
	{
		if(*p1 > * p2)
		{
			*p-- = *p1--;
		}
		else
		{
			*p-- = *p2--;
		}
	}
	while(p2 >= nums2)
	{
		*p-- = *p2--;
	}
	return;
}

int main(int argc,char** argv)
{
	int i;
	int num1[] = {1,3,5,7,0,0,0};
	int num2[] = {2,4,6};
	merge(num1, 7, 4, num2, 3, 3);
	for(i = 0; i < 7; i++)
	{
		printf("%d\t",num1[i]);
	}
	printf("\n");
    return 0;
}