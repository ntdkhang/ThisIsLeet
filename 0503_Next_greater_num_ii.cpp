#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> nextGreaterElements(std::vector<int>& nums) {
        std::stack<std::pair<int, int>> stack; // pair <value, index>
        std::vector<int> result(nums.size(), -1);
        for (int i = 0; i < nums.size(); i++) {
            while (!stack.empty() && stack.top().first < nums[i]) {
                result[stack.top().second] = nums[i];
                stack.pop();
            }
            stack.push(std::pair(nums[i], i));
        }

        for (int i = 0; i < nums.size(); i++) {
            while (!stack.empty() && stack.top().first < nums[i]) {
                result[stack.top().second] = nums[i];
                stack.pop();
            }
        }

        return result;
    }
};

