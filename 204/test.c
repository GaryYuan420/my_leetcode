#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>

bool isprim(int n)
{
	int i;
	for(i = 2; i < sqrt(n); i++)
	{
		if(n % i == 0)
			return 0;
	}
	return 1;
}
//0 is prim
int countPrimes(int n){
	int i;
	int j;
	int count = 0;
	char *p = malloc(n * sizeof(char));
	memset(p, 0, n * sizeof(char));
	for(i = 2; i < n; i++)
	{
		if(!p[i])
		{
			if(isprim(i))
			{
				for(j = 2 * i; j < n; j = j + i)
				{
					p[j] = 1;
				}
			}
		}
	}
	for(i = 2; i < n; i++)
	{
		if(!p[i])
			count++;
	}
	free(p);
	return count;
}

int main(int argc, char ** argv)
{
	int nums = atoi(argv[1]);
	printf("countPrimes %d\n", countPrimes(nums));
    return 0;
}