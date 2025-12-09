// Last updated: 12/8/2025, 11:27:00 PM
class MyCircularQueue {
private:
    vector<int> q;
    int head, tail, k;
    // bool full;
public:
    MyCircularQueue(int k) {
        this->k = k;
        q.resize(k, 0);
        head = 0, tail = -1;
        // full = false;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        tail = (tail + 1) % k;
        q[tail] = value;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;

        if (head == tail) {
            head = 0;
            tail = -1;
        } else {
            head = (head + 1) % k;
        }
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return q[head];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return q[tail];
    }
    
    bool isEmpty() {
        return tail == -1;
    }
    
    bool isFull() {
        return tail != -1 && (tail + 1) % k == head;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */