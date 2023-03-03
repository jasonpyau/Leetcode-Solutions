/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* current = head;
    struct ListNode* last_node = NULL;
    while (current != NULL) {
        if (current && last_node && current->val == last_node->val) {
            struct ListNode* removed = current;
            last_node->next = current->next;
            current = current->next;
            free(removed);
        } else {
            last_node = current;
            current = current->next;
        }
    }
    return head;
}
