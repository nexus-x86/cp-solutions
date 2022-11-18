// https://dmoj.ca/problem/aac5p3
// https://github.com/nexus-x86/cp-solutions
// Thursday November 17

#include <iostream>
using namespace std;
typedef long long ll;
ll N, K;
// N breakpoints from 1 -> N

const int mx = 1e5*2+5;
ll skillLevel[mx];

int main() {
    cin >> N >> K;
    for (ll i = 0; i < N - 1; i++) {
        ll a, b, d;
        // Hill between breakpoint a and b with difficulty d
        cin >> a >> b >> d;
    }
    for (ll i = 0; i < K; i++) {
        cin >> skillLevel[i];
        // i'th panda has skilllevel[i]
    }
    /*
    Skiing process
    If no hills connect to the current breakpoint, they will stop
    A panda will never ski to a hill previously skied to
    The panda will consider all hills connected, and will go down the hill
    that minimizes |s - d|, if there is a tie they will go down the hill
    with the lowest difficulty level
    And repeat
    */
}