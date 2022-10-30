#include <iostream>
using namespace std;
int arr[] = {4,3,2,13,1,2,3,4,5};
int slidingWindow(int windowSize) {
    if (windowSize > size(arr)) {
        cout << "Window too big" << "\n";
        return 0;
    }
    int best = 0;
    for (int i = 0; i < windowSize; i++) {
        best += arr[i];
    }
    int windowSum = best;
    for (int i = windowSize; i < size(arr); i++) {
        windowSum += (arr[i] - arr[i-windowSize]);
        best = max(windowSum,best);
    }
    return best;
}

int main() {
    // uses sliding window to find the maximum sum of a subarray with length 3
    cout << slidingWindow(3);
}