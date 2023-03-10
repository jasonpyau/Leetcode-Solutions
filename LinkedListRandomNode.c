/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct {
    int length;
    int* values;
} Solution;

Solution* solutionCreate(struct ListNode* head) {
    Solution* obj = (Solution*)malloc(sizeof(Solution));
    int* values = (int*)calloc(10000, sizeof(int));
    struct ListNode* current = head;
    int length;
    for (length = 0; current != NULL; length++) {
        values[length] = current->val;
        current = current->next;
    }
    values = (int*)realloc(values, length*sizeof(int));
    obj->values = values;
    obj->length = length;
    srand(time(NULL));
    return obj;
}

int solutionGetRandom(Solution* obj) {
    int randIndex = (obj->length) ? rand()%(obj->length) : 0;
    return obj->values[randIndex];
}

void solutionFree(Solution* obj) {
    free(obj->values);
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);
 
 * solutionFree(obj);
*/
