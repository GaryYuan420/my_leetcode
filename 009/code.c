static int reverse(int x)
{
    int n = 0;
    int ret = 0;
    while(x != 0)
    {
        n = x % 10;
        ret = ret * 10 + n;
        x /= 10;
    }
    return ret;
}
bool isPalindrome(int x) {
    int revx;
    if(x<0)
        return 0;
    else
        revx = reverse(x);
    return (x == revx) ? 1 : 0 ;
    
}