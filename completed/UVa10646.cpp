// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=611&page=show_problem&problem=1587
// https://github.com/nexus-x86/cp-solutions
// Sunday January 1 2023

#include <iostream>
#include <unordered_map>
#include <stack>
#include <string>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    unordered_map<char, int> mapping = {
        {'A', 10},
        {'K', 10},
        {'Q', 10},
        {'J', 10},
        {'T', 10}};
    for (int j = 1; j <= N; j++)
    {
        int a = 52;
        stack<string> myCards;
        while (a--)
        {
            string b;
            cin >> b;
            myCards.push(b);
        }

        stack<string> top25;
        int iter = 25;
        while (iter--)
        {
            top25.push(myCards.top());
            myCards.pop();
        }

        int Y = 0;

        for (int i = 0; i < 3; i++)
        {
            string topCard = myCards.top();
            int val = mapping[topCard[0]];
            if (val == 0)
            {
                val = topCard[0] - '0';
            }
            Y += val;
            int howmany = 10 - val;
            myCards.pop();
            while (howmany--)
            {
                myCards.pop();
            }
        }

        iter = 25;
        while (iter--)
        {
            myCards.push(top25.top());
            top25.pop();
        }

        Y = myCards.size() - Y;
        while (Y--)
        {
            myCards.pop();
        }
        cout << "Case " << j << ": " << myCards.top() << "\n";
    }
}