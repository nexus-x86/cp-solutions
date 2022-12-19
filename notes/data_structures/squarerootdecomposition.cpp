#include <iostream>

using namespace std;

int arr[] = {21,80,1,95,90,25,45,81,34,73,19,63,1,83,40,41,31,25,52,4};
int block[10];
int blk_sz = sqrt(size(arr));

void update(int idx, int val) {
    int blockNum = idx/blk_sz;
    block[blockNum] += val-arr[idx];
    arr[idx]=val;
}
int query(int l, int r) {
    int sum = 0;
    while (l < r && l % blk_sz != 0) {
        sum += arr[l];
        l++;    
    }
    while (l + blk_sz-1 <= r) {
        sum += block[l/blk_sz];
        l+=blk_sz;
    }
    while(l<=r){
        sum+=arr[l];
        l++;
    }
    return sum;
}
