class Solution {
public:
    // One solution: Coin change DP Problem, O(sqrt(n)^2) = O(n).
    // O(sqrt(n)*log(n)).
    int numSquares(int n) {
        if (perfect_square(n)) {
            return 1;
        }
        // Try to find two perfect squares.
        for (int i = 1, sq = sqrt_floor(n); i*i <= n; ++i) {
            if (perfect_square(n-i*i)) {
                return 2;
            }
        }
        // n = x^2+y^2+z^2 iff n != 4^a(8b+7), for all a, b in 0 or Z+.
        // https://en.wikipedia.org/wiki/Legendre%27s_three-square_theorem
        while (n%4 == 0) {
            n /= 4;
        }
        if (n%8 != 7) {
            return 3;
        }
        // Every number can be presented in [1,4] perfect squares.
        // https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem
        return 4;
    }
private:
    int sqrt_floor(int n) {
        int low = 0, mid, res = 0, high = 1e2;
        while (high >= low) {
            mid = (low+high)>>1;
            if (mid*mid > n) {
                high = mid-1;
            } else {
                low = mid+1;
                res = mid;
            }
        }
        return res;
    }

    bool perfect_square(int n) {
        int sq = sqrt_floor(n);
        return (sq*sq == n);
    }
};
