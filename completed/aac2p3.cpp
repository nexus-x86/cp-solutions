// https://dmoj.ca/problem/aac2p3
// https://github.com/nexus-x86/cp-solutions
// Friday November 18

#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <queue>

using namespace std;

typedef long long ll;

ll N,M;
const int mx = 1505;
vector<string> grid;
ll psa[mx][mx];
bool visited[mx][mx];
int directionsX[4] = {1,-1,0,0};
int directionsY[4] = {0,0,1,-1};

bool obstacleCheck(int x) {
    memset(visited,0,sizeof(visited));
    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push(make_pair(make_pair(1,1),make_pair(x,x)));
    int x1, y1, x2, y2, x3, y3, x4, y4;
    while (!q.empty()) {
        x1 = q.front().first.first;
        y1 = q.front().first.second;
        x2 = q.front().first.first;
        y2 = q.front().second.second;
        x3 = q.front().second.first;
        y3 = q.front().first.second;
        x4 = q.front().second.first;
        y4 = q.front().second.second;
        q.pop();
        if (x1 < 1 || y1 < 1 || x2 < 1 || y2 < 1 || x3 < 1 || y3 < 1 || x4 < 1 || y4 < 1|| x1 > N || x2 > N || x3 > N || x4 > N || y1 > M || y2 > M || y3 > M || y4 > M || psa[x4][y4] - psa[x3][y3-1] - psa[x2-1][y2] + psa[x1-1][y1-1]) {
            continue; 
        } else if (x4 == N && y4 == M) {
            return 1;
        } else if (visited[x1][y1]) {
            continue;
        }
        visited[x1][y1] = 1;
        for (int i = 0; i < 4; i++) {
            int cx = directionsX[i];
            int cy = directionsY[i];
			int nx1 = x1 + cx;
            int ny1 = y1 + cy;
            int nx4 = x4 + cx;
            int ny4 = y4 + cy;
			if (!visited[nx1][ny1]) {
                q.push(make_pair(make_pair(nx1,ny1),make_pair(nx4,ny4)));
            }
        }
    }
    return 0;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        grid.push_back(s);
    }
    memset(psa,0,sizeof(psa));
    for (int i = 1; i < M + 1; i++) {
        psa[1][i] = (grid[0][i-1] == 'X') + psa[1][i-1];
    }
    for (int i = 1; i < N+ 1; i++) {
        psa[i][1] = (grid[i-1][0] == 'X') + psa[i-1][1];	
    }
	for (int i = 2; i < N+1; i++) {
		for (int j = 2; j < M + 1; j++) {
			psa[i][j] = psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1] + (grid[i-1][j-1] == 'X');
		}
	}
    int left = 0;
    int right = 1;
    int mid;
    for (int i = 0; i < min(M,N); i++) { // min is the max square size
        if (grid[0][i] == 'X' || grid[i][0] == 'X') { 
            break;
        }
        right++;
    }
    while (right - left > 1) { // binary search
        mid = (left + right) / 2;
        if (obstacleCheck(mid)) { 
            left = mid;
        } else {
            right = mid;
        }
    }
    cout << left << "\n";
    return 0;
}