// segment tree

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const int mx = 1e5;
int N, M;
int A[mx];
vector<int> segTree;
vector<int> lazy;
int segSize;

int conquer(int a, int b) {
    if (a == -1) {
        return b;
    }
    if (b == -1) {
        return a;
    }
    return min(a,b);
}

void propagate(int p, int L, int R) {
    if (lazy[p] != -1) {
        segTree[p] = lazy[p];
        if (L != R) {
            lazy[2 * p] = lazy[2 * p + 1] = lazy[p];
        } else {
            A[L] = lazy[p];
        }
        lazy[p] = -1;
    }
}

void build(int p, int L, int R) { // 8 lines at most < - > check!
    if (L == R) {
        segTree[p] = A[L];
        return;
    }
    int mid = (L + R) / 2;
    build(2*p,L,mid);
    build(2*p+1,mid+1,R);
    segTree[p] = min(segTree[2*p],segTree[2*p+1]);
}

int rmq(int p, int L, int R, int i, int j) { // 6 lines
    propagate(p, L, R);
    if (i > j) {
        return -1;
    }
    if ((L >= i) && (R <= j)) {
        return segTree[p];
    }
    int m = (L + R) / 2;
    return conquer(rmq(p * 2, L, m, i, min(m,j)), rmq(p * 2 + 1, m + 1, R, max(i, m + 1), j));
}

void update(int p, int L, int R, int i, int j, int val) { // 9 lines
    propagate(p,L,R);
    if (i > j) {
        return;
    }
    if ((L >= i) && (R <= j)) {
        lazy[p] = val;
        propagate(p,L,R);
    } else {
        int m = (L + R) / 2;
        update(2*p,L, m,i ,min(m,j),val);
        update(2*p+1,m+1,R,max(i,m+1),j,val);
        segTree[p] = min(segTree[2*p],segTree[2*p+1]);
    }

}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    segSize = 2 * pow(2, ceil(log2(N))) + 1; // start at 1-index
    segTree.assign(segSize,-1);
    lazy.assign(segSize,-1);

    build(1,0,N);

    for (int i = 1; i <= segSize; i++) {
        cout << segTree[i] << " ";
    }
    cout << "\n";

    cout << rmq(1,0,N,0,3 ) << "\n";
}