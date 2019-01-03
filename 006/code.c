char* convert(char* s, int numRows) {
    int len = strlen(s);
    char* strout = (char *)malloc(len*sizeof(char)+1);
    int i, j, count = 0;
    int cylen = 2*numRows-2;
	if(numRows == 1)
		return s;
    for(i = 0; i < numRows; i++)
    {
        for(j = 0; j < len; j ++)
        {
            if(i == 0 && ((j*(2*numRows - 2)) < len))
            {
                strout[count++] = s[j*(2*numRows - 2)];
            }
            else if(i == (numRows - 1) && ((j*(2*numRows - 2) + numRows - 1) < len))
            {
                strout[count++] = s[j*(2*numRows - 2) + numRows - 1];
            }
            else
			{				
				if( ((j*(2*numRows - 2) + i) < len))
				{
					strout[count++] = s[j*(2*numRows - 2) + i];
				}
				if( (((j+1)*(2*numRows - 2) -i) < len))
				{
					strout[count++] = s[(j+1)*(2*numRows - 2) -i];
				}
			}
        }
    }
	strout[count] = '\0';
    return strout;
    
}