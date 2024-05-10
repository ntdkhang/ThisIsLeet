#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numset;
        unordered_map<int, int> map;
        int maxCount = 0;
        for (int num : nums) {
            numset.insert(num);
        }

        for (int num : numset) {
            int left = 0, right = 0;
            if (numset.find(num - 1) != numset.end()) {
                left = map[num - 1];
            }

            if (numset.find(num + 1) != numset.end()) {
                right = map[num + 1];
            }

            int length = left + right + 1;
            map[num - left] = length;
            map[num + right] = length;
            maxCount = max(maxCount, length);
        }

        return maxCount;
    }
};

