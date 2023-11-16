class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> s(nums.begin(), nums.end());
        int n = nums.size();
        string curr(n, '0');
        perm(curr, 0, n, s);
        return curr;
    }
private:
    bool perm(string& curr, int k, int n, unordered_set<string>& s) {
        if (n == k) {
            return (s.count(curr) == 0);
        }
        curr[k] = '0';
        if (perm(curr, k+1, n, s)) {
            return true;
        }
        curr[k] = '1';
        return perm(curr, k+1, n, s);
    }
};
