#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

char ** fizzBuzz(int n, int* returnSize){
	char **res = (char **)malloc(sizeof(char*) * n);
	int i;
	*returnSize = n;
	for(i = 0; i < n; i++)
	{
		if((i+1) % 15 == 0)
		{
			res[i] = malloc(sizeof(char) * 9);
			sprintf(res[i], "FizzBuzz");
		}
		else if((i+1) % 3 == 0)
		{
			res[i] = malloc(sizeof(char) * 5);
			sprintf(res[i], "Fizz");
		}
		else if((i+1) % 5 == 0)
		{
			res[i] = malloc(sizeof(char) * 5);
			sprintf(res[i], "Buzz");
		}
		else
		{
			res[i] = malloc(sizeof(char) * 11);
			sprintf(res[i], "%d", (i+1));
		}

	}
	return res;
	
}

int main(int argc, char** argv){
	int size;
	char ** res = fizzBuzz(atoi(argv[1]), &size);
	int i;
	for(i = 0; i < size; i++)
	{
		printf("fizzBuzz is %s\t\n",res[i]);
	}
	
	return 0;
}