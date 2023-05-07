class Solution {
public:
    bool isCircularSentence(string sentence) {
        int len = sentence.size();
        for (int i = 0; i < len; i++) {
            char ch = sentence[i];
            if (ch == ' ') {
                if (i+1 < len && sentence[i-1] != sentence[i+1]) {
                    return false;
                }
            }
        }
        return (sentence[0] == sentence[len-1]);
    }
};
