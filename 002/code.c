/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* p1, *p2, *p3, *p;
    int carry = 0;
    int sum = 0;
    struct ListNode* l3; 
    l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    p1 = l1;
    p2 = l2;
    p3 = l3;
    while(p1 != NULL || p2 != NULL)
    {

        if(p1 != NULL)
        {
            sum += p1->val;
            p1 = p1->next;

        }
        if(p2 != NULL)
        {
            sum += p2->val;
            p2 = p2->next;
        }
        p3->val = (sum + carry)% 10 ;
        carry = (sum + carry) / 10 ;
        sum = 0;
        if(p1 != NULL || p2 != NULL)
        {
            p =  (struct ListNode*)malloc(sizeof(struct ListNode));
            p3->next = p;
            p3 = p3->next;
        }
                
    }
    if(carry > 0)
    {
        p =  (struct ListNode*)malloc(sizeof(struct ListNode));
        p3->next = p;
        p3 = p3->next;
        p3->val = carry;
    }
    p3->next = NULL;
    return l3;
    
}