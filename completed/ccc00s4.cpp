// https://dmoj.ca/problem/ccc00s4
// https://github.com/nexus-x86/cp-solutions
// Tuesday December 27 2022

#include <iostream>
#include <algorithm>
using namespace std;

const int mx = 5290;
const int INF = 1e6;
int dp[mx];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int dist, C;
    cin >> dist >> C;
    int dp[dist * 2 + 5];

    for (int i = 0; i < dist + 5; i++)
    {
        dp[i] = INF;
    }

    for (int i = 0; i < C; i++)
    {
        int a;
        cin >> a;
        dp[a] = 1;
    }

    for (int i = 0; i <= dist; i++)
    {
        for (int j = 0; j <= dist; j++)
        {
            dp[i + j] = min(dp[i + j], dp[i] + dp[j]);
        }
    }

    if (dp[dist] == INF)
    {
        cout << "Roberta acknowledges defeat.\n";
    }
    else
    {
        cout << "Roberta wins in " << dp[dist] << " strokes.\n";
    }
}