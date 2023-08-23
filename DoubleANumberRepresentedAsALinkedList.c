/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;

int traverse(ListNode* curr) {
    int carry = 0;
    if (curr->next) {
        carry = traverse(curr->next);
    }
    int val = curr->val*2+carry;
    curr->val = val%10;
    return val/10;
}

ListNode* doubleIt(ListNode* head){
    int carry = traverse(head);
    if (carry) {
        ListNode* newHead = malloc(sizeof(ListNode));
        newHead->val = carry;
        newHead->next = head;
        head = newHead;
    }
    return head;
}
