#include <iostream>

template <typename T>
class Node {
public:
    T value;
    Node *next;

    Node(int val) {
        value = val;
    }
};


template <typename T>
class Queue {
    Node<T> *head;
    Node<T> *tail;
    int length = 0;

    void enqueue(T value) {
        Node<T> *node = new Node<T>(value);
        tail->next = node;
        tail = node;
        length++;
    }

    T dequeue() {
        if (length == 0) { return nullptr; }
        T value = head->value;
        head = head->next;
        length--;
        return value;
    }
};
