// https://codeforces.com/contest/680/problem/B
// https://github.com/nexus-x86/cp-solutions
// Saturday January 21 2023

#include <iostream>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, a;
    cin >> n >> a;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int counter = 0;
    int left = a - 1;
    int right = a - 1;

    int leftStop = 0;
    int rightStop = 0;
    if (arr[a-1] == 1) {
        counter++;
    } 
    while (leftStop == 0 || rightStop == 0) {
        if (left-1 >= 0) {
            left--;
        } else {
            leftStop = 1;
            arr[left] = 0;
        }
        if (right+1 < n) {
            right++;
        } else {
            rightStop = 1;
            arr[right] = 0;
        }
        if (rightStop == 0 && leftStop == 0) {
            if (arr[left] == 1 && arr[right] == 1) {
                counter+=2;
            }
        } else {
            if (arr[left] == 1 && rightStop == 1) {
                counter++;
            } else if (arr[right] == 1 && leftStop == 1) {
                counter++;
            }
        }
    }
    cout << counter << "\n";
}