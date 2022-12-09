// http://www.usaco.org/index.php?page=viewproblem2&cpid=856
// https://github.com/nexus-x86/cp-solutions
// Sunday December 4 2022

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("blist");
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    const int mx = 1001;
    int startList[mx];
    int endList[mx];
    int bucketList[mx];
    int bucketsInUsed[mx];

    fill(startList, startList + mx, -1);
    fill(endList, endList + mx, -1);

    for (int i = 0; i < N; i++) {
        int s, e, b;
        cin >> s >> e >> b;
        startList[s] = e;
        endList[e] = s;
        bucketList[e] = b;
    }
    int buckets = 0;
    for (int i = 1; i <= 1000; i++) {
        if (endList[i] != -1) {
            int bucketsUsed = bucketsInUsed[i];
            bucketsInUsed[i] = 0;
            //cout << "CLOSE: Reached index " << i << " which means the cow is done being milked. We can now re-add " << bucketsUsed << " to our supply. We nw have " << buckets << " buckets." << "\n";
            buckets += bucketsUsed;
        }
        if (startList[i] != -1) {
            int bucketsNeeded = bucketList[startList[i]];
            //cout << "BEGIN: Reached index " << i << " which needs " << bucketsNeeded << " buckets." << "\n";

            if (bucketsNeeded > buckets) {
                //cout << "We need " << bucketsNeeded << " buckets but we only have "  << buckets << " buckets, so we went to the equipment room and grabbed " << bucketsNeeded - buckets << " buckets." << "\n";
                buckets += (bucketsNeeded - buckets);
            }

            buckets -= bucketsNeeded;
            //cout << "Grabbing " << bucketsNeeded << " buckets from the stash" << "\n";
            bucketsInUsed[startList[i]] = bucketsNeeded;

        }
    }
    cout << buckets << "\n";
    return 0;
}