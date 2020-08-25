#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int** generate(int numRows, int* returnSize, int** returnColumnSizes){
	*returnSize = numRows;
	*returnColumnSizes = (int *)malloc(numRows * sizeof(int));
	int **res = (int **)malloc(numRows * sizeof(int*));
	int i, j;
	for(i = 0; i < numRows; i++)
	{
		(*returnColumnSizes)[i] = i+1;
		res[i] = (int *)malloc((i + 1) * sizeof(int));
		for(j = 0; j < i + 1; j++)
		{
			if(j == 0 || j == i)
			{
				res[i][j] = 1;
				continue;
			}
			res[i][j] = res[i-1][j-1] + res[i-1][j];
		}
	}
	return res;
}

int main(int argc, char** argv){
	int ** res;
	int returnSize,*returnColumnSizes;
	printf("nums %d\n", atoi(argv[1]));
	res = generate(atoi(argv[1]), &returnSize, &returnColumnSizes);
	
	return 0;
}