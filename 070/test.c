#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>



int climbStairs_cal(int n, int* dp){
	if(*(dp + n) == 0)
	{
		*(dp + n) = climbStairs_cal(n-1, dp) + climbStairs_cal(n-2, dp);
	}
	return *(dp + n);
}

int climbStairs(int n){
	int *dp;
	int res;
	
	if(n == 1)
		return 1;
	if(n == 2)
		return 2;
	
	dp = malloc((n+1) * sizeof(int));
	memset(dp, 0, (n+1) * sizeof(int));
	dp[1] = 1;
	dp[2] = 2;
	res = climbStairs_cal(n, dp);
	free(dp);
	return res;
}

int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);
	printf("%d\n", climbStairs(n));
	return 0;
}