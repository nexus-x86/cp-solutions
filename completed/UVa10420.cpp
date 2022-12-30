// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=1361
// https://github.com/nexus-x86/cp-solutions
// Thursday December 29 2022

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    map<string, int> myMap;
    cin.ignore();
    while (N--)
    {
        string a;
        getline(cin, a);
        a = a.substr(0, a.find(' '));
        myMap[a]++;
    }
    for (pair<string, int> a : myMap)
    {
        cout << a.first << " " << a.second << "\n";
    }
}