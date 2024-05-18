#include <mutex>
#include <condition_variable>
#include <queue>

class BoundedBlockingQueue {
    std::mutex mut;
    std::condition_variable cond;
    std::queue<int> q;
    int sz;
    int capacity;

public:
    BoundedBlockingQueue(int capacity) {
        sz = 0;
        this->capacity = capacity;
    }

    void enqueue(int element) {
        std::unique_lock<std::mutex> lock(mut);
        cond.wait(lock, [this] { return sz < capacity; });
        q.push(element);
        sz++;
        cond.notify_all();
    }

    int dequeue() {
        std::unique_lock<std::mutex> lock(mut);
        cond.wait(lock, [this] { return sz > 0; });
        int num = q.front();
        q.pop();
        sz--;
        cond.notify_all();
        return num;
    }

    int size() {
        std::lock_guard<std::mutex> lock(mut);
        return sz;
    }
};
