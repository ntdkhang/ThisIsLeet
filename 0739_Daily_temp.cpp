#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::vector<int> result(temperatures.size(), 0);
        std::stack<std::pair<int, int>> stack; // pair<index, value>

        // stack.push(std::pair(0, temperatures[0]));
        for (int i = 0; i < temperatures.size(); i++) {
            while (!stack.empty() && temperatures[i] > stack.top().second) {
                result[stack.top().first] = i - stack.top().first;
                stack.pop();
            }
            stack.push(std::pair(i, temperatures[i]));
        }

        return result;
    }
};

