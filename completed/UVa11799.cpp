// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=342&page=show_problem&problem=2899
// https://github.com/nexus-x86/cp-solutions
// Friday December 30 2022

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int a;
    cin >> a;
    cin.ignore();
    for (int i = 1; i <= a; i++)
    {
        int max = -1;
        string a;
        getline(cin, a);
        stringstream stream(a);
        while (true)
        {
            int n;
            stream >> n;
            if (!stream)
            {
                break;
            }
            if (n > max)
            {
                max = n;
            }
        }
        cout << "Case " << i << ": " << max << "\n";
    }
}