#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long a[1000000];
vector<long long> newSeq;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    long long N;
    cin >> N;

    for (long long i = 0; i < N; i++) 
        cin >> a[i];
    

    long long maxCurrNum = -1;
    for (long long i = 0; i < N; i++) {
        vector<long long>::iterator myIt;
        myIt = lower_bound(newSeq.begin(), newSeq.end(), a[i]);
        if (myIt == newSeq.end()) {
            newSeq.push_back(a[i]);
        } else {
            *myIt = a[i];
        }
    }

    cout << newSeq.size() << "\n";
}