// https://dmoj.ca/problem/ccc07j4
// https://github.com/nexus-x86/cp-solutions
// Monday December 26 2022

#include <utility>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    // use 2 frequency arrays for each input
    string a;
    string b;
    getline(cin, a);
    getline(cin, b);
    map<char, int> f1;
    map<char, int> f2;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == ' ')
        {
            continue;
        }
        f1[a[i]]++;
    }
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] == ' ')
        {
            continue;
        }
        f2[b[i]]++;
    }

    if (f1.size() == f2.size() && equal(f1.begin(), f1.end(), f2.begin()))
    {
        cout << "Is an anagram.\n";
    }
    else
    {
        cout << "Is not an anagram.\n";
    }

    return 0;
}