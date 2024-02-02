class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for (int d = get_digits(low), dh = get_digits(high); d <= dh; ++d) {
            for (int leading = 1; leading <= 9 && can_do(leading, d); ++leading) {
                int val = get_val(leading, d);
                if (val < low) {
                    continue;
                } else if (val > high) {
                    return ans;
                }
                ans.push_back(val);
            }
        }
        return ans;
    }
private:
    // 1-10. Only edge case is 0, so good.
    int get_digits(int val) {
        int res = 0;
        while (val) {
            val /= 10;
            ++res;
        }
        return res;
    }

    bool can_do(int leading, int digits) {
        return (10-leading >= digits);
    }

    // Assume can_do(leading, digits) is true.
    int get_val(int leading, int digits) {
        int res = leading;
        for (int i = 1; i < digits; ++i) {
            res = res*10+leading+i;
        }
        return res;
    }
};
