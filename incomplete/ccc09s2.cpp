// https://dmoj.ca/problem/ccc09s2
// https://github.com/nexus-x86/cp-solutions
// Saturday October 22

#include <iostream>
#include <bitset>

using namespace std;

int lights[30][8];
int xorLights[30][8];

int main() {
    int R, L;
    // if button k is pressed, is there any point of pressing button i with i < k
    // the final answer shuldn't be that big right?
    // XOR all columns

    cin >> R >> L;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < L; j++) {
            cin >> lights[i][j];
        }
    }
    // a ^ b
    for (int i = 1; i < R; i++) {
        for (int j = 0; j < L; j++) {
            xorLights[i][j] = lights[i-1][j] ^ lights[i][j];
            cout << xorLights[i][j] << " ";
        }
        cout << "\n";
    }
    int sum = 0;
    for (int a = 0; a < L; a++) {

    }
    // it takes a certain level of emotional maturity to be great
    // it takes an insane level of work ethic
}