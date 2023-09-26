class Solution {
public:
    int captureForts(vector<int>& forts) {
        int ans = 0;
        for (int i = 0, j = 0; j < forts.size(); ++j) {
            if (forts[j]) {
                if (forts[j] == -forts[i]) {
                    ans = max(ans, j-i-1);
                }
                i = j;
            }
        }
        return ans;
    }
};
