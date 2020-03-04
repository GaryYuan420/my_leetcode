#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int i = 0, j = 0;
    char ComChar;
    int ComFlag = 1;
    char * ret = (char *)malloc(1000);
    memset(ret, 0, 1000);
    if(strsSize == 0)
        return ret;
    
    for(;;)
    {
        ComChar = strs[0][i];
        for(j = 0; j < strsSize; j++)
        {
            if(strs[j][i] == '\0' || strs[j][i] !=ComChar)
            {
                ComFlag = 0;
                break;
            }
        }
        if(ComFlag != 1)
            break;
        i++;
    }
    memcpy(ret, strs[0], i);
    return ret;
}


int main(void)
{
    char* strs[] = {"flower","flow","flight"}; 
    char *out;
    
    out = longestCommonPrefix(strs, 3);
    
    printf("%s\n", out);
    
    return 0;
}