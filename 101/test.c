#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool recur_mirror(struct TreeNode* left, struct TreeNode* right){
	bool ret;
	if(left == NULL && right == NULL)
		return true;
	if(left == NULL ^ right == NULL)
		return false;
	ret = recur_mirror(left->left, right->right);
	ret &= recur_mirror(left->right, right->left);
	ret &= (left->val == right->val) ? 1 : 0;
	
	return ret;
}

bool isSymmetric(struct TreeNode* root){
	bool ret;
	if(root->left == NULL && root->right == NULL)
		return true;
	if(root->left == NULL ^ root->right == NULL)
		return false;
	if(root->left->val != root->right->val)
		return false;
	ret = recur_mirror(root->left, root->right);
	return ret;
}

int main(void)
{
#if 0	
    struct TreeNode root, n10, n11, n20, n21, n22, n23;
    root.val = 1;
    n10.val = 2;
    n11.val = 2;
    n20.val = 3;
    n21.val = 4;
    n22.val = 4;
    n23.val = 3;
    root.left = &n10;
    root.right = &n11;
    n10.left = &n20;
    n10.right = &n21;
    n11.left = &n22;
    n11.right = &n23;
    n20.left = NULL;
    n20.right = NULL;
    n21.left = NULL;
    n21.right = NULL;
    n22.left = NULL;
    n22.right = NULL;
    n23.left = NULL;
    n23.right = NULL;
#else
    struct TreeNode root, n10, n11, n21, n22;
    root.val = 1;
    n10.val = 2;
    n11.val = 2;
    n21.val = 3;
    n22.val = 4;
    root.left = &n10;
    root.right = &n11;
    n10.left = NULL;
    n10.right = &n21;
    n11.left = &n22;
    n11.right = NULL;
    n21.left = NULL;
    n21.right = NULL;
    n22.left = NULL;
    n22.right = NULL;
#endif

    printf("%s\n", isSymmetric(&root) ? "true" : "false");
    return 0;
}