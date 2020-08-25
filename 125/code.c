#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define bool char
#define true 1
#define false 0


bool isPalindrome(char * s){
	int len = strlen(s);
	int i,j;
	if(s == NULL)
		return true;
	for(i = 0, j = len-1; i < j ;i++, j--)
	{
		while(!isalnum(s[i]) && i < len-1) i++;
		while(!isalnum(s[j]) && j > 0) j--;
		if(i >= j) return true;
		if(isupper(s[i])) s[i] = tolower(s[i]);
		if(isupper(s[j])) s[j] = tolower(s[j]);
		if(s[i] != s[j])
			return false;
	}
	return true;
}

int main(int argc, char** argv){
	bool x = isPalindrome(argv[1]);
	printf("input is %s\n",argv[1]);
	printf("%s\n",x ? "true":"false");
	return 0;
}