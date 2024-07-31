#include <vector>

class MinStack {
public:
    std::vector<std::pair<long, long>> stack;  // pair <value, min>

    MinStack() {
    }

    void push(long val) {
        if (stack.size() == 0) {
            stack.push_back(std::pair(val, val));
        } else {
            long pre_min = stack.back().second;
            stack.push_back(std::pair(val, std::min(pre_min, val)));
        }
    }

    void pop() {
        stack.pop_back();
    }

    int top() {
        return stack.back().first;
    }

    int getMin() {
        return stack.back().second;
    }
};
