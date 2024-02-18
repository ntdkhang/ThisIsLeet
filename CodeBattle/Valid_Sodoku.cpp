#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // write your code here

        // check horizontal lines
        for (int i = 0; i < 9; i++) {
            vector<int> count(10, 0);
            for (int j = 0; j < 9; j++) {
                char c = board.at(i).at(j);
                if (c != '.') {
                    if (count.at(c - '1')++ > 0) {
                        return false;
                    }
                }

            }
        }

        // check vertical lines
        for (int i = 0; i < 9; i++) {
            vector<int> count(10, 0);
            for (int j = 0; j < 9; j++) {
                char c = board.at(j).at(i);
                if (c != '.') {
                    if (count.at(c - '1')++ > 0) {
                        return false;
                    }
                }

            }
        }


        // check box
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                vector<int> count(10, 0);
                for (int k = 0; k < 3; i++) {
                    for (int l = 0; l < 3; j++) {
                        char c = board.at(i*3 + k).at(j*3 + l);
                        if (c != '.') {
                            if (count.at(c - '1')++ > 0) {
                                return false;
                            }
                        }
                    }
                }
            }
        }


        return true;

    }

};
