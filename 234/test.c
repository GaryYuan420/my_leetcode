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
 

bool isPalindrome(struct ListNode* head){
	struct ListNode *fast;
	struct ListNode *slow;
	fast = slow = head;
	bool ret = true;
	struct ListNode *prev = NULL;
	struct ListNode *next;
	
	struct ListNode *midhead;
	
	if(head == NULL || head->next == NULL)
		return true;
	
	while(fast->next != NULL && fast->next->next != NULL)
	{
		fast = fast->next->next;

		next = slow->next;
		slow->next = prev;
		prev = slow;
		slow = next;
	}
	
	if(fast->next == NULL)
	{
		midhead = prev;
		slow = slow->next;
	}
	else if(fast->next->next == NULL)
	{
		next = slow->next;
		slow->next = prev;
		prev = slow;
		slow = next;
		midhead = prev;
	}
	
	while(midhead != NULL && slow != NULL)
	{
		if(midhead->val != slow->val)
		{
			ret = false;
			break;
		}
		midhead = midhead->next;
		slow = slow->next;
	}
	return ret;
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
	struct ListNode L1, L2, L3, L4;
	L1.val = 1;
	L1.next = &L2;
	L2.val = 2;
	L2.next = &L3;
	L3.val = 1;
	L3.next = NULL;
	L4.val = 1;
	L4.next = NULL;
	printf_L(&L1);
	
	printf("%s\n", isPalindrome(&L1) ? "true" : "false");
    return 0;
}