#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char * countAndSay(int n){
	char *res, *temp;
	res = malloc(5000 * sizeof(char));
	temp = malloc(5000 * sizeof(char));
	int i, j;
	int count = 1;
	int pos = 0;
	int lenth;
	res[0] = '1';
	res[1] = '\0';
	lenth = strlen(res);
	for(i = 1; i < n; i++)
	{
		for(j = 1; j <= lenth; j++)
		{
			if(res[j] == res[j-1])
			{
				count++;
			}
			else
			{
				temp[pos++] = count + 0x30;
				temp[pos++] = res[j-1];
				count = 1;
			}
		}
		temp[pos] = '\0';
		pos = 0;
		count = 1;
		strcpy(res, temp);
		lenth = strlen(res);
	}
	
	return res;
}

int main(int argc,char** argv)
{
	printf("%s, %d\n",countAndSay(atoi(argv[1])), atoi(argv[1]));
    return 0;
}