#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> map(26, 0);

        for (char c : s) {
            map.at(c - 'a')++;
        }

        for (char c : t) {
            map.at(c - 'a')--;
        }

        for (int i : map) {
            if (i != 0) {
                return false;
            }
        }
        return true;
    }
};
