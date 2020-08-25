#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode* node) {
	while(node != NULL && node->next != NULL)
	{
		node->val = node->next->val;
		if(node->next->next == NULL)
		{
			node->next=NULL;
		}
		else
			node = node->next;
	}
	return;
}

int main(int argc, char** argv){
	struct ListNode l1, l2, l3;
	l1.val = 1;
	l1.next = &l2;
	l2.val = 2;
	l2.next = &l3;
	l3.val = 3;
	l3.next = NULL;
	deleteNode(&l2);
	return 0;
}