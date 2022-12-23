// https://dmoj.ca/problem/ccc22s3
// https://github.com/nexus-x86/cp-solutions
// Thursday December 22 2022

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    // N notes, M possible pitches, K good samples
    vector<int> notes(N, 0);

    // We can only use notes less than or equal to M
    // Each note is it's own good sample.

    return 0;
}