class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        for (int i = 0; i < variables.size(); ++i) {
            int a = variables[i][0], b = variables[i][1];
            int c = variables[i][2], m = variables[i][3];
            if (pow(pow(a,b, 10), c, m) == target) {
                ans.push_back(i);
            }
        }
        return ans;
    }
private:
    int pow(int n, int e, int m) {
        if (!e) {
            return 1;
        } else if (e&1) {
            return pow(n, e-1, m)*n%m;
        } else {
            int sqt = pow(n, e>>1, m);
            return sqt*sqt%m;
        }
    }
};
