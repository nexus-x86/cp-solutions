// http://www.usaco.org/index.php?page=viewproblem2&cpid=1061
// https://github.com/nexus-x86/cp-solutions
// Thursday December 15 2022

#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<tuple<int,int,int>> northcows, eastcows;

    for (int i = 0; i < N; i++) {
        char a;
        int b, c;
        cin >> a >> b >> c;

        // A north and an east will collide if and only if
        /*
            The north's y value is below the east's y value
            The east's x value is to the left o the north's x value
        */
        if (a == 'N') {
            northcows.push_back(make_tuple(b,c,i));
        } else {
            eastcows.push_back(make_tuple(b,c,i));
        }
    }

    sort(northcows.begin(),northcows.end());
    sort(eastcows.begin(),eastcows.end(),
        [](tuple<int,int,int> const &t1, tuple <int,int,int> const &t2) {
            return get<1>(t1) < get<1>(t2);
        }
    );

    vector<int> stop(N)


    return 0;
}