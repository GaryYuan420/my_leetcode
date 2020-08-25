#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int cmp(const void * a, const void * b)
{
	if(*(int*)a > *(int*)b)
		return 1;
	else if(*(int*)a < *(int*)b)
		return -1;
	else 
		return 0;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
	int* s1 = nums1, *s2 = nums2;
	int count = 0;
	qsort(nums1, nums1Size, sizeof(int), cmp);
	qsort(nums2, nums2Size, sizeof(int), cmp);
	while(s1 < nums1 + nums1Size && s2 < nums2 + nums2Size)
	{
		if(*s1 < *s2)
			s1++;
		else if(*s1 > *s2)
			s2++;
		else
		{
			nums1[count++] = *s1;
			s1++;
			s2++;
		}
	}
	*returnSize = count;
	return nums1;
}

int main(int argc, char** argv){
	int nu1[] = {-2147483648,1,2,3};
	int nu2[] = {1,-2147483648,-2147483648};
	int size;
	int *res = intersect(nu1, sizeof(nu1)/sizeof(nu1[0]), nu2, sizeof(nu2)/sizeof(nu2[0]), &size); 
	int i;
	for(i = 0; i < size; i++)
	{
		printf("%d\t", res[i]);
	}
	printf("\n");
	return 0;
}