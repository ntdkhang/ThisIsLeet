#include <string>
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int longest_len = 1;
        std::string longest_str = s.substr(0,1);
        int left = 0, right = 0;
        // 1 char as center
        for (int i = 1; i < s.size() - 1; i++) {
            left = i - 1;
            right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                if (right - left + 1 > longest_len) {
                    longest_len = right - left + 1;
                    longest_str = s.substr(left, longest_len);
                }
                right++;
                left--;
            }
        }

        // 2 char as center
        for (int i = 0; i < s.size() - 1; i++) {
            left = i;
            right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                if (right - left + 1 > longest_len) {
                    longest_len = right - left + 1;
                    longest_str = s.substr(left, longest_len);
                }
                right++;
                left--;
            }
        }

        return longest_str;
    }
};

