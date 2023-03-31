class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans = 0;
        for (string str : strs) {
            bool onlyDigits = true;
            int numVal = 0;
            int leadingZeros = 0;
            for (; str[leadingZeros] == '0'; leadingZeros++);
            for (int i = leadingZeros; i < str.length() && onlyDigits; i++) {
                if (str[i] >= '0' && str[i] <= '9') {
                    numVal *= 10;
                    numVal += str[i]-'0';
                }
                else 
                    onlyDigits = false;
            }
            int value = (onlyDigits) ? numVal : str.length();
            if (value > ans)
                ans = value;
        }
        return ans;
    }
};
