// https://leetcode.com/problems/design-linked-list

class MyLinkedList {
    struct Node {
        int val;
        Node* next;
        Node* prev;
        Node(int x, Node* nextNode = nullptr, Node* prevNode = nullptr)
            : val(x), next(nextNode), prev(prevNode) {}
    };
    Node* head;
    Node* tail;
    int size;

public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index >= size || index < 0)
            return -1;
        Node* tmp = head;
        for (int i = 0; i < index; i++) {
            tmp = tmp->next;
        }
        return tmp->val;
    }

    void addAtHead(int val) {
        Node* new_node = new Node(val, head, nullptr);
        if (head != nullptr) {
            head->prev = new_node;
        }
        head = new_node;
        if (size == 0) {
            tail = new_node;
        }
        size++;
    }

    void addAtTail(int val) {
        Node* new_node = new Node(val, nullptr, tail);
        if (tail != nullptr) {
            tail->next = new_node;
        } else {
            head = new_node;
        }
        tail = new_node;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index > size || index < 0)
            return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == size) {
            addAtTail(val);
            return;
        }

        Node* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        Node* new_node = new Node(val, curr, curr->prev);
        if (curr->prev != nullptr) {
            curr->prev->next = new_node;
        }
        curr->prev = new_node;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index >= size || index < 0)
            return;
        Node* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        if (curr->prev != nullptr) {
            curr->prev->next = curr->next;
        } else {
            head = curr->next;
        }
        if (curr->next != nullptr) {
            curr->next->prev = curr->prev;
        } else {
            tail = curr->prev;
        }
        delete curr;
        size--;
    }
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