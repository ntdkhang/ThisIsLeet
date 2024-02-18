#include <iostream>


class Solution {
public:
    int kthFactor(unsigned long long n, unsigned long long k) {
        unsigned long long count = 0;
        for (unsigned long long i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                count++;
            }
            if (count == k) {
                return i;
            }
        }

        unsigned long long root = round(sqrt(n));
        if (root * root == n) {
            count--;
        }
        for (unsigned long long i = sqrt(n); i >= 1; i--) {
            if (n % i == 0) {
                count++;
            }
            if (count == k) {
                return n / i;
            }
        }

        return -1;

    }
};
