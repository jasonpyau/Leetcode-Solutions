class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str2.size() > str1.size())
            swap(str1, str2);
        int strLen = str1.size(), divLen = str2.size();
        divLen = gcd(strLen, divLen);
        string ans = str2.substr(0, divLen);
        for (int i = 0; i < str2.size(); ) {
            for (int j = 0; j < divLen; i++, j++) {
                if (str2[i] != ans[j])
                    return "";
            }
        }
        for (int i = 0; i < strLen; ) {
            for (int j = 0; j < divLen; i++, j++) {
                if (str1[i] != str2[j])
                    return "";
            }
        }
        return ans;
    }
};
