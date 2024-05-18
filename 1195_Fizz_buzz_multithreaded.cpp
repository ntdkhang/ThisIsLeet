#include <condition_variable>
#include <mutex>

class FizzBuzz {
private:
    int n;
    int i;
    std::mutex mut;
    std::condition_variable cond;

public:
    FizzBuzz(int n) {
        this->n = n;
        i = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(std::function<void()> printFizz) {
        while (i <= n) {
            std::unique_lock<std::mutex> lock(mut);
            cond.wait(lock, [this] { return (i % 3 == 0 && i % 5 != 0) || i > n; });

            if (i > n)
                return;
            printFizz();
            i++;
            cond.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(std::function<void()> printBuzz) {
        while (i <= n) {
            std::unique_lock<std::mutex> lock(mut);
            cond.wait(lock, [this] { return (i % 5 == 0 && i % 3 != 0) || i > n; });

            if (i > n)
                return;
            printBuzz();
            i++;
            cond.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(std::function<void()> printFizzBuzz) {
        while (i <= n) {
            std::unique_lock<std::mutex> lock(mut);
            cond.wait(lock, [this] { return (i % 5 == 0 && i % 3 == 0) || i > n; });

            if (i > n)
                return;
            printFizzBuzz();
            i++;
            cond.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(std::function<void(int)> printNumber) {
        while (i <= n) {
            std::unique_lock<std::mutex> lock(mut);
            cond.wait(lock, [this] { return (i % 5 != 0 && i % 3 != 0) || i > n; });

            if (i > n)
                return;
            printNumber(i);
            i++;
            cond.notify_all();
        }
    }
};
