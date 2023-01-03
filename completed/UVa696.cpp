// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=612&page=show_problem&problem=637
// https://github.com/nexus-x86/cp-solutions
// Sunday January 1 2023

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int M, N;
    while (cin >> M >> N)
    {
        if (M == 0 && N == 0)
        {
            return 0;
        }
        int ans = (M * N) - (M * N) / 2;
        int minimum = min(M, N);
        int maxNum = max(M, N);
        if (M == 0 || N == 0)
        {
            ans = 0;
        }
        else if (M == 1 || N == 1)
        {
            ans = M * N;
        }
        else if (M == 2 || N == 2)
        {
            // group the knights into blocks of 4 (2x2)
            ans = 4 * (int)(maxNum / 4) + 2 * min(2, maxNum % 4);
        }
        cout << ans << " knights may be placed on a " << M << " row " << N << " column board.\n";
    }
}