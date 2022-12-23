// https://dmoj.ca/problem/dmopc19c5p4
// https://github.com/nexus-x86/cp-solutions
// Tuesday December 20 2022

#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll N, Q;
    cin >> N >> Q;

    ll money[N];
    for (ll i = 0; i < N; i++)
    {
        cin >> money[i];
    }

    ll bully[N];
    for (ll i = 0; i < N; i++)
    {
        cin >> bully[i];
    }
    // precompute the maximum money V can extort from this person

    ll maxMoney[N];
    for (ll i = 0; i < N; i++)
    {
        ll currMoney = money[i];
        ll currVictim = bully[i];
        while (currVictim != 0)
        {
            currMoney += money[currVictim - 1];
            currVictim = bully[currVictim - 1];
        }
        maxMoney[i] = currMoney;
    }

    for (ll i = 0; i < Q; i++)
    {
        ll P, C;
        cin >> P >> C;
        if (P >= C)
        {
            cout << -1 << "\n";
            continue;
        }
        // print the person with the least index that satisfies
        // the condition of paying for his lunch
        // each person may only extort one other person
        //

        // victim arrays are 1 indexed

        // We have P dollars and we need C;
        C -= P;
        int flag = 0;
        for (ll j = 0; j < N; j++)
        {
            if (maxMoney[j] >= C)
            {
                cout << j + 1 << "\n";
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << -1 << "\n";
        }
    }

    return 0;
}