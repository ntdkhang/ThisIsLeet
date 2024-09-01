#include <vector>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
        int i = 0, j = 0;
        int med1 = (nums1.size() + nums2.size()) / 2;
        int med2;
        if ((nums1.size() + nums2.size()) % 2  == 0) {
            med2 = med1 - 1;
        } else {
            med2 = med1;
        }

        int curIdx = 0, num1 = 0, num2 = 0;
        int curNum = 0;
        while (curIdx <= med1) {
            if (j == nums2.size()) {
                curNum = nums1[i];
                i++;
            } else if (i == nums1.size()) {
                curNum = nums2[j];
                j++;
            } else if (nums1[i] <= nums2[j]) {
                curNum = nums1[i];
                i++;
            } else if (nums1[i] >= nums2[j]) {
                curNum = nums2[j];
                j++;
            }

            if (curIdx == med1) {
                num1 = curNum;
            }
            if (curIdx == med2) {
                num2 = curNum;
            }

            curIdx++;
        }

        return ((double)num1 + num2) / 2;
   }
};

