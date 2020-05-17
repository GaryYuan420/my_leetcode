#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>

int hammingDistance(int x, int y){
    int z = x ^ y;
    int count = 0;
    while(z != 0)
    {
        if((z & 0x01) == 1)
            count++;
        z = z >> 1;
    }
    return count;
}

int main(void)
{

	printf("%d\n", hammingDistance(1, 4));
	
    return 0;
}