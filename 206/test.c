#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList1(struct ListNode* head){
	static struct ListNode *p;
	if(head == NULL || head->next == NULL) return head;
	p = reverseList1(head->next);
	head->next->next = head;
	head->next = NULL;
	return p;
}

struct ListNode* reverseList(struct ListNode* head){
	struct ListNode *next;
	struct ListNode *prev = NULL;
	while(head != NULL)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	return prev;
}


void printf_L(struct ListNode* head)
{
	while(head != NULL)
	{
		printf("%d\t", head->val);
		head = head->next;
	}
	printf("\n");
}


int main(void)
{
	struct ListNode L1, L2, L3;
	struct ListNode *resL;
	L1.val = 1;
	L1.next = &L2;
	L2.val = 2;
	L2.next = &L3;
	L3.val = 3;
	L3.next = NULL;
	
	printf_L(&L1);
	
	resL = reverseList(&L1);
	
	printf_L(resL);
    return 0;
}