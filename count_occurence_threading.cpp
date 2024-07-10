#include <iostream>
#include <string>

int countOccurence(std::string str, char letter) {
    int count = 0;
    for (char c: str) {
        if (c == letter) {
            count++;
        }
    }
    return count;
}
int main() {
    std::cout << countOccurence("abcaabbdcadkjsavla", 'a');
}
