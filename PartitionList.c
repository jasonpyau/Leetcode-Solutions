/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
ListNode* partition(ListNode* head, int x) {
    ListNode* less_head = NULL;
    ListNode* less_curr = NULL;
    ListNode* greater_head = NULL;
    ListNode* greater_curr = NULL;
    ListNode* curr = head;
    while (curr) {
        ListNode* next = curr->next;
        if (curr->val >= x) {
            if (!greater_head) {
                greater_head = curr;
            } else {
                greater_curr->next = curr;
            }
            greater_curr = curr;
        } else {
            if (!less_head) {
                less_head = curr;
            } else {
                less_curr->next = curr;
            }
            less_curr = curr;
        }
        curr = next;
    }
    if (less_curr) {
        less_curr->next = greater_head;
    }
    if (greater_curr) {
        greater_curr->next = NULL;
    }
    return (less_head) ? less_head : greater_head;
}
