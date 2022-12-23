// https://dmoj.ca/problem/coci12c3p4
// https://github.com/nexus-x86/cp-solutions
// Monday December 19 2022

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    ll times[n];

    ll high = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> times[i];
        if (times[i] > high)
        {
            high = times[i];
        }
    }

    ll low = 0;
    high *= m; // the max times the number of delegates is the worst case scenario

    while (low < high)
    {
        ll mid = (low + high) / 2;
        ll mySum = 0;
        for (int i = 0; i < n; i++)
        {
            mySum += mid / times[i];
        }
        if (mySum < m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    cout << low << "\n";

    return 0;
}