int compareTo(const void* lhs, const void* rhs) {
    return *((int*)rhs)-*((int*)lhs);
}

bool equalFrequency(char * word) {
    // Hold freq of each letter
    int freq[26];
    for (int i = 0; i < 26; i++)
        freq[i] = 0;
    int len = 0;
    for (; word[len]; len++)
        freq[word[len]-'a']++;
    qsort(freq, 26, sizeof(int), &compareTo);
    // Check if one freq is greater than the rest by one
    if (freq[0] == freq[1]+1) {
        for (int i = 2; i < 26 && freq[i]; i++) {
            if (freq[i] == freq[1])
                continue;
            else
                return false;
        }
        return true;
    } else if (!freq[2] && (freq[1] == 1 || !freq[1])) {
        // EDGE CASES!!!!!!!!!!
        return true;
    } else if (freq[0] > freq[1]) {
        return false;
    }
    // Check if the rest are the same but need to throw out a 1
    int i = 1;
    for (; i < 26 && freq[i]; i++) {
        if (freq[i] != freq[i-1]) {
            i++;
            break;
        }
    }
    if (i == 26) {
        return (freq[25] == 1);
    }
    printf("%d", i);
    return (freq[i-1] == 1 && !freq[i]);
}
