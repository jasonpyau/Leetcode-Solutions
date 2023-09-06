/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct ListNode ListNode;

int get_len(ListNode* curr) {
    int len = 0;
    while (curr) {
        ++len;
        curr = curr->next;
    }
    return len;
}

ListNode** splitListToParts(ListNode* curr, int k, int* returnSize) {
    ListNode **ans = malloc(k*sizeof(ListNode*)), *next;
    int len = get_len(curr), i, j, num_add = len%k, n = len/k;
    bool add;
    for (i = 0; i < k; ++i) {
        ans[i] = curr;
        add = (i < num_add);
        for (j = 0; j < n+add-1; ++j) {
            curr = curr->next;
        }
        if (curr) {
            next = curr->next;
            curr->next = NULL;
            curr = next;
        }
    }
    *returnSize = k;
    return ans;
}
