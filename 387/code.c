#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int firstUniqChar(char * s){
	int cha[26] = {0};
	int i, index = -1;
	int len = strlen(s);
	for(i = 0; i < len; i++)
	{
		cha[s[i] - 'a']++;
	}
	for(i = 0; i < len; i++)
	{
		if(cha[s[i] - 'a'] == 1)
		{
			index = i;
			break;
		}
	}
	return index;

}

int main(int argc, char** argv){
	int index = firstUniqChar(argv[1]);
	printf("firstUniqChar is %s %c %d\n",argv[1], argv[1][index], index);
	return 0;
}