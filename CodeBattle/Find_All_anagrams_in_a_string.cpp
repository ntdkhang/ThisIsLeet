#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> findAnagrams_(string s, string p) {
        unordered_map<char, int> map_p, map_s;

        vector<int> res{};
        for (char c: p) {
            map_p[c]++;
        }
        int count = p.size();

        for (int i = 0; i < count; i++) {
            map_s[s.at(i)]++;
        }

        for (int i = count; i <= s.size(); i++) {
            bool isAna = true;
            for (auto x: map_p) {
                if (x.second != map_s[x.first]) {
                    isAna = false;
                    break;
                }
            }
            if (isAna) {
                res.push_back(i - count);
            }
            if (i != s.size()) {
                map_s[s.at(i)]++;
                map_s[s.at(i - count)]--;
            }
        }

        return res;
    }

    vector<int> findAnagrams_Correct(string s, string p) {
            // unordered_map<char, int> map_p, map_s;
        vector<int> map_p(26, 0), map_s(26,0);

        vector<int> res{};
        for (char c: p) {
            map_p.at(c - 'a')++;
        }
        int count = p.size(), curr_count = 0;

        for (int i = 0; i < count; i++) {
            map_s.at(s.at(i) - 'a')++;
        }

        for (int i = count; i <= s.size(); i++) {
            bool isAna = true;
            for (int j = 0; j < 26; j++) {
                if (map_p.at(j) != map_s.at(j)) {
                    isAna = false;
                    break;
                }
            }
            if (isAna) {
                res.push_back(i - count);
            }
            if (i != s.size()) {
                map_s.at(s.at(i) - 'a')++;
                map_s.at(s.at(i - count) - 'a')--;
            }
        }

        return res;
    }
};
