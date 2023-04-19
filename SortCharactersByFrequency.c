#define FREQ_LEN 'z'-'0'+1

typedef struct {
    char item;
    int freq;
} character;

int compareTo(const void*, const void*);

int compareTo(const void* a, const void* b) {
    return ((character*)b)->freq-((character*)a)->freq;
}
char * frequencySort(char * s) {
    character freqs[FREQ_LEN];
    for (int i = 0; i < FREQ_LEN; i++) {
        freqs[i].item = i+'0';
        freqs[i].freq = 0;
    }
    int len = 0;
    for (; s[len]; len++) {
        char ch = s[len];
        freqs[ch-'0'].freq++;
    }
    int (*compareToPtr)(const void*, const void*) = &compareTo;
    qsort(freqs, FREQ_LEN, sizeof(character), compareToPtr);
    char* ans = calloc(len+1, sizeof(char));
    int ansInd = 0;
    for (int i = 0; i < FREQ_LEN; i++) {
        int freq;
        if ((freq = freqs[i].freq)) {
            while (freq--) {
                ans[ansInd++] = freqs[i].item;
            }
        } else {
            break;
        }
    }
    ans[ansInd] = '\0';
    return ans;
}
