
#include <unordered_map>
template <typename V>
class Node {
    V value;
    Node<V> *prev;
    Node<V> *next;

    Node(V val) {
        value = val;
        prev = nullptr;
        next = nullptr;
    }
};


template <class K, class V>
class LRU {
    int length;
    int capacity;
    Node<V> *head;
    Node<V> *tail;
    std::unordered_map<K, Node<V>*> lookup;
    std::unordered_map<Node<V>*, K> reverseLookup;

    void detach(Node<V> *node) {
        length--;
        if (length == 0) {
            head = nullptr;
            tail = nullptr;
            return;
        }
        if (node == head) {
            head = node->next;
        }
        if (node == tail) {
            tail = node->prev;
        }

        if (node->next != nullptr) {
            node->next->prev = node->prev;
        }
        if (node->prev != nullptr) {
            node->prev->next = node->next;
        }
        node->prev = nullptr;
        node->next = nullptr;
    }

    void prepend(Node<V> *node) {
        length++;
        if (length == 1) {
            head = node;
            tail = node;
            return;
        }
        node->next = head;
        head->prev = node;
        head = node;

    }

    void trimCache() {
        if (length <= capacity) {
            return;
        }

        K key = reverseLookup.at(tail);
        lookup.erase(key);
        reverseLookup.erase(tail);

        Node<V> *node = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete node;
    }

public:
    LRU(int _capacity) {
        head = nullptr;
        tail = nullptr;
        length = 0;
        capacity = _capacity;
    }

    Node<V>* get(K key) {
        // first check if key exists in lookup
        // if no, return nullptr
        auto it = lookup.find(key);
        if (it == lookup.end()) {
            return nullptr;
        }
        Node<V> *node = *it;

        // if yes, move node to front, then return node.
        detach(node);
        prepend(node);
        return node;
    }

    void put(K key, V value) {
        // check if key exists in lookup
        auto it = lookup.find(key);

        // if not, create a new node, prepend to front
        // check if capacity is reached, evict if needed
        if (it == lookup.end()) {
            Node<V> *node = new Node<V>(value);
            prepend(node);
            lookup.insert(key, node);
            reverseLookup.insert(node, key);
            trimCache();
        } else {
            // if key exists, prepend to front, update value;
            Node<V> *node = *it;
            detach(node);
            prepend(node);
            node->value = value;
        }
    }
};
