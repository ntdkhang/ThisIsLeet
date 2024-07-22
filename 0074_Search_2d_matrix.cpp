#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int row_count = matrix.size(), col_count = matrix[0].size();
        int left = 0, right = row_count * col_count;
        while (left < right) {
            int mid = (left + right) / 2;
            int row = mid / col_count;
            int col = mid % col_count;
            int num = matrix[row][col];
            if (num == target) {
                return true;
            } else if (num > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return false;
    }
};
