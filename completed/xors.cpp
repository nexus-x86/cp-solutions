// https://dmoj.ca/problem/xors
// https://github.com/nexus-x86/cp-solutions
// Wednesday October 26 2022 

/*
Editorial:
Dangerously easy to overcomplicate this problem.
No special technique used.
Problem solvers will have to realize that the minimum XOR sum is just the entire
list XOR'D, and the maximum XOR sum is each individual element added
*/

#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    long long min = 0;
    long long max = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        min ^= x;
        max += x;
    }
    cout << max - min << "\n";
}