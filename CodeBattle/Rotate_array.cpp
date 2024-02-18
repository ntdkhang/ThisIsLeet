#include <vector>

using namespace std;

class Solution {
public:
    int prev = 0, temp = 0;
	void rotate(vector<int>& nums, int k) {
		// write your code here
        if (k==0) {
            return;
        }
        prev = nums.at(0);
        temp = 0;
        for (int i = 1; i <= nums.size(); i++) {
            if (i == nums.size()) {
                nums.at(0) = prev;
            } else {
                temp = nums.at(i);
                nums.at(i) = prev;
                prev = temp;
            }
        }
        rotate(nums, k-1);
        return;
	}
};
