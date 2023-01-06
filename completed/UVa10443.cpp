// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=614&page=show_problem&problem=1384
// https://github.com/nexus-x86/cp-solutions
// Friday January 6 2023

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    unordered_map<char, char> mapping = {
        {'R','S'},
        {'S','P'},
        {'P','R'}
    };

    int cases;
    cin >> cases;

    string a = "";

    int dirX[4] = {1,-1,0,0};
    int dirY[4] = {0,0,1,-1};

    while (cases--) {
        int r, c, n;
        cin >> r >> c >> n;
        char grid[r][c];
        
        for (int i = 0; i < r; i++) {
            string myStr;
            cin >> myStr;
            int iter = 0;
            for (char c : myStr) {
                grid[i][iter] = c;
                iter++;
            }
        }

        while (n--) {
            char newGrid[r][c];
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    newGrid[i][j] = grid[i][j];
                }
            }

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    for (int k = 0; k < 4; k++) {
                        if (i + dirX[k] >= 0 && i + dirX[k] < r && j + dirY[k] >= 0 && j + dirY[k] < c) {
                            if (mapping[grid[i][j]] == grid[i+dirX[k]][j+dirY[k]]) {
                                newGrid[i+dirX[k]][j+dirY[k]] = grid[i][j];
                            }
                        }
                    }
                }
            }

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    grid[i][j] = newGrid[i][j];
                }
            }
        }
        cout << a;
        a = "\n";
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << grid[i][j];
            }
            cout << "\n";
        }
        

    }
}