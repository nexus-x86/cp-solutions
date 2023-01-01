// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=611&page=show_problem&problem=3399
// https://github.com/nexus-x86/cp-solutions
// Sunday January 1 2023

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int A, B, C, X, Y;
    while (cin >> A >> B >> C >> X >> Y)
    {
        if (A == 0 && B == 0 && C == 0 && X == 0 && Y == 0)
        {
            return 0;
        }
        int visited[60];
        memset(visited, 0, sizeof(visited));
        vector<int> M = {A, B, C};
        vector<int> N = {X, Y};
        sort(M.begin(), M.end());
        sort(N.begin(), N.end());
        visited[A] = 1;
        visited[B] = 1;
        visited[C] = 1;
        visited[X] = 1;
        visited[Y] = 1;

        // fail as many cards as possible (match with smallest card they can fail with )
        // and with the remaining cards,
        // match the remaining card with the smallest card they can beat

        // if it is impossible to fail any of the princes card, the remaining
        // card can be 1

        // if we can only fail 1 card, the remaining card will be
        // the second largest + 1

        // if we can fail all cards, it is impossible to guarantee a win.

        int fails = 0;
        int answer = -1;
        vector<int>::iterator upper;
        for (int i = 0; i < 2; i++)
        {
            upper = upper_bound(M.begin(), M.end(), N[i]);
            if (upper != M.end())
            {
                fails++;
                M.erase(upper);
            }
        }
        if (fails == 0)
        {
            answer = 1;
        }
        else if (fails == 1)
        {
            answer = M[1] + 1;
        }
        else if (fails == 2)
        {
            cout << answer << "\n";
            continue;
        }
        while (visited[answer] == 1)
        {
            answer = answer + 1;
        }
        if (answer >= 53)
        {
            cout << -1 << "\n";
            continue;
        }
        cout << answer << "\n";
    }
}