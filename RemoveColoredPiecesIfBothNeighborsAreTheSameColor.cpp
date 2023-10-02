class Solution {
public:
    bool winnerOfGame(string colors) {
        int freq[2] = {0};
        for (int i = 1; i < colors.size()-1; ++i) {
            if (colors[i-1] == colors[i] && colors[i] == colors[i+1]) {
                ++freq[colors[i]-'A'];
            }
        }
        return (freq[0] > freq[1]);
    }
};
