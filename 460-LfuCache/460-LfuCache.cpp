// Last updated: 12/8/2025, 11:28:40 PM
class LFUCache {
private:
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
    };

    struct LinkedList {
        Node* head;
        Node* tail;
        int sz = 0;
        LinkedList() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
        }
        ~LinkedList() {
            delete head;
            delete tail;
        }
    };

    unordered_map<int, pair<Node*, int>> nodes;  // {key, {node, freq}}  
    unordered_map<int, LinkedList> lru;  // {freq, nodes}
    int lf;  // least frequency
    int k;  // cap
    
public:
    LFUCache(int capacity) {
        lf = 1;
        k = capacity;
    }
    
    void removeFromFreq(int freq, Node* cur) {
        if (cur->prev) cur->prev->next = cur->next;
        if (cur->next) cur->next->prev = cur->prev;
        cur->prev = cur->next = nullptr;
        if (--lru[freq].sz == 0) {
            lru.erase(freq);
            if (freq == lf) {
                lf = freq + 1;
            }
        }
    }

    void addToFreq(int freq, Node* cur) {
        // add to head
        lru[freq].head->next->prev = cur;
        cur->next = lru[freq].head->next;
        lru[freq].head->next = cur;
        cur->prev = lru[freq].head;

        // increment the linkedlist(LRU)'s size
        lru[freq].sz++;
    }

    int get(int key) {
        if (nodes.find(key) != nodes.end()) {
            Node* cur = nodes[key].first;
            int freq = nodes[key].second++;
            // nodes[key].second++;  // update node's freq
            removeFromFreq(freq, cur);
            addToFreq(freq + 1, cur);            
            return cur->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (nodes.find(key) != nodes.end()) {
            get(key);
            nodes[key].first->val = value;
        } else {
            if (nodes.size() >= k) {
                Node* lfNode = lru[lf].tail->prev;
                removeFromFreq(lf, lfNode);
                int lfKey = lfNode->key;
                delete lfNode;
                nodes.erase(lfKey);
            }
            // create new node
            Node* cur = new Node(key, value);
            nodes[key] = {cur, 1};
            addToFreq(1, cur);
            lf = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */