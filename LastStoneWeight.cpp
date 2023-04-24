class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int freq[1001];
        memset(freq, 0, 1001*sizeof(int));
        for (int stone : stones)
            freq[stone]++;
        // represents remainder stone
        int s1 = 0;
        for (int i = 1000; i >= 0; i--) {
            while (freq[i]) {
                if (s1) {
                    freq[i]--;
                    freq[s1-i]++;
                    if (s1-i > i)
                        i = s1-i;
                    s1 = 0;
                } else {
                    if (freq[i] == 1) {
                        s1 = i;
                        freq[i]--;
                    } else {
                        s1 = 0;
                        freq[i] -= 2;
                    }
                }
            }
        }
        return s1;
    }
};
