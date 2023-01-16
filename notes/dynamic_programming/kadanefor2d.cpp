#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int R, C;
    cin >> R >> C;
    int grid[R][C+1];
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j <= C; j++) {
            grid[i][j] = 0;
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> grid[i][j];
            grid[i][j] += grid[i][j-1];

            //cout << grid[i][j] << " ";
        }
        //cout << "\n";
    }
    
    for (int i = 0; i < R; i++) {
        int runningSum = 0;
        int best = 0;
        for (int j = 1; j <= C; j++) {
            runningSum += grid[i][j];
            best = max(runningSum, best);
            if (runningSum < 0) {
                runningSum = 0;
            }
        }
        cout << best << "\n";
    }

    for (int Left = 0; Left < C; Left++) {
        for (int Right = C - 1; Right >= 0; Right--) {
            if (Left > Right) {
                continue;
            }

            int runningSum = 0;
            int best = 0;
            for (int j = Left; j <= Right; j++) {
                for (int i = 0; i < )
            }
        }
    }
    

}