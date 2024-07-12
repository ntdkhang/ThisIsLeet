#include <algorithm>
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        std::vector<int>::iterator left = height.begin(), right = height.end();
        int max_area = 0;
        for (int width = height.size(); width > 1; width--) {
            int curHeight = std::min(*left, *right);
            max_area = std::max(width * curHeight, max_area);
            if (*left < *right) {
                left++;
            } else {
                right--;
            }
        }

        return max_area;
    }
};
