// https://dmoj.ca/problem/xors
// https://github.com/nexus-x86/cp-solutions
// Wednesday October 26 2022 

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