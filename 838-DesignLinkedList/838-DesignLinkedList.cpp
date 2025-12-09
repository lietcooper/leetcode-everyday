// Last updated: 12/8/2025, 11:27:02 PM
class MyLinkedList {
public:
    MyLinkedList() {
        this->_count = 0;
        this->_dummyHead = new LinkedNode(0);
    }
    
    int get(int index) {
        if (++index > this->_count) return -1;
        LinkedNode* temp = this->_dummyHead;
        while (index--) {
            temp = temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* temp = this->_dummyHead->next;
        this->_dummyHead->next = newNode;
        newNode->next = temp;
        this->_count++;
    }
    
    void addAtTail(int val) {
        LinkedNode* temp = this->_dummyHead;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new LinkedNode(val);
        this->_count++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > this->_count) return;
        if (index == this->_count) return addAtTail(val);
        LinkedNode* temp = this->_dummyHead;
        while (index--) {
            temp = temp->next;
        }
        LinkedNode* temp1 = temp->next;
        temp->next = new LinkedNode(val);
        temp->next->next = temp1;
        this->_count++;
    }
    
    void deleteAtIndex(int index) {
        if (index + 1 > this->_count) return;
        LinkedNode* temp = this->_dummyHead;
        while (index--) {
            temp = temp->next;
        }
        LinkedNode* del = temp->next;
        temp->next = del->next;
        delete del;
        del = nullptr;
        this->_count--;
    }

private:
struct LinkedNode {
    int val;
    LinkedNode* next;
    LinkedNode(int val) : val(val), next(NULL) {};
};

int _count;
LinkedNode* _dummyHead;


};




/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */