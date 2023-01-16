// https://dmoj.ca/problem/dmopc22c3p1
// https://github.com/nexus-x86/cp-solutions
// Friday December 30 2022

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    // this problem is a massive bruh moment
    cin.sync_with_stdio(0);
    cin.tie(0);

    long long N, M;
    cin >> N >> M;
    if (N % 2 == 0 || M % 2 == 0)
    {
        cout << (N * M) / 2 << " " << (N * M) / 2 << "\n";
    }
    else
    {
        cout << (N * M) / 2 + 1 << " " << N * M - ((N * M) / 2 + 1) << "\n";
    }
}
