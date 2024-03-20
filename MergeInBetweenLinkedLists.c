/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2) {
    struct ListNode* curr = list1;
    for (int i = 0; i < a-1; ++i) {
        curr = curr->next;
    }
    struct ListNode* a_minus_1 = curr;
    curr = curr->next;
    for (int i = 0; i < b-a+1; ++i) {
        struct ListNode* next = curr->next;
        free(curr);
        curr = next;
    }
    a_minus_1->next = list2;
    struct ListNode* b_plus_1 = curr, *b_node = list2;
    while (b_node->next) {
        b_node = b_node->next;
    }
    b_node->next = b_plus_1;
    return list1;
}
