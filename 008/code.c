int myAtoi(char* str) {
    int n = 0, sign = 0;
    while(*str == ' ' || *str == '\t')
    {
        str++;
    }
    
    if(*str == '+')
    {
        sign = 0;
        str++;
    }
    else if(*str == '-')
    {
        sign = 1;
        str++;
    }
    
    while(isdigit(*str))
    {
        if (sign) {
            if (-n < INT_MIN / 10 ||(-n ==  INT_MIN / 10 && ((*str - '0') >= 8))) {
                n = INT_MIN;
                break;
            }
        } else {
            if (n > INT_MAX  / 10||(n == INT_MAX  / 10 && ((*str - '0') >= 7) )) {
                n = INT_MAX;
                break;
            }
        }
        
        n = n * 10 + (*str++ - '0');
        
    }
    return sign ? -n : n;
    
}