#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // write your code here
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                triangle.at(i).at(j) += min(triangle.at(i+1).at(j), triangle.at(i+1).at(j+1));
            }
        }
        return triangle.at(0).at(0);
    }
};

/*
   2
  3 4
 6 5 7
4 1 8 3
*/
