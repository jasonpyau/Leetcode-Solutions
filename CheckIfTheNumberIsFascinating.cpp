class Solution {
public:
    bool isFascinating(int n) {
        string s = to_string(n)+to_string(n*2)+to_string(n*3);
        if (s.size() != 9) {
            return false;
        }
        int freq[10];
        memset(freq, 0, 10*sizeof(int));
        for (int i = 0; i < 9; i++) {
            freq[s[i]-'0']++;
        }
        for (int i = 1; i < 10; i++) {
            if (freq[i] != 1) {
                return false;
            }
        }
        return true;
    }
};
