/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* nextNonDupe(struct ListNode* curr) {
    int val = curr->val;
    while (curr && curr->val == val)
        curr = curr->next;
    return curr;
}

struct ListNode* deleteDuplicates(struct ListNode* head) {
    while (head && head->next && head->val == head->next->val)
        head = nextNonDupe(head);
    struct ListNode* curr = head;
    while (curr) {
        struct ListNode* prev = curr;
        curr = curr->next;
        while (curr && curr->next && curr->val == curr->next->val)
            curr = nextNonDupe(curr);
        prev->next = curr;
    }
    return head;
}
