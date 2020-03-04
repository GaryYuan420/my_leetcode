char* intToRoman(int num) {
    char *thou[4] = {"", "M", "MM", "MMM"};
    char *hun[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char *ten[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char *bit[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    
    int thou_n, hun_n, ten_n, bit_n;
    char* out = (char *)malloc(16*sizeof(char));
    memset(out, 0, 16);
    thou_n = num /1000;
    hun_n = num % 1000 / 100;
    ten_n = num % 100 / 10;
    bit_n = num % 10;
    
    strcpy(out, thou[thou_n]);
    strcpy(out + strlen(out), hun[hun_n]);
    strcpy(out + strlen(out), ten[ten_n]);
    strcpy(out + strlen(out), bit[bit_n]);
    
    return out;
        
}