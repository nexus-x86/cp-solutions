#include <iostream>
#include <algorithm>
using namespace std;
int arr[] = {4,3,2,13,1,2,3,4,5};

bool twoPointer(int X) {
    sort(arr,end(arr));
    int l = 0;
    int r = size(arr)-1;
    while (l<r){
        if (arr[l] + arr[r] == X) {
            return 1;
        } else if (arr[l] + arr[r] < X) {
            l++;
        } else {
            r--;
        }
    }
    return 0;
}

int main() {
    // function finds 2 numbers that add to the target: 11 efficiently using 2 pointers
    cout << twoPointer(17); 
}