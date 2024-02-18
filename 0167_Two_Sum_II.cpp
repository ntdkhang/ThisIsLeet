#include <vector>

using namespace std;

class Solution {
public:
    int bsearch(vector<int>& numbers, int target, int left = 0) {
        int r = numbers.size();
        int l = left;
        int m;

        while (l < r) {
            m = (l+r) / 2;
            if (numbers.at(m) == target) {
                return m+1; // 1-indexed
            } else if (numbers.at(m) > target) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return -1;
    }

    /*
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret;
        int i2;
        int find;
        for (int i = 0; i < numbers.size(); i++) {
            find = target - numbers.at(i);
            i2 = bsearch(numbers, find, i+1);
            if (i2 != -1) {
                ret.push_back(i+1);
                ret.push_back(i2);
            }
        }
        return ret;
    }
    // */

    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret;
        int l=0, r=numbers.size()-1;
        while (l < r) {
            if (numbers[l] + numbers[r] == target) {
                ret.push_back(l+1);
                ret.push_back(r+1);
                return ret;
            } else if (numbers[l] + numbers[r] > target) {
                --r;
            } else {
                ++l;
            }
        }
        return ret;
    }

};
