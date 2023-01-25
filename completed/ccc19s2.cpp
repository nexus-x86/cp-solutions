// https://dmoj.ca/problem/ccc19s2
// https://github.com/nexus-x86/cp-solutions
// Wednesday January 25 2023

#include <iostream>
#include <vector>

using namespace std;

const int mx = 2*1e6;

int main() {    
    cin.sync_with_stdio(0);
    cin.tie(0);

    // input specifications say that max n is 1000000
    // so use sieve to precompute primes

    vector<bool> isPrime(mx + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i <= mx; i++) {
        if (isPrime[i] && (long long) i * i  <= mx) {
            for (int j = i * i; j <= mx; j+= i ) {
                isPrime[j] = false;
            }
        }
    }
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        a *= 2;
        int num1;
        int num2;
        for (int j = 2; j <= mx; j++){ 
            if (isPrime[j] == false) {
                continue;
            }
            if (isPrime[a-j]) {
                num1 = j;
                num2 = a - j;
                break;
            }
        }
        cout << num1 << " " << num2 << "\n";
    }
}