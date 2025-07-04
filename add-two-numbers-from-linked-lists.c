/*
    LINK:
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

int main() {

    //create a linked list with the numbers 2, 4, 3
    ListNode *l1 = (ListNode *)malloc(sizeof(ListNode));
    l1->val = 2;
    l1->next = (ListNode *)malloc(sizeof(ListNode));
    l1->next->val = 4;
    l1->next->next = (ListNode *)malloc(sizeof(ListNode));
    l1->next->next->val = 3;

    //create a linked list with the numbers 5, 6, 4
    ListNode *l2 = (ListNode *)malloc(sizeof(ListNode));
    l2->val = 5;
    l2->next = (ListNode *)malloc(sizeof(ListNode));
    l2->next->val = 6;
    l2->next->next = (ListNode *)malloc(sizeof(ListNode));
    l2->next->next->val = 4;

    ListNode *result = addTwoNumbers(l1, l2);

    //[5,6] and [5,4,9]

    //print each node in the result linked list
    ListNode *current = result;
    while(current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }

    printf("\n");

    return 0;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy = {0, NULL};
    struct ListNode* current = &dummy;
    int carry = 0;
    
    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        carry = sum / 10;
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;
        current->next = newNode;
        current = newNode;
    }
    
    return dummy.next;
}