/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;

// Returns new head of list
ListNode* reverse(ListNode* head, ListNode* node_after_right) {
    ListNode *prev = node_after_right, *curr = head, *next;
    while (curr != node_after_right) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode *curr = head, *node_before_left, *node_after_right;
    int i = 1;
    if (left > 1) {
        for (; i < left-1; ++i) {
            curr = curr->next;
        }
        node_before_left = curr;
    }
    for (; i <= right; ++i) {
        curr = curr->next;
    }
    node_after_right = curr;
    if (left == 1) {
        return reverse(head, node_after_right);
    } else {
        node_before_left->next = reverse(node_before_left->next, node_after_right);
        return head;
    }
}
