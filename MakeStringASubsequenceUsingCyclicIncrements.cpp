class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i_1 = 0, i_2;
        for (i_2 = 0; i_1 < str1.size() && i_2 < str2.size(); ++i_1, ++i_2) {
            while (!isValid(str1[i_1], str2[i_2])) {
                if (++i_1 == str1.size()) {
                    return false;
                }
            }
        }
        return (i_2 == str2.size());
    }
private:
    bool isValid(char ch, char compareTo) {
        if (ch == compareTo) {
            return true;
        } else {
            if (ch != 'z') {
                if (ch+1 == compareTo) {
                    return true;
                }
            } else if (compareTo == 'a') {
                return true;
            }
        }
        return false;
    }
};
