#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // write your code here
        unordered_map<int, int> map;
        for (int num : arr) {
            map[num] += 1;
            if (num == 0) {
                if(map[num] == 2)
                    return true;
            } else if ((num % 2 == 0 && map.find(num/2) != map.end()) || map.find(num*2) != map.end()) {
                return true;
            }
        }


        return false;
    }
};
