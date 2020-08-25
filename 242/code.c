#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>


bool isAnagram(char * s, char * t){
	int i;
	char has[26] = {0};
	for(i = 0; s[i] != '\0'; i++)
	{
		has[s[i] - 'a']++;
	}
	for(i = 0; t[i] != '\0'; i++)
	{
		has[t[i] - 'a']--;
	}
	for(i = 0; i < 26; i++)
	{
		if(has[i] != 0)
			return false;
	}
	return true;
}

int main(int argc, char** argv){
	printf("isAnagram is %s\n", isAnagram(argv[1], argv[2]) ? "true" : "false");
	return 0;
}