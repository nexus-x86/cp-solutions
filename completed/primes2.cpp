// https://dmoj.ca/problem/primes2
// https://github.com/nexus-x86/cp-solutions
// Monday October 31 2022 

#include <bits/stdc++.h>
using namespace std;
vector<char> segmentedSieve(long long L, long long R) {
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<char> isPrime(R - L + 1, true);
    for (long long i : primes)  
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;

}
int main() {
    int low,high;
    cin >> low >> high;
    vector<char> sieve = segmentedSieve(low, high);
    for (int i = 0; i < high-low+1; i++) {
        if (sieve[i] == true) {
            cout << i +low << "\n";
        }
    }
}