#define CAP 100001

typedef struct {
    int key;
    struct Node* next;
} Node;

typedef struct {
    Node** keys;
    Node* keysHeads;
    int capacity;
} Set;

Set* setInit() {
    Set* set = malloc(sizeof(Set));
    set->capacity = CAP;
    Node** keys = calloc(CAP, sizeof(Node*));
    set->keys = keys;
    set->keysHeads = NULL;
    return set;
}

Node* createNode(int key) {
    Node* node = malloc(sizeof(Node));
    node->key = key;
    return node;
}

void setAdd(Set* set, int key) {
    int ind = key%CAP;
    Node* head = set->keys[ind];
    if (!head) {
        Node* newNode = createNode(key);
        newNode->next = NULL;
        set->keys[ind] = newNode;
        Node* keysHead = createNode(key);
        keysHead->next = set->keysHeads;
        set->keysHeads = keysHead;
    } else {
        Node* newNode = createNode(key);
        newNode->next = head;
        set->keys[ind] = newNode;
    }
}

bool setFind(Set* set, int key) {
    int ind = key%CAP;
    Node* head = set->keys[ind];
    if (!head)
        return false;
    Node* curr = head;
    while (curr) {
        if (curr->key == key)
            return true;
        curr = curr->next;
    }
    return false;
}

void setFree(Set* set) {
    Node* currHead = set->keysHeads;
    while (currHead) {
        Node* currHeadNext = currHead->next;
        int ind = currHead->key%CAP;
        Node* curr = set->keys[ind];
        while (curr) {
            Node* next = curr->next;
            free(curr);
            curr = next;
        }
        free(currHead);
        currHead = currHeadNext;
    }
    free(set->keys);
    free(set);
    set = NULL;
}

static inline int strToInt(char* str, char skip) {
    int res = 0;
    for (int i = 0; str[i]; i++) {
        char ch = str[i];
        if (ch == skip)
            continue;
        res |= 1<<(ch-'a');
    }
    return res;
}

int wordCount(char ** startWords, int startWordsSize, char ** targetWords, int targetWordsSize) {
    Set* startLetters = setInit();
    int ans = 0;
    for (int i = 0; i < startWordsSize; i++)
        setAdd(startLetters, strToInt(startWords[i], '\0'));
    for (int i = 0; i < targetWordsSize; i++) {
        char* targetWord = targetWords[i];
        for (int j = 0; targetWord[j]; j++) {
            int targetLetters = strToInt(targetWord, targetWord[j]);
            if (setFind(startLetters, targetLetters)) {
                ans++;
                break;
            }
        }
    }
    setFree(startLetters);
    return ans;
}
