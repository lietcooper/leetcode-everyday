// Last updated: 12/8/2025, 11:27:04 PM
#define MOD 10001
class MyHashMap {
private:
    class Node {
    public:
        int key, val;
        Node* next;
        Node(int key, int val) : key(key), val(val), next(nullptr) {}
    };
    // Node* arr[MOD];
    vector<Node*> arr;
public:
    MyHashMap() {
        arr = vector<Node*>(MOD, nullptr);
    }
    
    void put(int key, int value) {
        int hashed_key = key % MOD;
        Node* cur = arr[hashed_key];
        while (cur) {
            if (cur->key == key) {
                cur->val = value;
                return;
            }
            cur = cur->next;
        }
        Node* node = new Node(key, value);
        node->next = arr[hashed_key];
        arr[hashed_key] = node;
    }
    
    int get(int key) {
        int hashed_key = key % MOD;
        Node* cur = arr[hashed_key];
        if (!cur) return -1;
        while (cur) {
            if (cur->key == key) {
                return cur->val;
            }
            cur = cur->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int hashed_key = key % MOD;
        Node* cur = arr[hashed_key];
        if (!cur) return;
        if (cur->key == key) {
            arr[hashed_key] = cur->next;
            cur->next = nullptr;
            delete cur;
            return;
        }

        while (cur->next && cur->next->key != key) {
            cur = cur->next;
        }

        if (!cur->next) return;
        Node* temp = cur->next;
        cur->next = cur->next->next;
        temp->next = nullptr;
        delete temp;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */