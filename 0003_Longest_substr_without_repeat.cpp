#include <algorithm>
#include <string>
#include <unordered_set>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> appeared;
        size_t start = 0;
        int count = 0, maxCount = 0;

        for (size_t end = 0; end < s.size(); end++) {
            if (appeared.find(s[end]) == appeared.end()) {
                count++;
                appeared.insert(s[end]);
            } else {
                maxCount = std::max(count, maxCount);

                while (s[start] != s[end]) {
                    appeared.erase(s[start]);
                    start++;
                    count--;
                }
                start++;
            }
       }
        maxCount = std::max(count, maxCount);
        return maxCount;
    }
};
