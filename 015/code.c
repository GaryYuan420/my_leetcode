#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compar(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int** threeSum(int* nums, int numsSize, int* returnSize) {
    int** result;
    int loop, loop_in;
    int* head;
    int* tail;
    int target;
    *returnSize  = 0;
    result = (int **)malloc(5000*sizeof(int *));
    //*result = (int *)malloc(3*sizeof(int));
    for(loop = 0;loop < numsSize;loop++)
    {
        printf("%d ",nums[loop]);
    }
    printf("\n");
    qsort(nums, numsSize, sizeof(nums[0]),compar);
    printf("numsSize is %d\n",numsSize);
    for(loop = 0;loop < numsSize;loop++)
    {
        printf("%d ",nums[loop]);
    }
    printf("\n");
    for(loop = 0;loop < numsSize; loop++)
    {
        if(loop != 0 && nums[loop] == nums[loop - 1])
            continue;
        target = -nums[loop];
        head = nums+loop + 1;
        tail = nums + numsSize - 1;

        for(loop_in = 0;head < tail; loop_in++)
        {
            
            if(target == (*(head) + *(tail)))
            {
                printf("target is %d, head is %d, tail is %d,returnSize is %d,result is %d\n",target, *(head), *(tail), *returnSize,(*(head) + *(tail)));
                *(result+*returnSize) = (int *)malloc(3*sizeof(int));
                *(*(result+*returnSize)+0) = nums[loop];
                *(*(result+*returnSize)+1) = *(head);
                *(*(result+*returnSize)+2) = *(tail);
                (*returnSize)++;
                head++;
                tail--;
                while(*head == *(head-1))
                    head++;
                while(*tail == *(tail+1))
                    tail--;
            }
            else if(target > *(head) + *(tail))
            {
                head++;
                while(*head == *(head-1))
                    head++;
            }
            else if(target < *(head) + *(tail))
            {
                tail--;
                while(*tail == *(tail+1))
                    tail--;
            }
                
        }
    }
    return result;

}


int main(void)
{
    int array[7] = {0,-4,-1,-4,-2,-3,2}; 
    int **out;
    int ret_size;
    int loop, loop1;
    out = threeSum(array, 7, &ret_size);
    printf("ret_size is %d \n",ret_size);
    for(loop = 0;loop < ret_size;loop++)
    {
        for(loop1 = 0;loop1 < 3;loop1++)
        {
            printf("%d ",out[loop][loop1]);
            
        }
        printf("\n");
    }
    
    return 0;
}