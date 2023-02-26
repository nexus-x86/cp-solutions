// https://dmoj.ca/problem/ccc22s3
// https://github.com/nexus-x86/cp-solutions
// Thursday December 22 2022

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    if (N > K || N * M - ((M - 1) * M) / 2 < K) {
        cout << -1 << "\n";
        return 0;
    }

    // N integers between 1 and M with exactly K good samples
    int music[N];
    K -= N;

    for (int i = 1; i <= N; i++) {
        music[0] += 1;

        int minimum = min({i, M, K + 1});
        music[i] = music[i-minimum];
        K -= minimum - 1;
    }

    for (int i = 1; i <= N; i++) {
        cout << music[i] << " ";
    }
    cout << "\n";


    return 0;
}