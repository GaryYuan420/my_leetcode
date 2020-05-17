#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void convert_cur(struct TreeNode* root, int *prev)
{
	if(root == NULL) return ;
	convert_cur(root->right, prev);
	root->val += *prev;
	*prev = root->val;
	convert_cur(root->left, prev);
	return;
	
}

struct TreeNode* convertBST(struct TreeNode* root){
	int prev = 0;
	convert_cur(root, &prev);
	return root;
}

int main(void)
{
	
	printf("%d\n", hammingDistance(1, 4));
	
    return 0;
}