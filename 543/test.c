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

#define Max(a, b) ((a) > (b) ? (a) : (b))

int cur_tree(struct TreeNode* root, int* max_d)
{
	int left_dep, right_dep, max_res;
	if(root == NULL) return 0;
	left_dep = cur_tree(root->left, max_d);
	right_dep = cur_tree(root->right, max_d);
	max_res = left_dep + right_dep;
	if(max_res > *max_d)
		*max_d = max_res;
	return Max(left_dep, right_dep)+1;
}


int diameterOfBinaryTree(struct TreeNode* root){
	int max_d = 0;
	(void)cur_tree(root, &max_d);
	return max_d;
}
int main(void)
{
	
	printf("%d\n", hammingDistance(1, 4));
	
    return 0;
}