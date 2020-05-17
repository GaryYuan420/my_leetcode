#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int pathSum_Cur(struct TreeNode* root, int target, int* arr, int depth)
{	
	int count = 0;
	int loop;
	int tmp = 0;
	if(root == NULL) return 0;
	arr[depth] = root->val;
	for(loop = 0; loop <= depth; loop++)
	{
		tmp += arr[depth - loop];
		if(tmp == target) 
		{
            count++;
        }	
	}
	count += pathSum_Cur(root->left, target, arr, depth + 1);
	count += pathSum_Cur(root->right, target, arr, depth + 1);
	
	return count;
}

int MaxDepth(struct TreeNode* root)
{
	if(root == NULL) return 0;
	int l, r;
	l = MaxDepth(root->left) + 1;
	r = MaxDepth(root->right) + 1;
	
	return l > r ? l : r;
}

int pathSum(struct TreeNode* root, int sum){
	int max_depth;
	int *array;
	max_depth = MaxDepth(root);
	array = malloc(max_depth * sizeof(int) );
	
	sum = pathSum_Cur(root, sum, array, 0);
	free(array);
	return sum;
}

int main(void)
{
	
    return 0;
}