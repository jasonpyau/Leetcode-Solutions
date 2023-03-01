/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 #define MAX_LEN 30

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* nodes[MAX_LEN];
    struct ListNode* current = head;
    int i = 0;
    for (; i < MAX_LEN && current != NULL; i++) {
        nodes[i] = current;
        current = current->next;
    }
    if (i-n == 0) {
        struct ListNode* last = head;
        head = head->next;
        free(last);
    } else {
        nodes[i-n-1]->next = nodes[i-n]->next;
        free(nodes[i-n]);
    }
    return head;
}
