int lengthOfLongestSubstring(char* s) {
    int offset[128];
    int len = 0;
    int maxlen = 0;
    int index = 0;
    memset(offset, -1, sizeof(offset));

    while(*s != '\0')
    {
        if(offset[*s] == -1)
        {
            len++;
        }
        else
        {
            if(index - offset[*s] > len)
                len++;
            else
                len = index - offset[*s];
        }
        if(len > maxlen)
        {

            maxlen = len;
        }
        
        offset[*s++] = index++;
        printf("%d", len);
    }
    return maxlen;
    
}