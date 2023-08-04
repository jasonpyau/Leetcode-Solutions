/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* mid = head, *high = head;
        while (high && high->next) {
            mid = mid->next;
            high = high->next->next;
        }

        ListNode* prev2 = nullptr, *curr2 = mid->next, *next2;
        mid->next = nullptr;
        while (curr2) {
            next2 = curr2->next;
            curr2->next = prev2;
            prev2 = curr2;
            curr2 = next2;
        }

        ListNode* curr = head, *next;
        curr2 = prev2;
        while (curr && curr2) {
            next = curr->next;
            next2 = curr2->next;
            curr->next = curr2;
            curr2->next = next;
            curr = next;
            curr2 = next2;
        }
    }
};
