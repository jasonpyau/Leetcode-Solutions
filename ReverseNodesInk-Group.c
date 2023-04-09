/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode node;

int llistlen(node* head) {
    int len = 0;
    node* curr = head;
    for (; curr != NULL; len++, curr = curr->next);
    return len;
}

void reverseGroup(node* lastTail, node* head, node** returnHead, node** returnTail, node** returnNextHead, int k) {
    *returnTail = head;
    node* curr = head;
    node* last = lastTail;
    for (int i = 0; i < k; i++) {
        node* next = curr->next;
        curr->next = last;
        last = curr;
        curr = next;
    }
    *returnHead = last;
    if (lastTail)
        lastTail->next = last;
    *returnNextHead = curr;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    int len = llistlen(head), i = 0;
    int n = len/k;
    node* returnHead = NULL;
    node* tail = NULL;
    node* nextHead = NULL;
    if (n >= 1) {
        reverseGroup(NULL, head, &returnHead, &tail, &nextHead, k);
        i++;
    } else {
        return head;
    }
    node* placeholder = NULL;
    for (; i < n; i++) {
        reverseGroup(tail, nextHead, &placeholder, &tail, &nextHead, k);
    }
    tail->next = nextHead;
    return returnHead;
}
