#include <unordered_map>
struct Node {
    int value;
    Node* prev;
    Node* next;

    Node(int val) {
        value = val;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
    int capacity;
    int size;
    std::unordered_map<int, Node*> lookup;
    std::unordered_map<Node*, int> reverseLookup;
    Node *front = nullptr, *back = nullptr;

    void detach(Node* node) {
        size--;

        if (size == 0) {
            front = nullptr;
            back = nullptr;
            return;
        }

        if (node == front) {
            front = node->next;
        }
        if (node == back) {
            back = node->prev;
        }

        if (node->prev != nullptr) {
            node->prev->next = node->next;
        }
        if (node->next != nullptr) {
            node->next->prev = node->prev;
        }

        node->prev = nullptr;
        node->next = nullptr;
    }

    void prepend(Node* node) {
        size++;
        if (size == 1) {
            front = node;
            back = node;
            return;
        }

        node->next = front;
        front->prev = node;
        front = node;
    }

    void trimCache() {
        if (size <= capacity) {
            return;
        }

        Node *node = back;

        // back = node->prev;
        // back->next = nullptr;

        // detach the last node.
        detach(node);

        // remove last node from lookup & reverseLookup
        int key = reverseLookup[node];
        lookup.erase(key);
        reverseLookup.erase(node);

        // delete last node
        delete node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
    }

    int get(int key) {
        auto it = lookup.find(key);
        if (it == lookup.end()) {
            return -1;
        }

        Node *node = it->second;
        detach(node);
        prepend(node);

        return node->value;
    }

    void put(int key, int value) {
        auto it = lookup.find(key);
        if (it == lookup.end()) {
            Node *node = new Node(value);
            prepend(node);
            lookup[key] = node;
            reverseLookup[node] = key;
            trimCache();
        } else {
            Node *node = it->second;
            node->value = value;
            detach(node);
            prepend(node);
        }
    }
};

