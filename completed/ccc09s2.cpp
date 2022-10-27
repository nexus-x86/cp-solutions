// https://dmoj.ca/problem/ccc09s2
// https://github.com/nexus-x86/cp-solutions
// Saturday October 22 2022

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int rows, columns;
vector<int> grid;

int main() {
    cin >> rows >> columns;
    for (int i = 0; i < rows; i++) {
        int n = 0;
        for (int j = 0; j < columns; j++) {
            int d;
            cin >> d;
            n = ((n << 1) | d); 
            // moves the binary to the left and adds a zero (multiplying 2)
            // and then | d.
            // bitwise or
            // 0 | 0 = 0
            // 0 | 1 = 1
            // 1 | 0 = 1
            // 1 | 1 = 1
        }
        // at the end, n is converted into decimal
        grid.push_back(n);
    }
    set<int> xors;
    int last = 0;
    // 0 xor X = X
    for (int i = rows-1; i >= 0; i--) {
        last = last ^ grid[i]; // xor calculating the bottom row
        xors.insert(last);
    }
    cout << xors.size() << "\n";
}