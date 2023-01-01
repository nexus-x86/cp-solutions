// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=612&page=show_problem&problem=214
// https://github.com/nexus-x86/cp-solutions
// Sunday January 1 2023

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int p;
    cin >> p;
    while (p--)
    {
        char a;
        int m, n;
        cin >> a >> m >> n;

        /*
        r -- rook
        k -- knight
        Q -- queen
        K -- king
        */
        if (a == 'r')
        {
            cout << min(m, n) << '\n';
        }
        else if (a == 'k')
        {
            if (m * n % 2 == 1)
            {
                cout << m * n / 2 + 1 << "\n";
            }
            else
            {
                cout << m * n / 2 << "\n";
            }
        }
        else if (a == 'Q')
        {
            cout << min(m, n) << "\n";
        }
        else if (a == 'K')
        {
            cout << (((m + 1) / 2) * ((n + 1) / 2)) << "\n";
        }
    }
}