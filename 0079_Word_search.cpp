#include <vector>
#include <string>
class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        std::vector<std::vector<bool>> travelled(board.size(), std::vector<bool>(board[0].size(), false));

        std::string::iterator curChar = word.begin();


        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {

            }
        }

        return false;
    }
};
