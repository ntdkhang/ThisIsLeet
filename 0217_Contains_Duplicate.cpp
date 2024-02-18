#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int a : nums) {
            if (s.count(a) == 1) {
                return true;
            }
            s.insert(a);
        }
        return false;
    }
};
