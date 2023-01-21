// https://codeforces.com/contest/66/problem/B
// https://github.com/nexus-x86/cp-solutions
// Saturday January 21 2023

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int best = 0;

    for (int j = 0; j < n; j++) {
        int left = j;
        int right = j;
        int counter = 1;

        int leftStop = 0;
        int rightStop = 0;
        
        while (leftStop == 0 || rightStop == 0) {

            if (left - 1 >= 0 && leftStop == 0) {
                left--;
                if (arr[left] <= arr[left + 1]) {
                    counter++;
                } else {
                    leftStop = 1;
                }
            } else {
                leftStop = 1;
            }

            if (right + 1 < n && rightStop == 0) {
                right++;
                if (arr[right] <= arr[right - 1]) {
                    counter++;
                } else {
                    rightStop = 1;
                }
            } else {
                rightStop = 1;
            }
            best = max(best, counter);
        }
    }
    cout << best << "\n";
}