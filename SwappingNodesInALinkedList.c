/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapNodes(struct ListNode* head, int k) {
    struct ListNode* curr = head;
    int len = 0;
    while (len < k-1) {
        curr = curr->next;
        len++;
    }
    struct ListNode* node_to_swap = curr;
    while (curr) {
        len++;
        curr = curr->next;
    }
    int i;
    if (k > (len>>1)) {
        i = 0;
        curr = head;
    } else {
        i = k-1;
        curr = node_to_swap;
    }
    for ( ; i < len-k; i++) {
        curr = curr->next;
    }
    int temp = curr->val;
    curr->val = node_to_swap->val;
    node_to_swap->val = temp;
    return head;
}
