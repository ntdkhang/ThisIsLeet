#include <string>
#include <unordered_map>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.size() < t.size()) {
            return "";
        }
        std::unordered_map<char, int> freq;
        int count = 0, minLength = s.size() + 1;
        int minLeft = 0;
        std::string res = "";

        for (char c: t) {
            if (freq[c] == 0) {
                count++;
            }
            freq[c]++;
        }

        int left = 0, right = 0;
        while (right < s.size()) {
            if (freq.find(s[right])!= freq.end()) {
                freq[s[right]]--;
                if (freq[s[right]] == 0) {
                    count--;
                }

                while (count == 0) {
                    if (right - left + 1 < minLength) {
                        minLength = right - left + 1;
                        minLeft = left;
                    }
                    if (freq.find(s[left]) != freq.end()) {
                        freq[s[left]]++;
                        if (freq[s[left]] == 1) {
                            count++;
                        }
                    }
                    left++;
                }
            }
            right++;
        }
        if  (minLength != s.size() + 1) {
            res = s.substr(minLeft, minLength);
        }

        return res;
    }
};
