// https://dmoj.ca/problem/ccc21s3
// https://github.com/nexus-x86/cp-solutions
// Friday December 23 2022

#include <iostream>
using namespace std;

typedef long long ll;

const ll mx = 2e5+2;
ll N, p[mx], w[mx], d[mx];

ll test(ll c, ll i) {
    // this function returns the minimum time for the ith person to get 
    // within the concert at c
    ll dist = abs(p[i] - c) - d[i]; // if dist is negative,
    // we are already within range
    ll time = dist * w[i];
    return time;
}

ll getSum(ll c) { // gets sum of all times for this c
    ll sum = 0;
    for (ll i = 0; i < N; i++) {   
        ll curr = test(c,i);
        if (curr > 0) {
            sum += curr;
        }
    }
    return sum;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (ll i = 0; i < N; i++) {
        cin >> p[i] >> w[i] >> d[i];
        /*
        Let c be the position of the concert, what is the equation for 
        minimum seconds for only this pi,wi,di
        */
        // cout << test(12,i) << "\n";
    }

    // could we possible binary search the minimum
    // try to
    ll min = 1e9;
    ll bestC = 0;
    /*for (ll c = 0; c < 2000; c++) {
        ll curr = getSum(c);
        if (curr < min) {
            min = curr;
            //cout << c << "\n";
            bestC = c;
        }
    }*/

    ll low = 0;
    ll high = 1e9 + 1;

    /*
    getsum is a scuffed parabola
    so we binary search for the poll right before it starts increasing
    that is our minimum which is the ans
    */

    while (low <= high) {
        ll mid = (low + high) / 2;

        if (getSum(mid) > getSum(mid + 1)) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    

    cout << getSum(low) << "\n";
    
}