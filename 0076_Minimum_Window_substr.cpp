#include <string>
#include <unordered_map>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        int counter = 0;
        size_t start = 0, end = 0, minStart = 0, minLength = INT_MAX;
        std::unordered_map<char, int> map;

        if (t.size() > s.size()) {
            return "";
        }

        for (char c: t) {
            map[c]++;
        }

        for (; end < s.size(); end++) {
            if (map[s[end]] > 0) {
                counter++;
            }
            map[s[end]]--;

            while (counter == t.size()) {
                if (end - start + 1 < minLength) {
                    minLength = end - start + 1;
                    minStart = start;
                }

                map[s[start]]++;
                if (map[s[start]] > 0) {
                    counter--;
                }

                start++;
            }
        }

        if (minLength == INT_MAX) {
            return "";
        }

        return s.substr(minStart, minLength);
    }
};
