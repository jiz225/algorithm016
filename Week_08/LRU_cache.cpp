struct CacheNode {
    int key, value;
    CacheNode *prev;
    CacheNode *next;
    CacheNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    CacheNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};
class LRUCache {
private:
    int capacity;
    CacheNode *head; 
    CacheNode *tail;
    unordered_map<int,CacheNode*> nodes;

    void addToHead(CacheNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    void moveNode(CacheNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    CacheNode* removeTail() {
        CacheNode* node = tail->prev;
        moveNode(node);
        return node;
    }
    void moveToHead(CacheNode* node) {
        moveNode(node);
        addToHead(node);
    }
    
public:
    LRUCache(int c) {
        capacity = c;
        head = new CacheNode();
        tail = new CacheNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (nodes.find(key) == nodes.end()) {
            return -1;
        }
        CacheNode* node = nodes[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (nodes.find(key) != nodes.end()) {
            CacheNode* node = nodes[key];
            node->value = value;
            moveToHead(node);
        }
        else {
            CacheNode* node = new CacheNode(key, value);
            nodes[key] = node;
            addToHead(node);
            capacity --;
            if (capacity < 0 && !nodes.empty()) {
                CacheNode* removed = removeTail();
                nodes.erase(removed->key);
                delete removed;
                capacity ++;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
