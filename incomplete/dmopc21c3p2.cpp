// https://dmoj.ca/problem/dmopc21c3p2
// https://github.com/nexus-x86/cp-solutions
// Monday October 31 2022 

#include <iostream>
#include <vector>
#include <set>

using namespace std;

long long f(long long a, long long b) {
    return (a*(a+1)/2)+(b*(b-1)/2);
}

int main() {
    long long K;
    cin >> K;
    long long a = 1000000;
    long long b = 0;
    if (K == 0) {
        cout << "1" << "\n" << "1" << "\n";
        return 0;
    }
    while (a >= b && a > 0) {
        if (f(a,b) == K && a + b <= 1000000) {
            cout << a + b << "\n" << "0";
            for (int i = 1; i < a; i++) {
                cout << " 0";
            }
            if (b > 0) {
                cout << " 1";
                for (int i = 1; i < b; i++) {
                    cout << " 0";
                }
            }
            cout << "\n";
            return 0;
        }
        if (f(a,b) > K) {
            a--;
        } else {
            b++;
        }
    }
    cout << -1 << "\n";
}