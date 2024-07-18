#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int target = -nums[i];
            int left = i+1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == target) {
                    result.push_back(std::vector<int>{nums[i], nums[left], nums[right]});
                    do {
                        left++;
                    } while (left < right && nums[left] == nums[left-1]);
                    do {
                        right--;
                    } while (right > left && nums[right] == nums[right+1]);
                } else if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                }
            }
        }

        return result;
    }
};
