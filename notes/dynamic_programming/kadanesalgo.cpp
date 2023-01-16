#include <iostream>
#include <algorithm>

using namespace std;

// -2, -3, 4, -1, -2, 1, 5, -3

// max is 7

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int numbers;
    cin >> numbers;
    int arr[numbers];
    int runningSum = 0;
    int best = 0;

    for (int i = 0; i < numbers; i++) {
        cin >> arr[i];
        //runningSum += arr[numbers];
    }
    
    for (int i = 0; i < numbers; i++) {
        runningSum += arr[i];
        best = max(best,runningSum);
        if (runningSum < 0) {
            runningSum = 0;
        }
    }

    cout << best << "\n";
}