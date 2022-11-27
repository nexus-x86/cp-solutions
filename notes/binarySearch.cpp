#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    /*
    Binary search is an absolute classic
    The fundamental idea behind binary search is splitting the search
    interval in two.
    Commonly used in finding a number in a sorted array.
    */

    int arr[] = {69,420,69420,1,505,382,-500000,-4000,-300,-200,5,20,30,11};
    sort(begin(arr),end(arr)); // binary search only works for sorted arrays

    int targetVal = -200;
    int left = -1;
    int right = 14;
    int steps = 0;
    while (right - left > 1) {
        steps++;
        int mid = (left+right)/2;
        if (arr[mid] == targetVal) {
            cout << "Found " << targetVal << " in " << steps << " steps.";
        }
        if (targetVal < arr[mid]) {
            right = mid;
        }  else {
            left = mid;
        }
    }
}