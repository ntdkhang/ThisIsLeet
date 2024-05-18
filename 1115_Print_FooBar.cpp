#include <mutex>
#include <condition_variable>

class FooBar {
private:
    int n;
    std::mutex mut;
    std::condition_variable cond;
    int flag;

public:
    FooBar(int n) {
        this->n = n;
        flag = 0;
    }

    void foo(std::function<void()> printFoo) {

        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mut);
            cond.wait(lock, [=] { return flag == 0;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            flag = 1;
            cond.notify_one();
        }
    }

    void bar(std::function<void()> printBar) {

        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mut);
            cond.wait(lock, [this] { return flag == 1;});

        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            flag = 0;
            cond.notify_one();
        }
    }
};
