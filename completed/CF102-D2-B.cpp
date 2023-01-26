// https://codeforces.com/contest/102/problem/B
// https://github.com/nexus-x86/cp-solutions
// Sunday January 22 2023

#include <iostream>
#include <string>

using namespace std;

string sumOfDigits(string n) {
    int sum = 0;
    for (char c : n) {
        sum += c - '0';
    }
    return to_string(sum);
}

int main() {    
    cin.sync_with_stdio(0);
    cin.tie(0);

    string n;
    cin >> n;

    int counter = 0;
    while (n.size() != 1) {
        counter++;
        n = sumOfDigits(n);
    }

    cout << counter << "\n";
}