#include <vector>
#include <stack>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        std::stack<int> stack; // memory of the index
        heights.push_back(0); // padding to make the logic works for the last element

        int maxArea = 0;
        int width;
        int curIdx;
        int height;

        for (int i = 0; i < heights.size(); i++) {
            while (!stack.empty() && heights[stack.top()] > heights[i]) {
                height = heights[stack.top()];
                stack.pop();

                int prevLowIdx = -1;
                if (!stack.empty()) {
                    prevLowIdx = stack.top();
                }

                width = i - prevLowIdx - 1;
                maxArea = std::max(maxArea, width * height);
            }

            stack.push(i);
        }

        return maxArea;
    }
};

