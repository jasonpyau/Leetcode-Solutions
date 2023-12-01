// Classic counting problem with minimum/maximum restrictions.
// a+b+c = n, a,b,c <= limit and are the 3 slots to fill.
// In total we have nCr(n+3-1, 3-1), ignoring the limit. (Star-and-bars)
// Then, exclude where exactly one slot has over limit candies.
// Then, exclude where exactly two slots have over limit candies.
// Then, exclude where exactly three slots have over limit candies.
class Solution {
public:
    // O(1), since we always have only two "bars".
    long long distributeCandies(int n, int limit) {
        // nCr(10^6+2, 2) < LLONG_MAX.
        long long ans = nCr(n+2, 2);
        // Force give exactly one child limit+1 candies.
        // a >= limit+1, b, c <= limit. 3 ways to do this.
        // We will need inclusion exclusion for this part.
        // Signs are reversed since we're subtracting this.
        // Count where a >= limit+1, with no other restrictions.
        ans -= 3*nCr(max(n-(limit+1)+2, 0), 2);
        // Exclude where b <= limit or c <= limit.
        ans += 3*2*nCr(max(n-2*(limit+1)+2, 0), 2);
        // You over subtracted where b <= limit and c <= limit.
        ans -= 3*nCr(max(n-3*(limit+1)+2, 0), 2);
        // Force give exactly two children limit+1 candies.
        // a, b >= limit+1, c <= limit. 3 ways to do this.
        ans -= 3*(nCr(max(n-2*(limit+1)+2, 0), 2)-nCr(max(n-3*(limit+1)+2, 0), 2));
        // Force give exactly three children limit+1 candies.
        // a, b, c >= limit+1.
        ans -= nCr(max(n-3*(limit+1)+2, 0), 2);
        // I see you can simplify some terms, but I'll leave this here for the logic.
        return ans;
    }
private:
    // O(r).
    long long nCr(int n, int r) {
        long long res = 1;
        for (int i = 1; i <= r; ++i) {
            res *= n-r+i;
            res /= i;
        }
        return res;
    }
};
