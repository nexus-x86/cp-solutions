// https://dmoj.ca/problem/ccc15s2
// https://github.com/nexus-x86/cp-solutions
// Saturday November 5

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int mx = 1e6+5;
char jerseys[mx];


int main() {
    int J, A;
    cin >> J >> A;
    int count = 0;
    for (int i = 0; i < J; i++) {
        cin >> jerseys[i];
    }
    for (int i = 0; i < A; i++) {
        char size;
        int num;
        cin >> size >> num;
        if (size == 'S') {
            if (jerseys[num-1] == 'S' || jerseys[num-1] == 'M' || jerseys[num-1] == 'L') {
                count++;
                jerseys[num-1] = ' ';
            }
        } else if (size == 'M') {
            if (jerseys[num-1] == 'M' || jerseys[num-1] =='L') {
                count++;
                jerseys[num-1] = ' ';
            }
        } else if (size == 'L' &&   jerseys[num-1] == 'L') {
            count++;
            jerseys[num-1] = ' ';
         }   
    }
    cout << count << "\n";
}