#include <iostream>
#include <vector>

using namespace std;

void Bubble_Sort(vector<int> &arr) {
    for (size_t i = arr.size() - 1; i > 0; i--) {
        for (size_t j = 0; j < i; j++) {
            if (arr.at(j) > arr.at(i)) {
                int temp = arr.at(j);
                arr.at(j) = arr.at(i);
                arr.at(i) = temp;
            }
        }
    }
}

int main() {
    vector<int> arr {1, 3, 7, 4, 2, 5};
    Bubble_Sort(arr);
    for (int a : arr) {
        cout << a << " ";
    }
    cout << endl;
}
