#include <iostream>
#include <mutex>
#include <condition_variable>
#include <queue>



class ZeroEvenOdd {
private:
    int n;
    std::queue<int> q;
    std::condition_variable cond;
    std::mutex mut;

public:
    ZeroEvenOdd(int n) {
        // n = 5
        // res = "0102030405"
        // n = 12
        // res = "010203040506070809101112"
        this->n = n;
        for (int i = 1; i <= n; i++) {
            q.push(0);
            for (char c : std::to_string(i)) {
                q.push(c - '0');
            }
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(std::function<void(int)> printNumber) {
        while (!q.empty()) {
            std::unique_lock<std::mutex> lock(mut);
            cond.wait(lock, [this] { return q.front() == 0 || q.empty(); });
            if (q.empty()) {
                return;
            }
            printNumber(0);
            q.pop();
            cond.notify_all();
        }
    }

    void even(std::function<void(int)> printNumber) {
        while (!q.empty()) {
            std::unique_lock<std::mutex> lock(mut);
            cond.wait(lock, [this] { return (q.front() % 2 == 0 && q.front() != 0) || q.empty(); });
            if (q.empty()) {
                return;
            }
            printNumber(q.front());
            q.pop();
            cond.notify_all();
        }

    }

    void odd(std::function<void(int)> printNumber) {
        while (!q.empty()) {
            std::unique_lock<std::mutex> lock(mut);
            cond.wait(lock, [this] { return q.front() % 2 == 1 || q.empty(); });
            if (q.empty()) {
                return;
            }
            printNumber(q.front());
            q.pop();
            cond.notify_all();
        }
    }
};
