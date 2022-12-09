// http://www.usaco.org/index.php?page=viewproblem2&cpid=855
// https://github.com/nexus-x86/cp-solutions
// Saturday December 3 2022

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("mixmilk");
    cin.sync_with_stdio(0);
    cin.tie(0);
    int capacity[3];
    int milks[3];
    int cycle[3] = {1,2,0};
    for (int i = 0; i < 3; i++) {
        cin >> capacity[i] >> milks[i];
    }
    //cout << milks[0] << " " << milks[1] << " " << milks[2] << "\n";
    for (int i = 1; i <= 100; i++) {
        int index = i % 3 - 1;
        if (index == -1) {
            index = 2;
        }
        // cycle[index] is where we pour to
        // capacity[cycle[index]] is the maximum capacity of the bucket we pour to
        // milks[cycle[index]] is how much milk is already in the bucket we pour to

        // capcity[index] is the capacity of our bucket
        // milks[index] is the milk we pour

        int bucketGoal = cycle[index];
        int maxWeCanPour = capacity[bucketGoal] - milks[bucketGoal];
        int amountWeActuallyPour = min(milks[index],maxWeCanPour);
        
        milks[index] -= amountWeActuallyPour;
        milks[bucketGoal] += amountWeActuallyPour;

        //cout << i << ": " << milks[0] << " " << milks[1] << " " << milks[2] << "\n";

    }

    for (int i = 0; i < 3; i++) {
        cout << milks[i] << "\n";
    }
    return 0;
}