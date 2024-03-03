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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (size(head) == n) {
            ListNode* res = head->next;
            delete head;
            return res;
        }
        ListNode* turtle = head, *hare = head;
        for (int i = 0; i < n; ++i) {
            hare = hare->next;
        }
        while (hare && hare->next) {
            turtle = turtle->next, hare = hare->next;
        }
        ListNode* after = turtle->next->next;
        delete turtle->next;
        turtle->next = after;
        return head;
    }
private:
    int size(ListNode* head) {
        int res = 0;
        while (head) {
            ++res, head = head->next;
        }
        return res;
    }
};
