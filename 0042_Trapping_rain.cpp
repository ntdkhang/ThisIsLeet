#include <vector>

class Solution {
public:
    int trap(std::vector<int>& height) {
/*         int left = 0, right;
        if (height.size() < 3) {
            return 0;
        }

        while (height[left] == 0) {
            left++;
        }
        right = left + 2;
        int curHeight = height[left];
        int rain = 0;

        while (left < height.size() - 1) {
            if (height[right] >= height[left]) {
                // calculate the rain in-between
                while (left < right - 1) {
                    left++;
                    rain += curHeight - height[left];
                }
                left = right;
                curHeight = height[left];
                right += 2;
            } else {
                right++;
            }

            if (right >= height.size()) {
                do {
                    left++;
                } while (height[left] >= curHeight && left < height.size() - 1);
                curHeight = height[left];
                right = left + 2;
            }
        }

        return rain; */

        int left = 0, right = height.size() - 1;
        int maxLeft = 0, maxRight = 0;
        int rain = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] > maxLeft) {
                    maxLeft = height[left];
                } else {
                    rain += (maxLeft - height[left]);
                }
                left++;
            } else {
                if (height[right] > maxRight) {
                    maxRight = height[right];
                } else {
                    rain += (maxRight - height[right]);
                }
                right--;
            }
        }

        return rain;
    }
};
