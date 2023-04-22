// The N Queen problem
// Using backtracking to place N queens on an N by N chessboard such that
// no queen attacks each other.

#include <iostream>
#include <math.h>

using namespace std;

const int mx = 100;
char chessboard[mx][mx];
int visited[mx][mx];
int N;

int counter = 0;

void markCheck(int i, int j) {
    if (i >= 0 && j >= 0 && i < N && j < N) {
        visited[i][j] = 1;
    }
}

void mark(int i, int j) {
    chessboard[i][j] = 'Q';
    counter++;
    for (int k = 0; k < N; k++) {
        markCheck(i, k);
        markCheck(k, j);
    }

    for (int k = 0; k < N; k++) {
        markCheck(i + k, j + k);
        markCheck(i - k, j - k);
        markCheck(i + k, j - k);
        markCheck(i - k, j + k);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < mx; i++) {
        for (int j = 0; j < mx; j++) {
            chessboard[i][j] = '.';
        }
    }

    cin >> N;


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == 0) {
                mark(i,j);
            }
        }
    }

    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << chessboard[i][j] << " ";
        }
        cout << "\n";
    }
}