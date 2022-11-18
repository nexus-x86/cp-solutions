// https://dmoj.ca/problem/cco20p1
// https://github.com/nexus-x86/cp-solutions
// Saturday November 5

#include <iostream>
#include <math.h>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    ll N, L, R;
    long double Y;
    cin >> N >> L >> R >> Y;
    unordered_map<ll,ll> numToPeople;
    unordered_map<ll,ll> counter;
    for (ll i = 0; i < N; i++) {
        long double xi, vi, hi;
        cin >> xi >> vi >> hi;
        long double left = (hi/vi) * (Y + (vi/hi)*xi);
        long double right = (hi/-vi) * (Y + (-vi/hi) * xi);
        long double a = min(left,right);
        right = max(left,right);
        left = a;
        left = (ll)floor(left);
        right = (ll)ceil(right);

        if (left < L) {
            numToPeople[L] += 1;
        } else {
            numToPeople[left] += 1;
        }
        if (right-1 > R) {
            numToPeople[R] -= 1;
        } else {
            numToPeople[right-1] -= 1;
        }
    }
    for (ll i = L; i <= R; i++) {
        if (i != L) {
            numToPeople[i] += numToPeople[i-1];
        }
        //cout << numToPeople[i] << " ";
        counter[numToPeople[i]] += 1;
    }
    cout << "\n";
    ll previous = 0;
    ll current = 0;
    for (ll i = 0; i <= N; i++) {
        current = counter[i];
        cout << current + previous << "\n";
        previous += current;
    }
}