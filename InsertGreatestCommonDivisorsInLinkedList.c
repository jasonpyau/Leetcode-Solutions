/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;

int gcd(int a, int b) {
    int r = a%b;
    if (!r) {
        return b;
    }
    return gcd(b, r);
}

void insert(ListNode* curr) {
    ListNode* next = curr->next;
    if (!next) {
        return;
    }
    int val = gcd(curr->val, next->val);
    curr->next = malloc(sizeof(ListNode));
    curr->next->val = val;
    curr->next->next = next;
    insert(next);
}

ListNode* insertGreatestCommonDivisors(ListNode* head){
    insert(head);
    return head;
}
