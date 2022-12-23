// https://dmoj.ca/problem/champions
// https://github.com/nexus-x86/cp-solutions
// Wednesday December 21 2022

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;

    ll vArray[n];
    // ll vArray2[n];
    vector<ll> vArray2(n, 0);
    unordered_map<ll, ll> friends;

    for (ll i = 0; i < n; i++)
    {
        cin >> vArray[i];
        vArray2[i] = vArray[i];
    }

    for (ll i = 0; i < k; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;

        if (vArray[a] > vArray[b])
        {
            friends[a]++;
        }
        if (vArray[b] > vArray[a])
        {
            friends[b]++;
        }
    }

    sort(vArray2.begin(), vArray2.end());
    /*
    for (int i = 0; i < n; i++)
    {
        cout << vArray2[i] << " ";
    }
    cout << "\n";
    */
    for (ll i = 0; i < n; i++)
    {
        ll power = vArray[i];
        power--; // Some elements might be the same, so we look for the highest element less than power
        // upper bound can also be used to solved this
        ll lo = 0;
        ll hi = n - 1;

        while (lo < hi)
        {
            ll mid = (lo + hi) / 2;
            if (vArray2[mid] <= power)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }

        cout << lo - friends[i] << " ";
    }

    return 0;
}