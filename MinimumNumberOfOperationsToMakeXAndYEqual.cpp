class Solution {
public:
    // We have 4 more recursive calls per recursive call.
    // We are always dividing by at least 5.
    // Thus we have 4^log_5(x).
    // The time complexity is between O(x) and O(x^(2/3)), exclusive,
    // which is better than the intuitive DP O(x) solution for large x.
    int minimumOperationsToMakeEqual(int x, int y) {
        if (y >= x) {
            // Can only increment from here.
            return y-x;
        }
        int mod11 = x%11, mod5 = x%5;
        return min(1+min({
            // Try to divide by 11 by first adding from x.
            minimumOperationsToMakeEqual((x+11-mod11)/11, y)+11-mod11,
            // Try to divide by 11 by first subtracting from x.
            minimumOperationsToMakeEqual((x-mod11)/11, y)+mod11,
            // Try to divide by 5 by first adding from x.
            minimumOperationsToMakeEqual((x+5-mod5)/5, y)+5-mod5,
            // Try to divide by 5 by first subtracting from x.
            minimumOperationsToMakeEqual((x-mod5)/5, y)+mod5,
            // Try to decrement x all the way to y.
        }), x-y);
    }
};
