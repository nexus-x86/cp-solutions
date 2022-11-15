// https://dmoj.ca/problem/segtree
// https://github.com/nexus-x86/cp-solutions
// Tuesday November 1 2022

#include <iostream>
#include <math.h>
#include <string>
int arr[100489];
int block[317];
const int blk_sz = 317;

using namespace std;
 

void update(int idx, int val)
{
    int blockNumber = idx / blk_sz;
    if (val <= block[blockNumber]) {
        block[blockNumber] = val;
        arr[idx] = val;
    } else if (block[blockNumber] < arr[idx]) {
        arr[idx] = val;
    } else {
        arr[idx] = val;
        block[blockNumber] = 1e7;
        int stop = (blockNumber + 1) * blk_sz;
        for (int i = blockNumber * blk_sz; i < stop; i++) {
            block[blockNumber] = min(block[blockNumber], arr[i]);
        }
    }
}

int query(int l, int r)
{
    int output = 1e7;
    while (l < r && l % blk_sz != 0) {
        output = min(output, arr[l]);
        l++;
    }
    while (l + blk_sz - 1 <= r) {
        output = min(output, block[l / blk_sz]);
        l += blk_sz;
    }
    while (l <= r) {
        output = min(output, arr[l]);
        l++;
    }
    return output;
}

 
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N, M, x, y;
    string s;
    cin >> N >> M;

    fill_n(block, 317, 1e7);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        block[i / blk_sz] = min(arr[i], block[i / blk_sz]);
    }

    for (int i = 0; i < M; i++) {
        cin >> s >> x >> y;
        if (s == "Q") {
            cout << query(x,y) << "\n";
        } else {
            update(x,y);
        }
    }
}