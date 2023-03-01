/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* createNode() {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = 0;
    node->next = NULL;
    return node;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int remainder = 0;
    struct ListNode* sum = createNode();
    struct ListNode* digit = sum;
    for (int i = 0; i < 101; i++) {
        int l1_val = (l1) ? l1->val : 0;
        int l2_val = (l2) ? l2->val : 0;
        int digit_sum = l1_val + l2_val + remainder;
        remainder = digit_sum / 10;
        digit->val = digit_sum % 10;
        l1 = (l1) ? l1->next : l1;
        l2 = (l2) ? l2->next : l2;
        if (!l1 && !l2 && !remainder)
            break;
        digit->next = createNode();
        digit = digit->next;
    } 
    return sum;
}
