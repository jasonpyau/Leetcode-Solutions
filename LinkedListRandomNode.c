/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct {
    int length;
    struct ListNode* head;
} Solution;

Solution* solutionCreate(struct ListNode* head) {
    srand(time(NULL));
    Solution* obj = (Solution*)malloc(sizeof(Solution));
    struct ListNode* current = head;
    int length;
    for (length = 0; current != NULL; length++)
        current = current->next;
    obj->length = length;
    obj->head = head;
    return obj;
}

int solutionGetRandom(Solution* obj) {
    int randIndex = rand()%(obj->length);
    struct ListNode* current = obj->head;
    for (int i = 0; i < randIndex && current != NULL; i++)
        current = current->next;
    return current->val;
}

void solutionFree(Solution* obj) {
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);
 
 * solutionFree(obj);
*/
