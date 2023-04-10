#define MAP_FACTOR 1001

typedef struct {
    int key;
    int value;
    struct Node* mapNext;
    struct Node* dequeNext;
    struct Node* dequePrev;
} Node;

typedef struct {
    int size;
    Node* head;
    Node* tail;
} LList;

typedef struct {
    int capacity;
    LList** llists;
} Map;

typedef struct {
    int capacity;
    LList* deque;
    Map* map;
} LRUCache;

Node* mapLListFind(LList*, int);
void mapPut(Map*, LList*, int, int);
void mapReplace(Map*, LList*, Node*, int, int);
void mapRemove(LList**, LList*, Node**);
Node* llistPut(LList*, int, int);
void dequeAdd(LList*, Node*);
void dequeRemove(LList*, Node*);

static inline LList* mapLListGet(Map* map, int key) {
    LList** map_llists = map->llists;
    return map_llists[key%(map->capacity)];
}

Node* mapLListFind(LList* mapLList, int key) {
    if (!mapLList) {
        return NULL;
    }
    Node* curr = mapLList->head;
    while (curr) {
        if (curr->key == key) {
            return curr;
        }
        curr = curr->mapNext;
    }
    return NULL;
}

void mapPut(Map* map, LList* deque, int key, int value) {
    LList* map_llist = mapLListGet(map, key);
    if (!map_llist) {
        map_llist = (LList*)malloc(sizeof(LList));
        map_llist->size = 0;
        map->llists[key%(map->capacity)] = map_llist;
    }
    Node* node = llistPut(map_llist, key, value);
    dequeAdd(deque, node);
}

void mapReplace(Map* map, LList* deque, Node* curr, int key, int value) {
    int n = map->capacity;
    int oldKey = curr->key;
    LList* llist = mapLListGet(map, oldKey);
    mapRemove(&llist, deque, &curr);
    if (!llist) {
        map->llists[oldKey%n] = NULL;
    }
    mapPut(map, deque, key, value);
}

void mapRemove(LList** mapLListRef, LList* deque, Node** delNodeRef) {
    LList* mapLList = *mapLListRef;
    Node* delNode = *delNodeRef;
    if (!mapLList) {
        return;
    }
    if (mapLList->size == 1) {
        free(*mapLListRef);
        *mapLListRef = NULL;
    } else if (mapLList->head == delNode) {
        mapLList->head = mapLList->head->mapNext;
        mapLList->size--;
    } else {
        Node* curr = mapLList->head;
        while (curr->mapNext) {
            if (curr->mapNext == delNode) {
                break;
            }
            curr = curr->mapNext;
        }
        curr->mapNext = delNode->mapNext;
        mapLList->size--;
    }
    dequeRemove(deque, delNode);
    free(*delNodeRef);
    *delNodeRef = NULL;
}

void dequeAdd(LList* deque, Node* curr) {
    curr->dequePrev = deque->tail;
    if (deque->size == 0) {
        deque->head = curr;
        deque->tail = curr;
    } else {
        deque->tail->dequeNext = curr;
        deque->tail = curr;
    }
    curr->dequeNext = NULL;
    deque->size++;
}

void dequeRemove(LList* deque, Node* curr) {
    if (deque->size == 0) {
        return;
    } else if (deque->size == 1) {
        deque->head = NULL;
        deque->tail = NULL;
    } else if (deque->head == curr) {
        deque->head = deque->head->dequeNext;
        deque->head->dequePrev = NULL;
    } else {
        Node* prev = curr->dequePrev;
        Node* next = curr->dequeNext;
        if (deque->tail == curr) {
            deque->tail = prev;
        } else {
            next->dequePrev = prev;
        }
        prev->dequeNext = next;
    }
    deque->size--;
}

Node* llistPut(LList* llist, int key, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->mapNext = NULL;
    node->key = key;
    node->value = value;
    node->dequePrev = NULL;
    node->dequeNext = NULL;
    if (llist->size == 0) {
        llist->head = node;
        llist->tail = node;
    } else {
        llist->tail->mapNext = node;
        llist->tail = node;
    }
    llist->size++;
    return node;
}

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* lru = (LRUCache*)malloc(sizeof(LRUCache));
    lru->capacity = capacity;
    LList* deque = (LList*)malloc(sizeof(LList));
    deque->size = 0;
    deque->head = NULL;
    deque->tail = NULL;
    lru->deque = deque;
    Map* map = (Map*)malloc(sizeof(Map));
    map->capacity = MAP_FACTOR*capacity;
    LList** map_llists = (LList**)calloc((map->capacity), sizeof(LList*));
    map->llists = map_llists;
    lru->map = map;
    return lru;
}

static inline void putNewNode(LRUCache* obj, Map* map, LList* deque, int key, int value) {
    if (obj->capacity == deque->size) {
        mapReplace(map, deque, deque->head, key, value);
    } else {
        mapPut(map, deque, key, value);
    }
}

int lRUCacheGet(LRUCache* obj, int key) {
    LList* map_llist = mapLListGet(obj->map, key);
    if (!map_llist) {
        return -1;
    }
    Node* node = mapLListFind(map_llist, key);
    if (!node) {
        return -1;
    }
    dequeRemove(obj->deque, node);
    dequeAdd(obj->deque, node);
    return node->value;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    Map* map = obj->map;
    LList* deque = obj->deque;
    LList* map_llist = mapLListGet(map, key);
    if (!map_llist) {
        putNewNode(obj, map, deque, key, value);
        return;
    }
    Node* map_node = mapLListFind(map_llist, key);
    if (!map_node) {
        putNewNode(obj, map, deque, key, value);
        return;
    }
    dequeRemove(deque, map_node);
    map_node->value = value;
    dequeAdd(deque, map_node);
}

void lRUCacheFree(LRUCache* obj) {
    Node* curr = obj->deque->head;
    Map* map = obj->map;
    int n = map->capacity;
    LList** map_llists = map->llists;
    while (curr) {
        Node* next = curr->dequeNext;
        int map_ind = (curr->key)%n;
        if (map_llists[map_ind]) {
            free(map_llists[map_ind]);
            map_llists[map_ind] = NULL;
        }
        free(curr);
        curr = next;
    }
    free(map_llists);
    free(map);
    obj->map = NULL;
    free(obj->deque);
    obj->deque = NULL;
    free(obj);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/
