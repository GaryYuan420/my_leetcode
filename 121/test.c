#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>


int maxProfit(int* prices, int pricesSize){
	int min, profit;
	int i;
	min = prices[0];
	profit = 0;
	for(i = 1; i < pricesSize; i++)
	{
		if(prices[i] < min)
			min = prices[i];
		else
			profit = (prices[i] - min) > profit ? (prices[i] - min) : profit;
	}
	return profit;
}

int main(void)
{
	int num[6] = {7,1,5,3,6,4};

    printf("%d\n", maxProfit(num, 6));
    return 0;
}