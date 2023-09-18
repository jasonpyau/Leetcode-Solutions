class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        for (int i = 0; i < mat.size(); ++i) {
            pq.push(make_pair(search(mat[i]), i));
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ans(k);
        for (int i = k-1; i >= 0; --i) {
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
private:
    // Returns number of 1s
    int search(vector<int>& row) {
        int low = 0, mid, high = row.size()-1;
        while (high >= low) {
            mid = (low+high)>>1;
            if (row[mid]) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return low;
    }
};
