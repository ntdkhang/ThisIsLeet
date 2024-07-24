#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        std::vector<int> freq(26, 0);
        int left = 0, right = 0;
        int maxFreq = 0, maxCount = 0;

        while (right < s.size()) {
            freq[s[right] - 'A']++;
            maxFreq = std::max(maxFreq, freq[s[right] - 'A']);

            int length = right - left + 1;
            if (length - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }
            right++;
        }

        int res = maxFreq + k;
        return std::min(res, static_cast<int>(s.size()));
    }
};
