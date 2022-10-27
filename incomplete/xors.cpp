// https://dmoj.ca/problem/xors
// https://github.com/nexus-x86/cp-solutions
// Wednesday October 26 2022 

#include <iostream>

using namespace std;


int main() {
    int N;
    cin >> N;
    int xorSum = 0;
    // prefix xor array needed?
    int prefixXor[N];
    int a;
    cin >> a;
    prefixXor[0] = a;
    for (int i = 1; i < N; i++) {
        int a;
        cin >> a;
        prefixXor[i] = prefixXor[i-1] ^ a;
        cout << prefixXor[i] << "\n";   
    }
    cout << xorSum << "\n";
}