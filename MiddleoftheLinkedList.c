/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* nodes[100];
    int numValues = 0;
    struct ListNode* current = head;
    while(current != NULL) {
        nodes[numValues++] = current;
        current = current->next;
    }
    return nodes[numValues/2];
}
