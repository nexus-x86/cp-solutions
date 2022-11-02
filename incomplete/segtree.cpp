// https://dmoj.ca/problem/segtree
// https://github.com/nexus-x86/cp-solutions
// Tuesday November 1 2022

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int arr[100000];
int block[400];
int blk_sz = sqrt(size(arr));

void update(int idx, int val) {
    int blockNum = idx/blk_sz;
    block[blockNum] += val-arr[idx];
    arr[idx]=val;
}
int query(int l, int r) {
    int minimum = 1e6+1;
    while (l < r && l % blk_sz != 0) {
        if (arr[l] < minimum) {
            minimum = arr[l];
        }
        l++;    
    }
    while (l + blk_sz-1 <= r) {
        if (block[l/blk_sz] < minimum) {
            minimum = block[l/blk_sz];
        }
        l+=blk_sz;
    }
    while(l<=r){
        if (arr[l] < minimum) {
            minimum = arr[l];
        }
        l++;
    }
    return minimum;
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < 1e5; i++) {
        arr[i] = 1e6+1;
    }
    for (int i = 0; i < N; i++) {
        int ele;
        cin >> ele;
        arr[i-2] = ele;
    }

    for (int i = 0; i < M; i++) {
        char a;
        int b;
        int c;
        cin >> a >> b >> c;
        if (a == 'M') {
            update(b,c);
        } else {
            cout << query(b,c) << "\n";
        }
    }
}