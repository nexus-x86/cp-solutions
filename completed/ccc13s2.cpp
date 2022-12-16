// https://dmoj.ca/problem/ccc13s2
// https://github.com/nexus-x86/cp-solutions
// Saturday November 19

#include <iostream>

typedef long long ll;

using namespace std;

ll W, N;
const ll mx = 1e5+5;
ll cars[mx] = {0};


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> W >> N;
    // W : Maximum weight that the bridge can hold any time
    // N : the Next N lines has the weight of the ith car
    
    ll carCount = 0;
    ll currSum = 0;

    for (int i = 0; i < N; i++) {
        // Each car is 10m but weights are different;
        // Bridge is 40m long, therefore can hold 4 cars;'
        // Bridge will crack if the weight on it is > W
        // Cars cross the bridge in the order of the input
        // Find the maximum cars that can be takne across.
        ll carWeight;
        cin >> carWeight;
        currSum += carWeight;
        carCount++;
        cars[i+4] = carWeight;
        currSum -= cars[i]; // car that just Left

        // DEBUG 
        /*
        cout << "Car that joins weighs " << carWeight << " joined.\n";
        cout << "Car count increased to " << carCount << ".\n";
        cout << "Car that left weighs " << cars[i] << ".\n";
        cout << "Current sum is now " << currSum << ".\n";
        */
        if (currSum > W) {
            cout << carCount - 1 << "\n";
            return 0;
        }
    }
    cout << carCount << "\n"; // might WA (Wrong Answer)
    return 0;
}