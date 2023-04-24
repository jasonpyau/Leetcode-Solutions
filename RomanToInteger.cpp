class Solution {
public:
    Solution() {
        val[ind('I')] = 1;
        val[ind('V')] = 5;
        val[ind('X')] = 10;
        val[ind('L')] = 50;
        val[ind('C')] = 100;
        val[ind('D')] = 500;
        val[ind('M')] = 1000;
    }

    int romanToInt(string s) {
        int ans = 0;
        int freq[26];
        memset(freq, 0, 26*sizeof(int));
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            ans += val[ind(ch)];
            freq[ind(ch)]++;
            switch (ch) {
                case 'V':
                case 'X':
                    if (freq[ind('I')])
                        ans -= 2*val[ind('I')];
                    break;
                case 'L':
                case 'C':
                    if (freq[ind('X')])
                        ans -= 2*val[ind('X')];
                    break;
                case 'D':
                case 'M':
                    if (freq[ind('C')])
                        ans -= 2*val[ind('C')];
                    break;
            }
        }
        return ans;
    }
private:
    int val[26];

    int ind(char ch) {
        return ch-'A';
    }
};
