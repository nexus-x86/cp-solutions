// http://usaco.org/index.php?page=viewproblem2&cpid=1252
// https://github.com/nexus-x86/cp-solutions
// Saturday January 14 2023

#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        string cows;
        cin >> N >> K >> cows;
        // plant a patch + K from an uncovered cow to cover the most distance
        
        string configuration(cows.size(), '.');
        int patches = 0; 
        for (int i = 0; i < cows.size(); i++) {
            if (cows[i] != '.') {
                int minus = 0;
                while (i + K - minus > cows.size() || configuration[i+K-minus] != '.') {
                    minus++;
                }
                configuration[i+K-minus] = cows[i];
                patches++;
                for (int j = i; j <= i + K + K; j++) {
                    if (cows[j] == configuration[i+K-minus]) {
                        cows[j] = '.';
                    }
                }
            }
        }
        cout << patches << "\n" << configuration << "\n";
    }
}