#include <mutex>
#include <condition_variable>

class Foo {
    std::mutex mut;
    std::condition_variable cond;

    int current;
public:
    Foo() {
        current = 0;
    }

    void first(std::function<void()> printFirst) {
        std::lock_guard<std::mutex> lock(mut);

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        current++;
    }

    void second(std::function<void()> printSecond) {
        std::unique_lock<std::mutex> lock(mut);
        cond.wait(lock, [this] { return current == 1;});

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        current++;
    }

    void third(std::function<void()> printThird) {
        std::unique_lock<std::mutex> lock(mut);
        cond.wait(lock, [this] { return current == 2;});

        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
