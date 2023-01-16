// https://dmoj.ca/problem/ccc22s1
// https://github.com/nexus-x86/cp-solutions
// Saturday January 7 2023

#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll N;
    cin >> N;
    ll counter = 0;
    for (int i = 0; i <= N / 5; i++) {
        if ((N - 5*i) % 4 == 0) {
            counter++;
        }
    }
    cout << counter << "\n";
}