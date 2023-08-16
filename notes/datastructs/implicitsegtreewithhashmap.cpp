#include <iostream>
#include <unordered_map>

using namespace std;

const int mx = 5e5+2;
int A[mx];
unordered_map<int, int> segTree;

void pushup(int p) {
    segTree[p] = min(segTree[2 * p], segTree[2 * p + 1]);
}

void update(int p, int L, int R, int idx, int val) {
    if (L == R) {
        segTree[p] = val;
        return;
    }
    int m = (L + R) / 2;
    if (idx <= m && idx >= L) {
        update(2 * p, L, m, idx, val);

    } else {
        update(2 * p + 1, m + 1, R, idx, val);
    }
    pushup(p);
}

int query(int p, int L, int R, int qL, int qR) {
    if (qL <= L && R <= qR) {
        return segTree[p];
    }
    if (R < qL || qR < L) {
        return INT_MAX;
    }
    int m = (L + R) / 2;
    // return min(query(2 * p, L, m, ))
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);


}