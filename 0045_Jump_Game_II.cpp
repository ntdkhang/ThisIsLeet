#include <algorithm>
#include <vector>

class Solution {
public:
    int jump1(std::vector<int>& nums) {
        int result = nums.size();
        std::vector<int> smallestStepTo(nums.size(), nums.size());

        smallestStepTo[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            int currentStep = smallestStepTo[i];
            int maxJump = nums[i];

            for (int j = i+1; j <= i + maxJump && j < nums.size(); j++) {
                smallestStepTo[j] = std::min(smallestStepTo[j], smallestStepTo[i] + 1);
            }
        }

        return smallestStepTo[nums.size() - 1];
    }

    int jump(std::vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int end = 0, farthest = 0, steps = 0;
        for (int i = 0; i < nums.size(); i++) {
            farthest = std::max(farthest, i + nums[i]);
            if (i == end) {
                end = farthest;
                steps++;
                if (farthest >= nums.size() - 1) {
                    break;
                }
            }
        }
        return steps;
    }
};
