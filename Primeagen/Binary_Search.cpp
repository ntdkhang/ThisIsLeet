#include <vector>
#include <iostream>

using namespace std;

int my_binary_search(vector<int> haystack, int needle) {
    int left = 0, right = haystack.size() - 1;
    int middle = haystack.size() / 2;

    while (left < right) {
        middle = (left + right) / 2;
        if (haystack.at(middle) == needle) {
            return middle;
        } else if (haystack.at(middle) < needle) {
            left = middle + 1;
        } else if (haystack.at(middle) > needle) {
            right = middle;
        }
    }
    return -1;
}

int main() {
    std::vector<int> haystack = {1,3,4,7,8,9,10,13,14,15,17,19,20,24,25,27,29,40};
    cout << "found 9 at index: " << my_binary_search(haystack, 20) << endl;

    return 0;
}
