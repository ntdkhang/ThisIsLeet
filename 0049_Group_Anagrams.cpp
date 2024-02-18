#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string str1, string str2) {
        vector<int> map(26,0);
        if (str1.length() != str2.length()) {
            return false;
        }
        for (char c : str1) {
            map.at(c - 'a')++;
        }

        for (char c : str2) {
            map.at(c - 'a')--;
        }

        for (int i : map) {
            if (i != 0) {
                return false;
            }
        }

        return true;
    }

    string reorder(string str) {
        string res;
        vector<int> map(26,0);
        for (char c : str) {
            map.at(c - 'a')++;
        }
        for (int i = 0; i < map.size(); i++) {
            for (int j = 0; j < map.at(i); j++) {
                char c = 'a' + i;
                res = res + c;
            }
        }
        return res;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        for (string str : strs) {
            string reordered_str = reorder(str);
            // if (map.find(reordered_str) == map.end()) {
            map[reordered_str].push_back(str);
            // }
        }
        for (auto x : map) {
            res.push_back(x.second);
        }
        return res;
    }
};

int main() {
    string str = "ccaadsfjlkdd";
    Solution sol;
    cout << sol.reorder(str) << " " << (sol.reorder(str) == "aaccdddfjkls");
}
