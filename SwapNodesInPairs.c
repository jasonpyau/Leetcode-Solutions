/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;

ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* next = head->next;
    ListNode* nextPair = swapPairs(head->next->next);
    next->next = head;
    head->next = nextPair;
    return next;
}
