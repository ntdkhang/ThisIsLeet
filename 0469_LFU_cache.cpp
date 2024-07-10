#include <list>
#include <unordered_map>
struct Node {
    // Node *prev, *next;
    int key, value, freq;
    std::list<int>::iterator it; // iterator to freq_map

    Node(int _key, int _value) : key(_key), value(_value), freq(1){} // , prev(nullptr), next(nullptr) {}
};



class LFUCache {
    int LFCount, size, capacity;
    std::unordered_map<int, std::list<int>> freq_map; // <freq, list<key>>
    std::unordered_map<int, Node*> lookup;               // <key, node>

    void trimCache() {
        if (size > capacity) {
            int key = freq_map[LFCount].back();
            freq_map[LFCount].pop_back();
            lookup.erase(key);
        }
    }
public:
    LFUCache(int _capacity) {
        capacity = _capacity;
        size = 0;
        LFCount = 1;
    }

    int get(int key) {
        auto it = lookup.find(key);
        if (it == lookup.end()) {
            return -1;
        }

        // retrieve node
        Node* node = it->second;
        // remove old freq_map
        freq_map[node->freq].erase(node->it);

        // update LFCount if needed
        if (freq_map[node->freq].empty() && node->freq == LFCount) {
            LFCount++;
        }

        // increment freq
        node->freq++;

        // update freq_map
        freq_map[node->freq].push_front(key);
        node->it = freq_map[node->freq].begin();
        return node->value;
    }

    void put(int key, int value) {
        auto it = lookup.find(key);
        if (it == lookup.end()) {
            // create a new node
            Node* node = new Node(key, value);

            // update size
            size++;

            // trim cache
            trimCache();

            // add to lookup
            lookup[key] = node;

            // add to freq_map
            freq_map[1].push_front(key);
            node->it = freq_map[1].begin();

            // update LFCount
            LFCount = 1;
        } else {
            get(key);
            Node *node = it->second;
            node->value = value;
        }
    }
};
