int maxArea(int* height, int heightSize) {
    int *font = height;
    int *back = height + heightSize - 1;
    int *min;
    int MaxArea = 0;
    int Area;
    int loop = heightSize;
    while(font != back)
    {
        if(*font < *back)
        {
            min = font++;
        }
        else 
        {
            min = back--;
        }
        Area = *min * (loop - 1);
        if(Area > MaxArea)
            MaxArea = Area;
        loop--;
        
    }
    return MaxArea;
}