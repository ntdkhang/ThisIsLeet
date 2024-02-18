#include <iostream>

class Node {
    public:
        int value;
        Node *next;

        Node(int val)  {
            value = val;
            next = nullptr;
        }

        Node(int val, Node* next) {
            value = val;
            next = next;
        }
        Node() {}
};

class LinkedList {
    Node* head;

    void insertAfter(Node* node, int val) {
        Node *nodeToInsert = new Node(val);
        nodeToInsert->next = node->next;
        node->next = nodeToInsert;
    }

    void deleteAfter(Node* node) {
        Node* temp = node->next->next;
        node->next->next = nullptr;
        node->next = temp;
    }
};

int main() {

}
