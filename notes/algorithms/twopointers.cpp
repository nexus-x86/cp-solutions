#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // idea behind 2 pointers is using 2 integer variables
    // leftPointer points to the left and marks the first element
    // rightPointer points to the right and marks the last element

    // an example of two pointers being used in a problem is the following code
    // this code finds 2 numbers in the array that add to the target number 

    int arr[] = {1,6,2,3,7,9,42,3,100000,-5000,69420,-1111};
    sort(arr,end(arr));
    int leftPointer = 0;
    int rightPointer = size(arr) - 1;

    int targetNum = 13;

    while (leftPointer < rightPointer) {
        if (arr[leftPointer] + arr[rightPointer] == targetNum) {
            cout << "Numbers " << arr[leftPointer] << " and " << arr[rightPointer] << " add up to " << targetNum << ".\n";
            return 0;
        } else if (arr[leftPointer] + arr[rightPointer] < targetNum) {
            leftPointer++;
        } else {
            rightPointer--;
        }
    }
}