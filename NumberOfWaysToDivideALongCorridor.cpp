class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.size(), total_seat = 0;
        for (int i = 0; i < n; ++i) {
            total_seat += is_seat(corridor[i]);
        }
        // Easy case.
        if (!total_seat || total_seat&1) {
            return 0;
        }
        int ans = 1;
        for (int i = 0, curr_seats = 0, curr_partition = 0; i < n; ++i) {
            if (is_seat(corridor[i])) {
                ++curr_seats;
                if (curr_seats == 3) {
                    ans = mult(ans, curr_partition);
                    curr_partition = 0;
                    curr_seats = 1;
                }
            }
            if (curr_seats == 2) {
                ++curr_partition;
            }
        }
        return ans;
    }
private:
    const int MOD = 1e9+7;

    inline bool is_seat(char ch) {
        return ch == 'S';
    }

    inline int mult(int a, int b) {
        return (1ll*a*b)%MOD;
    }
};
