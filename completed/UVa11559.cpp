// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=27&page=show_problem&problem=2595
// https://github.com/nexus-x86/cp-solutions
// Thursday December 29 2022

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, B, H, W;
    while (cin >> N >> B >> H >> W)
    {
        int minimum = 1e9;
        while (H--)
        {
            int p;
            cin >> p;
            for (int i = 0; i < W; i++)
            {
                int a;
                cin >> a;
                if (a >= N)
                {
                    minimum = min(minimum, N * p);
                }
            }
        }
        if (minimum > B)
        {
            cout << "stay home\n";
        }
        else
        {
            cout << minimum << "\n";
        }
    }
}