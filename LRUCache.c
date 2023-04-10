#define MAP_FACTOR 100

typedef struct {
    int key;
    int value;
    struct Node* next;
    struct Node* prev;
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

Node* mapGet(Map*, LList*, int);
void mapPut(Map*, LList*, int, int);
void mapReplace(Map*, LList*, Node*, int, int);
void mapRemove(LList**, LList*, Node**);
Node* llistPut(LList*, int, int);
void dequeAdd(LList*, Node*);
void dequeRemove(LList*, Node*);

Node* mapGet(Map* map, LList* deque, int key) {
    int n = map->capacity;
    LList** map_llists = map->llists;
    LList* llist = map_llists[key%n];
    if (!llist)
        return NULL;
    Node* curr = llist->head;
    while (curr) {
        if (curr->key == key) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

void mapPut(Map* map, LList* deque, int key, int value) {
    int n = map->capacity;
    LList** map_llists = map->llists;
    LList* llist = map_llists[key%n];
    if (!llist) {
        llist = (LList*)malloc(sizeof(LList));
        llist->size = 0;
        map_llists[key%n] = llist;
    }
    Node* node = llistPut(llist, key, value);
    dequeAdd(deque, node);
}

void mapReplace(Map* map, LList* deque, Node* curr, int key, int value) {
    int n = map->capacity;
    int oldKey = curr->key;
    LList** map_llists = map->llists;
    LList* llist = map_llists[oldKey%n];
    mapRemove(&llist, deque, &curr);
    if (!llist) {
        map_llists[oldKey%n] = NULL;
    }
    mapPut(map, deque, key, value);
}

void mapRemove(LList** mapListRef, LList* deque, Node** currRef) {
    LList* mapList = *mapListRef;
    Node* curr = *currRef;
    if (!mapList) {
        return;
    } else if (mapList->size == 1) {
        free(*mapListRef);
        *mapListRef = NULL;
    } else if (mapList->head->key == curr->key) {
        mapList->head = curr->next;
        mapList->size--;
    } else {
        curr->prev = curr->next;
        mapList->size--;
    }
    dequeRemove(deque, curr);
    free(*currRef);
    *currRef = NULL;
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
    } else if (deque->head->key == curr->key) {
        deque->head = deque->head->dequeNext;
        deque->head->dequePrev = NULL;
    } else {
        if (deque->tail->key == curr->key) {
            deque->tail = deque->tail->dequePrev;
        }
        Node* prev = curr->dequePrev;
        Node* next = curr->dequeNext;
        prev->dequeNext = next;
        if (next) {
            next->dequePrev = prev;
        }
    }
    deque->size--;
}

Node* llistPut(LList* llist, int key, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->next = NULL;
    node->prev = llist->tail;
    node->key = key;
    node->value = value;
    node->dequePrev = NULL;
    node->dequeNext = NULL;
    if (llist->size == 0) {
        llist->head = node;
        llist->tail = node;
    } else {
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

int lRUCacheGet(LRUCache* obj, int key) {
    Map* map = obj->map;
    Node* node = mapGet(map, obj->deque, key);
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
    Node* map_node = mapGet(map, deque, key);
    if (map_node == NULL) {
        int objSize = deque->size;
        if (obj->capacity == objSize) {
            mapReplace(map, deque, deque->head, key, value);
        } else {
            mapPut(map, deque, key, value);
        }
    } else {
        dequeRemove(obj->deque, map_node);
        map_node->value = value;
        dequeAdd(obj->deque, map_node);
    }
}

void lRUCacheFree(LRUCache* obj) {
    Node* curr = obj->deque->head;
    Map* map = obj->map;
    int n = map->capacity;
    LList** map_llists = map->llists;
    while (curr) {
        Node* next = curr->dequeNext;
        int key = curr->key;
        free(map_llists[key%n]);
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
