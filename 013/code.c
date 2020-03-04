int findrom(char c)
{
    int ret;
    switch (c)
    {
        case 'I':
            ret = 1;
            break;
        case 'V':
            ret = 5;
            break;
        case 'X':
            ret = 10;
            break;
        case 'L':
            ret = 50;
            break;
        case 'C':
            ret = 100;
            break;
        case 'D':
            ret = 500;
            break;
        case 'M':
            ret = 1000;
            break;
        default:
            break;
    }
    return ret;
}

int romanToInt(char* s) {
    int sum = 0;
    int cur, pre;
    while(*s != '\0')
    {
        cur = findrom(*s);
        pre = findrom(*(s-1));
        
        if(pre < cur)
            sum = sum - pre + cur - pre;
        else
            sum += cur;
        s++;
    }
    return sum;
    
}