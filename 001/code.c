struct value
{
	int val;
	int index;
};

static int compare(const void *a, const void *b)
{
    return ((struct value *)a)->val -((struct value *)b)->val;
}

int* twoSum(int* nums, int numsize, int target)
{
	int i;
	struct value *obj = malloc(sizeof(struct value)*numsize);
	for(i = 0;i < numsize;i++)
	{
		obj[i].val = nums[i];
        obj[i].index = i;
    }
    qsort(obj, numsize, sizeof(*obj), compare);
    int count;
    int *result = malloc(2*sizeof(int));
    i = 0;
    int j = numsize - 1;
    int diff = 0;
    while(i < j)
    {
        diff = target - obj[i].val;
        if(diff < obj[j].val)
            j--;
        else if(diff > obj[j].val)
            i++;
        else 
        {
            result[0] = obj[i].index;
            result[1] = obj[j].index;
            break;
        }
    }
    return result;

}