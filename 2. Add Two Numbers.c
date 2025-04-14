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
    
    /* Add the first n digits, where n is the length of the shorter number */
    int sum = 0;
    while(l1->next != NULL && l2->next != NULL)
    {
        sum += l1->val + l2->val;
        element->val = sum % 10;
        sum /= 10;

        l1 = l1->next;
        l2 = l2->next;
        element->next = malloc(sizeof(struct ListNode));
        element = element->next;
    }
    sum += l1->val + l2->val;
    element->val = sum % 10;
    sum /= 10;

    /* Add the rest of l1 if it's longer */
    if(l1->next != NULL && l2->next == NULL)
    {
        l1 = l1->next;
        element->next = malloc(sizeof(struct ListNode));
        element = element->next;
        while (l1->next != NULL)
        {
            sum += l1->val;
            element->val = sum % 10;
            sum /= 10;

            l1 = l1->next;
            element->next = malloc(sizeof(struct ListNode));
            element = element->next;
        }
        sum += l1->val;
        element->val = sum % 10;
        sum /= 10;
    }
    /* Add the rest of l2 if it's longer */
    else if(l1->next == NULL && l2->next != NULL)
    {
        l2 = l2->next;
        element->next = malloc(sizeof(struct ListNode));
        element = element->next;
        while (l2->next != NULL)
        {
            sum += l2->val;
            element->val = sum % 10;
            sum /= 10;

            l2 = l2->next;
            element->next = malloc(sizeof(struct ListNode));
            element = element->next;
        }
        sum += l2->val;
        element->val = sum % 10;
        sum /= 10;
    }

    if(sum)
    {
        element->next = malloc(sizeof(struct ListNode));
        element = element->next;
        element->val = sum;
    }
    element->next = NULL;

    return head;
}
