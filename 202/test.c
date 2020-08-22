#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

int getnext(int n){
	int res = 0;
	int temp;
	while(n > 0)
	{
		temp = n % 10;
		res += temp * temp;
		n = n / 10;
	}
	
	return res;
}

bool isHappy(int n){
	int slow = n;
	int fast = getnext(getnext(n));
	if(n <= 0)
		return false;
	while((fast != 1) &&( fast != slow))
	{
		slow = getnext(slow);
		fast = getnext(getnext(fast));
	}
	
	return (fast == 1);
}

int main(int argc, char ** argv)
{
	int nums = atoi(argv[1]);
	printf("isHappy %s\n", isHappy(nums) ? "true" : "false");
    return 0;
}