// https://codeforces.com/contest/16/problem/B
// https://github.com/nexus-x86/cp-solutions
// Saturday January 21 2023

#include <iostream>
#include <queue>

using namespace std;

int main() {    
    cin.sync_with_stdio(0);
    cin.tie(0);

    priority_queue<pair<long long,long long>> myPQ;

    long long n, m;
    cin >> n >> m;

    // m containers
    // a, b
    // a boxes, b matches per box

    // can hold a max of n matchboxes exactly
    for (long long i = 0; i < m; i++) {
        long long a,b;
        cin >> a >> b;
        myPQ.push({b,a});
    }

    long long score = 0;

    while (n > 0 && !myPQ.empty()) {
        pair<long long,long long> top = myPQ.top();
        myPQ.pop();

        long long maxBoxes = min(top.second, n);

        score += top.first * maxBoxes;

        n -= maxBoxes;
    }

    cout << score << "\n";
}