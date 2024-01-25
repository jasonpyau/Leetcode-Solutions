class djset {
public:
    djset(int n) {
        par = vector<int>(n);
        for (int i = 0; i < n; ++i) {
            par[i] = i;
        }
    }

    int find(int u) {
        if (par[u] == u) {
            return u;
        }
        return par[u] = find(par[u]);
    }

    void uni(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            // Use the min.
            if (u > v) {
                par[u] = v;
            } else {
                par[v] = u;
            }
        }
    }
private:
    vector<int> par;
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        djset dj(26);
        for (int i = 0; i < s1.size(); ++i) {
            dj.uni(s1[i]-'a', s2[i]-'a');
        }
        string ans;
        for (int i = 0; i < baseStr.size(); ++i) {
            ans.push_back(dj.find(baseStr[i]-'a')+'a');
        }
        return ans;
    }
};
