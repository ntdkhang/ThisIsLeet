#include <algorithm>
#include <string>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        // AACCBBB
        if (s.size() == 1) {
            return 1;
        }
        int changes = k, count = 1, maxCount = 0;
        std::string::iterator start = s.begin(), current = s.begin() + 1, nextJump = s.begin();

        while (start != s.end() && current != s.end()) {
            if (*current == *start) {
                count++;
                current++;
            } else {
                if (changes > 0) {
                    if (nextJump == start) {
                        nextJump = current;
                    }
                    changes--;
                    count++;
                    current++;
                } else { // reset
                    if (nextJump != start) {
                        start = nextJump;
                    } else {
                        start++;
                    }
                    nextJump = start;
                    current = start+1;
                    maxCount = std::max(count, maxCount);
                    changes = k;
                    count = 1;
                }
            }

        }
        count = 1;

        for (auto it = s.rbegin() + 1; it != s.rend(); it++) {
            if (*it != *(it-1)) {
                break;
            } else {
                count++;
            }
        }

        maxCount = std::max(count + changes, maxCount);

        if (maxCount > s.size()) {
            return s.size();
        }

        return maxCount;
    }
};
