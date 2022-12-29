// https://dmoj.ca/problem/acc2p2
// https://github.com/nexus-x86/cp-solutions
// Tuesday December 6 2022

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <bitset>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll INF = 99999;


int main() {
    ll N;
    cin >> N;
    
    //ll AM[N][N];
    //memset(AM, 0, sizeof(AM[0][0]) * N * N);
    vector<bitset<500>> AM(N);
    for (ll i = 0; i < N; i++) {
        string a;
        cin >> a;
        AM[i][i] = 1;
        for (ll j = 0; j < N; j++) {
            if (a.at(j) == '1') {
                AM[i][j] = 1;
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (AM[j][i]) {
                AM[j] |= AM[i];
            }
        }
    }


    ll counter = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if ((AM[i][j] | AM[j][i]) == 0) {
                counter++;
            }
        }
    }
    cout << counter << "\n";
}