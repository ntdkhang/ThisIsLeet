#include <vector>
#include <string>

class Solution {
public:
    void sortPeople(std::vector<std::string>& names, std::vector<int>& heights, int left, int right) {
        if (left >= right) {
            return;
        }

        int pivot_idx = partition(names, heights, left, right);
        sortPeople(names, heights, left, pivot_idx - 1);
        sortPeople(names, heights, pivot_idx + 1, right);
    }

    int partition(std::vector<std::string>& names, std::vector<int>& heights, int left, int right) {
        int pivot = heights[right];
        int idx = left;

        for (int i = left; i < right; i++) {
            if (heights[i] >= pivot) {
                std::swap(heights[i], heights[idx]);
                std::swap(names[i], names[idx]);
                idx++;
            }
        }
        std::swap(heights[right], heights[idx]);
        std::swap(names[right], names[idx]);

        return idx;
    }

    std::vector<std::string> sortPeople(std::vector<std::string>& names, std::vector<int>& heights) {
        sortPeople(names, heights, 0, names.size() - 1);
        return names;
    }
};
