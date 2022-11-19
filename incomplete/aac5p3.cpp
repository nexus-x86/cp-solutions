// https://dmoj.ca/problem/aac5p3
// https://github.com/nexus-x86/cp-solutions
// Thursday November 17

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string.h>
using namespace std;
typedef long long ll;

ll N, K;
const ll mx = 1e5*2+5;
ll skillLevel[mx]; // measures the skill level of panda's
ll breakPoints[mx]; // the output array, increment an index by 1 if a panda makes it
ll visited[mx] = {0}; // reset this array every new panda

//vector<pair<ll,ll>> adjList(mx); // stores relations

unordered_map<ll, vector<pair<ll,ll>>> adjList;

// first number is to, second number is difficulty, the from field is the index


/*
Skiing process
If no hills connect to the current breakpoint, they will stop
A panda will never ski to a hill previously skied to
The panda will consider all hills connected, and will go down the hill
that minimizes |s - d|, if there is a tie they will go down the hill
with the lowest difficulty level
And repeat
*/
void dfs(ll panda, ll curr) { 
    breakPoints[curr]++; // a panda somehow made it, yay!!
    visited[curr] = 1;

    ll skill = skillLevel[panda];

    ll bestHill = 0;
    ll minimizedValue = 9223372036854775807;
    ll bestHillDiffValue = 0;

    for (pair<ll,ll> myEpicHill : adjList[curr]) {
        ll goingTo = myEpicHill.first;
        ll difficulty = myEpicHill.second;
        if (visited[goingTo] == 1) {
            continue; // skip to next element in arr if we already went there
        } 
        ll minimize = abs(skill - difficulty);
        if (minimize < minimizedValue) {
            minimizedValue = minimize;
            bestHill = goingTo;
            bestHillDiffValue = difficulty;
        } else if (minimize == minimizedValue) {
            if (difficulty < bestHillDiffValue) {
                minimizedValue = minimize;
                bestHill = goingTo;
                bestHillDiffValue = difficulty;
            }
        }
    }

    if (bestHill == 0) {
        return; // no more values connected
    }

    dfs(panda,bestHill);
}

int main() {
    cin >> N >> K;
    /*
    N breakpoints from 1 -> N
    breakpoint with id 1 is the root
    N-1 hills which connect the breakpoints
    ith hill has difficulty di
    K pandas, the ith panda has skill level of si
    all start at breakpoint 1 and start skiing
    */
    for (ll i = 0; i < N - 1; i++) {
        ll a, b, d;
        // Hill between breakpoint a and b with difficulty d
        cin >> a >> b >> d;

        adjList[a].push_back({b,d});
        adjList[b].push_back({a,d});

    }
    for (ll i = 0; i < K; i++) {
        cin >> skillLevel[i];
        // i'th panda has skilllevel[i]
        //visited = {0}; // reset every element to 0
        memset(visited,0,mx);

        dfs(i,1); // we start at 1 as the root
    }
    for (ll i = 1; i < N; i++) {
        cout << breakPoints[i] << " ";
    }
    cout << breakPoints[N] << "\n";
}