// https://codeforces.com/contest/709/problem/A
// https://github.com/nexus-x86/cp-solutions
// Wednesday January 18 2023

#include <iostream>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, b, d;
    cin >> n >> b >> d;

    int counter = 0;
    int squeezed = 0;

    while (n--) {
        int a;
        cin >> a;

        if (a > b) {
            continue;
        }

        squeezed += a;
        if (squeezed > d) {
            squeezed = 0;
            counter++;
        }
    }
    cout << counter << "\n";
}