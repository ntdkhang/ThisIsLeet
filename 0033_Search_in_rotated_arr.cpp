#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        // 4,5,6,7,0,1,2,3
        // 0,1,2,4,5,6,7
        // 1,2,4,5,6,7,0

        int left = 0, right = nums.size() - 1;
        int mid;

        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < nums[right]) { // sorted on the right side
                if (nums[mid] <= target && target <= nums[right]) { // target in range on the right side
                    left = mid + 1;
                } else { // target not on right side
                    right = mid - 1;
                }
            } else { // sorted on the left side
                if (nums[mid] >= target && target >= nums[left]) { // target in range on left side
                    right = mid - 1;
                } else { // target on right side
                    left = mid + 1;
                }
            }
        }

        return -1;
    }
};

