#include <iostream>

using namespace std;

int main() {
    // literally just a line going left to right or something.
    int left = 0;
    int right = 10;
    int points[] = {0,5,2,5,4,5,6,5,8,5};
    for (int i = left; i <= right; i++) {
        if (points[i] == i) {
            cout << i << "\n";
        }
    }
}