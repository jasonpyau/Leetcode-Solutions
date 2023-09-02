typedef struct Trie {
    bool isWord;
    struct Trie* next[26];    
} Trie;


Trie* trieCreate() {
    Trie* trie = malloc(sizeof(Trie));
    trie->isWord = false;
    memset(trie->next, NULL, 26*sizeof(Trie*));
    return trie;
}

void trieInsert(Trie* obj, char * word) {
    int ind = word[0]-'a';
    if (!obj->next[ind]) {
        obj->next[ind] = trieCreate();
    }
    if (!word[1]) {
        obj->next[ind]->isWord = true;
        return;
    } else {
        trieInsert(obj->next[ind], word+1);
    }
}

bool trieSearch(Trie* obj, char * word) {
    if (!word[0]) {
        return obj->isWord;
    }
    int ind = word[0]-'a';
    if (!obj->next[ind]) {
        return false;
    }
    return trieSearch(obj->next[ind], word+1);
}

bool trieStartsWith(Trie* obj, char * prefix) {
    char ch;
    for (int i = 0; (ch = prefix[i]); ++i) {
        if (!obj->next[ch-'a']) {
            return false;
        }
        obj = obj->next[ch-'a'];
    }
    return true;
}

void trieFree(Trie* obj) {
    for (int i = 0; i < 26; ++i) {
        if (obj->next[i]) {
            trieFree(obj->next[i]);
        }
    }
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/
