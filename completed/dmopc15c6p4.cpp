// https://dmoj.ca/problem/dmopc15c6p4
// https://github.com/nexus-x86/cp-solutions
// Tuesday November 22

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
vector<int> p, height, setSize;

int numSets;

void initialize(int N)
{
    p.assign(N, 0);
    for (int i = 0; i < N; ++i)
        p[i] = i;
    height.assign(N, 0);
    setSize.assign(N, 1);
    numSets = N;
}
int findSet(int i)
{
    if (p[i] == i)
        return i;
    p[i] = findSet(p[i]);
    return p[i];
}
bool isSameSet(int i, int j)
{
    return findSet(i) == findSet(j);
}
void union_Set(int i, int j)
{
    if (isSameSet(i, j))
        return;
    int x = findSet(i);
    int y = findSet(j);
    if (height[x] > height[y])
        swap(x, y);
    p[x] = y;
    if (height[x] == height[y])
        ++height[y];
    setSize[y] += setSize[x];
    --numSets;
}

const int mx = 1e6;

vector<tuple<int,int,int>> edgeList; // weight, start ,end

int N, K;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    initialize(N);
    for (int i = 0; i < N - 1; i++) {
        // edge between i and i + 1 with weight wt
        int wt;
        cin >> wt;
        edgeList.push_back(make_tuple(wt, i, i+1));
        edgeList.push_back(make_tuple(wt, i+1, i));

        if (i + K <= N - 1) {
            edgeList.push_back(make_tuple(0, i, i+K));
            edgeList.push_back(make_tuple(0, i+K, i));
        }
    }

    sort(edgeList.begin(),edgeList.end());
    int cost = 0;
    for (auto x : edgeList) {
        if (!isSameSet(get<1>(x),get<2>(x))) {
            union_Set(get<1>(x),get<2>(x));
            cost += get<0>(x);
        }
    }
    cout << cost << "\n";
}