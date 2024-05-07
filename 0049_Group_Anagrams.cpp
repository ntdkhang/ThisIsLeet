#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> result;
        for (string word : strs) {
            string sorted = reorder(word);
            map[sorted].push_back(word);
        }

        for (auto it = map.begin(); it != map.end(); it++) {
            result.push_back(it->second);
        }

        return result;
    }

    string reorder(const string& word) {
        string temp = word;
        sort(temp.begin(), temp.end());
        return temp;
    }
};

int main() {}
