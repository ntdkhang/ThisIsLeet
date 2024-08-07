#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int left = 0, right = matrix.size() * n - 1;
        int midIdx;
        int col, row;
        int num;

        while (left <= right) {
            midIdx = (left + right) / 2;
            row = midIdx / n;
            col = midIdx % n;
            num = matrix[row][col];

            if (num == target) {
                return true;
            } else if (num > target) {
                right = midIdx - 1;
            } else {
                left = midIdx + 1;
            }
        }

        return false;
    }
};

