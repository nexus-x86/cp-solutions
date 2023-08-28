// https://dmoj.ca/problem/wc01sp3
// https://github.com/nexus-x86/cp-solutions
// Monday August 28 2023

#include <iostream>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

const int mx = 32;
int beer[mx][mx][mx];
int visited[mx][mx][mx];

int dirX[6] = {-1,1,0,0,0,0};
int dirY[6] = {0,0,-1,1,0,0};
int dirZ[6] = {0,0,0,0,-1,1};

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;

    while (cin >> N && N != -1) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                string in;
                cin >> in;

                for (int k = 1; k <= N; k++) {
                    // cin >> beer[i][j][k];
                    beer[i][j][k] = in[k-1] - '0';
                    visited[i][j][k] = 0;
                }
            }
        }

        /*for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                for (int k = 1; k <= N; k++) {
                    cout << beer[i][j][k];
                }
                cout << "\n";
            }
            cout << "\n";
        }*/

        int c,r;
        cin >> c >> r;
        tuple<int,int,int> start = {c,r,1};
        // is this just 3 dimensional bfs?
        queue<tuple<int,int,int>> myQueue;
        int ans = 0;
        myQueue.push(start);
        visited[1][r][c] = 1;
        while (!myQueue.empty()) {
            auto front = myQueue.front();
            myQueue.pop();
            ans += 1;
            //printf("Going to (%d,%d,%d) has grid of %d: \n",get<0>(front),get<1>(front),get<2>(front), beer[get<2>(front)][get<1>(front)][get<0>(front)]);
            for (int i = 0; i < 6; i++) {
                int newX = get<0>(front) + dirX[i];
                int newY = get<1>(front) + dirY[i];
                int newZ = get<2>(front) + dirZ[i];
                if (!(newX >= 1 && newX <= N && newY >= 1 && newY <= N && newZ >= 1 && newZ <= N)) {
                    continue;
                }
                if (visited[newZ][newY][newX] == 1) {
                    continue;
                }
                if (beer[newZ][newY][newX] == 1) {
                    continue;
                }
                visited[newZ][newY][newX] = 1;
                tuple<int,int,int> newTup = {newX,newY,newZ};
                myQueue.push(newTup);
            }
        }
        cout << ans << "\n";
    }
}