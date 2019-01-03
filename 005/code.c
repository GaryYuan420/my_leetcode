static inline int min(int m, int n)
{
    return m<n?m:n;
}

char* longestPalindrome(char* s) {
    char s2[3000];
    int i;
    int arrlen;
    memset(s2,0,sizeof(s2));
    
    s2[0] = '$';
    for(i = 0;s[i]!='\0';i++)
    {
        s2[(i<<1)+1] = '#';
        s2[(i<<1) + 2] = s[i];        
    }
    s2[(i<<1)+1] = '#';
    arrlen = i*2+2;
    s2[arrlen] = '\0';
    int pos[3000];
    memset(pos,0,sizeof(pos));
    int limit = 0;;
    int cur = 0;
    int maxlen = 0;
    int maxpos = 0;
    for(i = 1;i < arrlen;i++)
    {
        if(i < limit)
        {
            pos[i] = min(pos[cur*2-i], limit - i);
        }
        else
            pos[i] = 1;
        while(s2[i+pos[i]] == s2[i-pos[i]])
        {
            pos[i]++;
        }

        if(pos[i]-1 > maxlen)
        {
            maxlen = pos[i]-1;
            maxpos = i;
        }
        if((i + pos[i]) > limit )
        {
            limit = i+pos[i];
            cur = i;
        }
 
    }

    char *palindrome = malloc(2000);
    memset(palindrome, 0, sizeof(palindrome));
    int j;
    for(j = 0,i = maxpos - maxlen;i<maxpos + maxlen;i++)
    {
        if(s2[i] != '#')
        {
            palindrome[j++] = s2[i];
        }
    }
    palindrome[j] = '\0';
    return palindrome;
    
    
    
    
}