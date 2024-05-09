#include <iostream>
#include <iterator>
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
        vector<int> prefix{1}, postfix(nums.size(), 1);
        vector<int> result;

        for (auto iter = nums.begin(); iter != prev(nums.end()); iter++) {
            prefix.push_back(prefix.back() * (*iter));
        }

        vector<int>::reverse_iterator post_iter = postfix.rbegin() + 1;
        for (auto iter = nums.rbegin(); iter != prev(nums.rend()); iter++) {
            *post_iter = *(prev(post_iter)) * (*iter);
            post_iter++;
        }

        result.push_back(postfix.front());
        for (int i = 1; i < nums.size() - 1; i++) {
            result.push_back(prefix.at(i) * postfix.at(i));
        }
        result.push_back(prefix.back());
        return result;
    }
};
