#include <vector>

using namespace std;

class Solution {
public:
    //      [1, 2, 3, 4]
    //      [1, 1, 2, 6]
    //      [1, 1, 8, 6]

    // pre  [1, 1, 2, 6]
    // post [24,12,4, 1]
    // res  [24,12,8, 6]
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            result[i] = result[i-1] * nums[i-1];
        }
        int postfix = 1;

        for (int i = nums.size() - 1; i >= 0; i--) {
            result[i] *= postfix;
            postfix *= nums[i];
        }


        return result;
    }
};
