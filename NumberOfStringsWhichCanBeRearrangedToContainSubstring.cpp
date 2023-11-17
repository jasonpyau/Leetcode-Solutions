// Inclusion Exclusion

// Total possible: n slots, 26 choices each = 26^n.

// 25^n + 25^n + 25^n + n*25^(n-1)
// 0: l   0: e   0: t   1: e (force e in one slot, rest have 25 choices), n ways to do this.

// 24^n  +  24^n  +  +  24^n  +  n*24^(n-1)  +  n*24^(n-1)  +  0
// 0: l,t  0: l,e    0: t,e      1: e; 0: l     1: e; 0: t     0: e; 1: e

// 23^n   +   n*23^(n-1)
// 0: l,e,t   1: e; 0: l,t

// Simplified, we have:
// t = 26^n
// x1 = 3*25^n+n*25^(n-1)
// x2 = 3*24^n+2*n*24^(n-1)
// x3 = 23^n+n*23^(n-1)
// ans = t-x1+x2-x3
class Solution {
public:
    int stringCount(int n) {
        int t = pow(26, n);
        int x1 = add(mult(3, pow(25, n)), mult(n, pow(25, n-1)));
        int x2 = add(mult(3, pow(24, n)), mult(2, mult(n, pow(24, n-1))));
        int x3 = add(pow(23, n), mult(n, pow(23, n-1)));
        int ans = sub(t, x1);
        ans = add(ans, x2);
        ans = sub(ans, x3);
        return ans;
    }
private:
    const int MOD = 1e9+7;

    // 0 <= a, b < MOD
    inline int add(int a, int b) {
        return (a+b)%MOD;
    }

    inline int sub(int a, int b) {
        return (a-b+MOD)%MOD;
    }

    inline int mult(int a, int b) {
        return (1ll*a*b)%MOD;
    }

    int pow(int n, int e) {
        if (!e) {
            return 1;
        } else if (e&1) {
            return mult(n, pow(n, e-1));
        } else {
            // Time savings here.
            // n^e = n^(e/2)*n^(e/2)
            int half = pow(n, e>>1);
            return mult(half, half);
        }
    }
};
