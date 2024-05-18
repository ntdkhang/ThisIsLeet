#include <condition_variable>
#include <mutex>
#include <queue>

class FizzBuzz {
private:
    int n;
    std::queue<int> q;
    std::mutex mut;
    std::condition_variable cond;
    // -1 fizz
    // -2 buzz
    // -3 fizzbuzz
    // n  number

public:
    FizzBuzz(int n) {
        this->n = n;
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 != 0) {
                q.push(-1);
            } else if (i % 5 == 0 && i % 3 != 0) {
                q.push(-2);
            } else if (i % 5 == 0 && i % 3 == 0) {
                q.push(-3);
            } else {
                q.push(i);
            }
        }
    }

    // printFizz() outputs "fizz".
    // i % 3 == 0 || i % 5 != 0
    void fizz(std::function<void()> printFizz) {
        while (!q.empty()) {
            std::unique_lock<std::mutex> lock(mut);
            cond.wait(lock, [this] { return q.front() == -1 || q.empty(); });

            if (q.empty())
                return;
            printFizz();
            q.pop();
            cond.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    // i % 5 == 0 || i % 3 != 0
    void buzz(std::function<void()> printBuzz) {
        while (!q.empty()) {
            std::unique_lock<std::mutex> lock(mut);
            cond.wait(lock, [this] { return q.front() == -2 || q.empty(); });

            if (q.empty())
                return;
            printBuzz();
            q.pop();
            cond.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    // i % 5 == 0 || i % 3 == 0
	void fizzbuzz(std::function<void()> printFizzBuzz) {
        while (!q.empty()) {
            std::unique_lock<std::mutex> lock(mut);
            cond.wait(lock, [this] { return q.front() == -3 || q.empty(); });

            if (q.empty())
                return;
            printFizzBuzz();
            q.pop();
            cond.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    // i % 5 != 0 || i % 3 != 0
    void number(std::function<void(int)> printNumber) {
        while (!q.empty()) {
            std::unique_lock<std::mutex> lock(mut);
            cond.wait(lock, [this] { return q.front() > 0 || q.empty(); });

            if (q.empty())
                return;
            printNumber(q.front());
            q.pop();
            cond.notify_all();
        }
    }
};
