/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head){
    struct ListNode* current = (head && head->next) ? head->next->next : NULL;
    struct ListNode* lastOdd = head;
    struct ListNode* firstEven = (head) ? head->next : NULL;
    struct ListNode* lastEven = firstEven;
    if (firstEven)
        firstEven->next = NULL;
    for (int i = 3; current != NULL; i++) {
        if (i % 2 == 0) {
            lastEven->next = current;
            lastEven = current;
            current = current->next;
            lastEven->next = NULL;
        } else if (i % 2 == 1) {
            lastOdd->next = current;
            lastOdd = current;
            current = current->next;
            lastOdd->next = firstEven;
        }
    }
    return head;
}
