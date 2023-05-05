class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        bool set1[51];
        bool set2[51];
        memset(set1, false, 51*sizeof(bool));
        memset(set2, false, 51*sizeof(bool));
        int len = A.size();
        vector<int> ans(len);
        int curr = 0;
        for (int i = 0; i < len; i++) {
            set1[A[i]] = true;
            set2[B[i]] = true;
            curr += (A[i] == B[i]) ? 1 : set1[B[i]] + set2[A[i]];
            ans[i] = curr;
        }
        return ans;
    }
};
