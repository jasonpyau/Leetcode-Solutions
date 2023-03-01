/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define MAX_LEN 500
struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode* nodes[MAX_LEN];
    struct ListNode* current = head;
    int i = 0;
    for (; i < MAX_LEN && current != NULL; i++) {
        nodes[i] = current;
        current = current->next;
    }
    if (i == 0 || i == 1)
        return head;
    // Connect old tail with old head
    nodes[i-1]->next = nodes[0];
    // Get the next node after k rotations
    struct ListNode* new_head = nodes[i-k%i-1]->next;
    // Have the node after k rotations point to NULL
    nodes[i-k%i-1]->next = NULL;
    return new_head;
}
