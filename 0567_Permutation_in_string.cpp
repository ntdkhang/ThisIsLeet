#include <string>
#include <vector>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        std::vector<int> freq(26,0);
        int countNonZero;
        if (s1.size() < s2.size()) {
            return false;
        }

        for (char c : s2) {
            if (freq[c - 'a'] == 0) {
                countNonZero++;
            }
            freq[c - 'a']++;
        }

        for (int i = 0; i < s2.size(); i++) {
            freq[s1[i] - 'a']--;
            if (freq[s1[i] - 'a'] == 0) {
                countNonZero--;
            } else if (freq[s1[i] - 'a'] == -1) {
                countNonZero++;
            }
        }

        if (countNonZero == 0) {
            return true;
        }

        for (int i = s2.size(); i < s1.size(); i++) {
            // insert back
            freq[s1[i] - 'a']--;
            if (freq[s1[i] - 'a'] == 0) {
                countNonZero--;
            } else if (freq[s1[i] - 'a'] == -1) {
                countNonZero++;
            }


            // remove front
            freq[s1[i - s2.size()] - 'a']++;
            if (freq[s1[i - s2.size()] - 'a'] == 0) {
                countNonZero--;
            } else if (freq[s1[i - s2.size()] - 'a'] == 1) {
                countNonZero++;
            }

            if (countNonZero == 0) {
                return true;
            }
        }
        return false;
    }
};
