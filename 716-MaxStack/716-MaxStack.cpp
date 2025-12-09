// Last updated: 12/8/2025, 11:27:54 PM
// struct Node {
//     int val;
//     Node* prev;
//     Node* next;
//     Node(int val) : val(val), prev(nullptr), next(nullptr) {}
// };


// class LinkedList {
// public:
//     Node* head;
//     Node* tail;
//     LinkedList() {
//         head = new Node(0);
//         tail = head;
//     }

//     Node* push(int val) {
//         Node* node = new Node(val);
//         tail->next = node;
//         node->prev = tail;
//         tail = tail->next;
//         return node;
//     }

//     int pop() {
//         if (!isEmpty()) {
//             Node* cur = tail;
//             tail = cur->prev;
//             cur->prev = nullptr;
//             tail->next = nullptr;
//             int val = cur->val;
//             delete cur;
//             return val;
//         }
//         return -1;
//     }    

//     bool isEmpty() { return tail == head;}

//     ~LinkedList() {
//         delete head;
//     }
//  };


// class MaxStack {
// private:
//     LinkedList st;
//     unordered_map<int, vector<Node*>> map;
//     priority_queue<int> pq;

// public:
//     MaxStack() {
    
//     }
    
//     void push(int x) {
//         map[x].push_back(st.push(x));
//         pq.push(x);
//     }
    
//     int pop() {
//         int res = st.pop();
//         map[res].pop_back();
//         if (map[res].empty()) map.erase(res);
//         if (pq.top() == res) pq.pop();
//         return res;
//     }
    
//     int top() {
//         if (!st.isEmpty()) {
//             return st.tail->val;
//         }
//         return - 1;
//     }
    
//     int peekMax() {
//         if (!pq.empty()) {
//             while (map[pq.top()].empty()) pq.pop();
//             return pq.top();
//         }
//         return -1;
//     }
    
//     int popMax() {
//         if (!pq.empty()) {
//             while (map[pq.top()].empty()) pq.pop();
//             int res = pq.top();
//             pq.pop();
//             Node* cur = map[res].back();
//             map[res].pop_back();
//             if (map[res].empty()) map.erase(res);
//             if (st.tail == cur) {
//                 st.tail = cur->prev;
//             }
//             cur->prev->next = cur->next;
//             if (cur->next) cur->next->prev = cur->prev;
//             cur->prev = nullptr;
//             cur->next = nullptr;
//             delete cur;
//             return res;
//         }
//         return -1;
//     }
// };

// /**
//  * Your MaxStack object will be instantiated and called as such:
//  * MaxStack* obj = new MaxStack();
//  * obj->push(x);
//  * int param_2 = obj->pop();
//  * int param_3 = obj->top();
//  * int param_4 = obj->peekMax();
//  * int param_5 = obj->popMax();
//  */

class MaxStack {
private:
    stack<pair<int, int>> stack;
    priority_queue<pair<int, int>> heap;
    set<int> removed;
    int count;
public:
    MaxStack() {
        count = 0;
    }
    
    void push(int x) {
        stack.push({x, count});
        heap.push({x, count});
        count++;
    }
    
    int pop() {
        while(removed.contains(stack.top().second)){
            stack.pop();
        }
        auto [num, count] = stack.top();
        stack.pop();
        removed.insert(count);
        return num;
    }
    
    int top() {
        while(removed.contains(stack.top().second)){
            stack.pop();
        }
        return stack.top().first;
    }
    
    int peekMax() {
        while(removed.contains(heap.top().second)){
            heap.pop();
        }
        return heap.top().first;
    }
    
    int popMax() {
        while(removed.contains(heap.top().second)){
            heap.pop();
        }
        auto [num, count] = heap.top();
        heap.pop();
        removed.insert(count);
        return num;
    }
};