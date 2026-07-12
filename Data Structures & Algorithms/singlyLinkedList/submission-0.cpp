
class Node {
public:
    Node* next;
    int val;
    Node(int x) {
        this->val = x;
        this->next = nullptr; // Using nullptr is standard in modern C++
    }
};

class LinkedList {
    Node *head, *tail;
public:
    LinkedList() {
        // FIX: Start with a truly empty list
        head = nullptr;
        tail = nullptr;
    }

    int get(int index) {
        if (index < 0) return -1; 
        
        Node* n = head;
        // FIX: Safe traversal that stops correctly for index 0
        while (index > 0 && n != nullptr) {
            n = n->next;
            index--;
        }
        
        if (!n) return -1; // Out of bounds
        return n->val;
    }

    void insertHead(int val) {
        Node* t = new Node(val);
        if (!head) {
            // FIX: If list was empty, new node is both head and tail
            head = tail = t;
        } else {
            t->next = head;
            head = t;
        }
    }
    
    void insertTail(int val) {
        Node* t = new Node(val);
        if (!tail) {
            // FIX: Prevent segfault if list is empty
            head = tail = t;
        } else {
            tail->next = t;
            tail = t;
        }
    }

    bool remove(int index) {
        if (index < 0 || !head) return false;

        // Removing the head
        if (index == 0) {
            Node* t = head;
            head = head->next;
            if (!head) tail = nullptr; // FIX: If list becomes empty, clear tail
            delete t;
            return true;
        }

        Node* t = head;
        // FIX: Stop one node BEFORE the target, and ensure 't' doesn't become null
        while (index > 1 && t != nullptr) {
            t = t->next;
            index--;
        }

        // FIX: Ensure we aren't out of bounds (t->next must exist to be deleted)
        if (!t || !t->next) return false;

        Node* toDelete = t->next;
        t->next = toDelete->next;

        // FIX: If we just deleted the tail, update the tail pointer
        if (!t->next) {
            tail = t;
        }

        delete toDelete; // FIX: Prevent memory leak
        return true;
    }

    vector<int> getValues() {
        Node* t = head;
        vector<int> ans;
        while(t) {
            ans.push_back(t->val);
            t = t->next;
        }
        return ans;
    }
};