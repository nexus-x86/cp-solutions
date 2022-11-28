#include <iostream>

using namespace std;

int factorial(int x) {
    // recursion needs to have a base case that terminates the function
    // eventually
    if (x == 0) {
        return 1;
    }

    // recursion needs to accomplish something at every step of the way
    // recursion needs to put it all together
    return factorial(x-1)*x;
    
}

int main() {
    cout << factorial(5) << "\n"; // outputs 120 as expected
}