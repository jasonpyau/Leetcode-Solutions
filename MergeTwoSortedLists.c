/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (!list1)
        return list2;
    if (!list2)
        return list1;
    struct ListNode* curr1 = list1;
    struct ListNode* curr2 = list2;
    struct ListNode* head = NULL;
    if (list1->val >= list2->val) {
        head = list2;
        curr2 = curr2->next;
    } else {
        head = list1;
        curr1 = curr1->next;
    }
    struct ListNode* curr = head;
    while (curr1 && curr2) {
        if (curr1->val <= curr2->val) {
            curr->next = curr1;
            curr = curr->next;
            curr1 = curr1->next;
        } else {
            curr->next = curr2;
            curr = curr->next;
            curr2 = curr2->next;
        }
    }
    while (curr1) {
        curr->next = curr1;
        curr = curr->next;
        curr1 = curr1->next;
    }
    while (curr2) {
        curr->next = curr2;
        curr = curr->next;
        curr2 = curr2->next;
    }
    return head;
}
