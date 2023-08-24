#include <iostream>
#include <deque>
using namespace std;

deque<pair<int,int>> maxMonotonicQueue;

void push(int val) {
    int count = 0;
    while (!maxMonotonicQueue.empty() && maxMonotonicQueue.back().first < val) {
        count += maxMonotonicQueue.back().second + 1;
        maxMonotonicQueue.pop_back();
    }
    maxMonotonicQueue.push_back({val, count});
}

void pop() {
    if (maxMonotonicQueue.front().second > 0) {
        maxMonotonicQueue.front().second--;
        return;
    }
    maxMonotonicQueue.pop_front();
}

int getMax() {
    return maxMonotonicQueue.front().first;
}

// template problem: https://dmoj.ca/problem/dmopc15c6p5
// monotonic queue
/*
a data structure to find the maximum/minimum of a sliding window
this is implemented using a deque of pairs (value, number of elements between
value and the previous pair) It has the following O(1) functions
1. Push (add to deque)
2. max/min return the max/min of the deque
3. Pop: remove an element from the deque
*/

int N, K;
const int mx = 3 * 1e6 + 5;
int a[mx];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

}