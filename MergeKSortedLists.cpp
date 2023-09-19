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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        ListNode *head, *curr;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) {
                pq.push(make_pair(lists[i]->val, i));
            }
        }
        if (pq.empty()) {
            return nullptr;
        }
        head = curr = nextNode(pq, lists);
        while (!pq.empty()) {
            curr->next = nextNode(pq, lists);
            curr = curr->next;
        }
        curr->next = nullptr;
        return head;
    }
private:
    ListNode* nextNode(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& pq, vector<ListNode*>& lists) {
        int i = pq.top().second;
        ListNode* res = lists[i];
        lists[i] = res->next;
        pq.pop();
        if (lists[i]) {
            pq.push(make_pair(lists[i]->val, i));
        }
        return res;
    }
};
