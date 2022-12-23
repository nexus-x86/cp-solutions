// https://dmoj.ca/problem/tss17b
// https://github.com/nexus-x86/cp-solutions
// Monday December 19 2022

#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll N, Q;
    cin >> N >> Q;

    vector<ld> houses;

    for (ll i = 0; i < N; i++)
    {
        ll x, y;
        cin >> x >> y;
        houses.push_back(sqrt(x * x + y * y));
    }
    sort(houses.begin(), houses.end());

    for (ll i = 0; i < Q; i++)
    {

        ll low = 0;
        ll high = N;

        ll hypothetical;
        cin >> hypothetical;

        while (low < high)
        {
            ll mid = (low + high) / 2;
            if (houses[mid] <= hypothetical)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        cout << low << "\n";
    }

    return 0;
}