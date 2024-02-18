#include <vector>

using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // write your code here

        // 1 1 0 1 1 0 0 1 1 1 0
        // 0 1 2 2 3 4 4 4 5 6 7 7

        vector<int> sum{0};
        for (int i = 0; i < nums.size(); i++) {
            sum.push_back(sum.at(i) + nums.at(i));
        }

        int r = 1, l = 0, max_c = 0;

        while (r <= nums.size()) {
            int count = sum.at(r) - sum.at(l);
            if (count + k >= (r - l)) {
                max_c = max(r - l, max_c);
                r++;
            } else {
                l += 1;
            }
        }
        return max_c;


    }
};


// int main() {
//     Solution sol = Solution();
//     vector<int> nums {1,1,0,1,1,0,0,1,1,1,0};
//     sol.longestOnes(vector<int> &nums, 2);
// }
