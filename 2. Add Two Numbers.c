/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 #include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode* head = malloc(sizeof(struct ListNode));
    struct ListNode* element = head;
    
    int sum = 0;
    while(!(l1 == NULL && l2 == NULL))
    {
        if(l1 != NULL){
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2 != NULL){
            sum += l2->val;
            l2 = l2->next;
        }
        element->val = sum % 10;
        sum /= 10;

        if(l1 == NULL && l2 == NULL){
            if(sum)
            {
                element->next = malloc(sizeof(struct ListNode));
                element = element->next;
                element->val = sum;
            }
            element->next = NULL;
        }
        else{
            element->next = malloc(sizeof(struct ListNode));
            element = element->next;
        }
    }

    return head;
}
