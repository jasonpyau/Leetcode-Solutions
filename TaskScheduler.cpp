class Solution {
public:
    // O(tasks.size()).
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26);
        for (char ch : tasks) {
            ++freq[ch-'A'];
        }
        set<pair<int, char>> s;
        for (int i = 0; i < 26; ++i) {
            if (freq[i]) {
                s.emplace(freq[i], i+'A');
            }
        }
        int ans = 0;
        while (!s.empty()) {
            vector<pair<int, char>> curr_cycle;
            for (auto it = s.rbegin(); it != s.rend() && curr_cycle.size() <= n; ++it) {
                curr_cycle.push_back(*it);
                ++ans;
            }
            for (pair<int, char>& t : curr_cycle) {
                if (t.first > 1) {
                    s.emplace(t.first-1, t.second);
                }
                s.erase(t);
            }
            if (!s.empty()) {
                ans += max(0, int(n-curr_cycle.size()+1));
            }
        }
        return ans;
    }
};
