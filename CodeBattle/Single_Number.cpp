#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		// write your code here
        int res = 0;

        for (int x : nums) {
            res ^= x;
        }
        return res;
	}
};
