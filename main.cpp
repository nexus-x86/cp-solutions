#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll n,m;
    cin >> n >> m;
    ll prefix[n+1];
    prefix[0] = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> prefix[i];
        prefix[i] += prefix[i-1];
    }
    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        cout << prefix[b] - prefix[a] << "\n";
    }
}