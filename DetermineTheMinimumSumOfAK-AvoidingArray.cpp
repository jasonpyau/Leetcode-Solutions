class Solution {
public:
    int minimumSum(int n, int k) {
        // Arithmetic series for O(1) time
        // Always in form of ((a_1+a_n)*n)/2
        int a_n = min(n, k>>1), ans = ((1+a_n)*a_n)>>1;
        a_n = n-a_n;
        ans += ((k+(k+a_n-1))*a_n)>>1;
        return ans;
    }
};
