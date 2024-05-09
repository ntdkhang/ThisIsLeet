#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        return isValidSquare(board) && isValidHorizontal(board) && isValidVertical(board);
    }

    bool isValidSquare(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {
                if (!isValidSquareLocal(board, row, col)) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSquareLocal(vector<vector<char>>& board, int rowStart, int colStart) {
        vector<bool> map(9, false);
        for (int row = rowStart; row < rowStart + 3; row++) {
            for (int col = colStart; col < colStart + 3; col++) {
                int num = 0;
                if (isdigit(board[row][col])) {
                    num = board[row][col] - '0';
                    if (map[num] == true) {
                        return false;
                    } else {
                        map[num] = true;
                    }
                }
            }
        }
        return true;
    }

    bool isValidHorizontal(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            vector<bool> map(9, false);
            for (int col = 0; col < 9; col++) {
                int num = 0;
                if (isdigit(board[row][col])) {
                    num = board[row][col] - '0';
                    if (map[num] == true) {
                        return false;
                    } else {
                        map[num] = true;
                    }
                }
            }
        }
        return true;
    }

    bool isValidVertical(vector<vector<char>>& board) {
        for (int col = 0; col < 9; col++) {
            vector<bool> map(9, false);
            for (int row = 0; row < 9; row++) {
                int num = 0;
                if (isdigit(board[row][col])) {
                    num = board[row][col] - '0';
                    if (map[num] == true) {
                        return false;
                    } else {
                        map[num] = true;
                    }
                }
            }
        }
        return true;
    }
};
