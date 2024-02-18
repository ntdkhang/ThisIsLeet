class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1, temp;
        for (int i = 1; i <= n; i++) {
            temp = a;
            a += b;
            b = temp;
        }
        return a;
    }
};
