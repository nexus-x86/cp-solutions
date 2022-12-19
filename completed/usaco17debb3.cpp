// http://www.usaco.org/index.php?page=viewproblem2&cpid=761
// https://github.com/nexus-x86/cp-solutions
// Thursday December 15 2022

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <tuple>
#include <string>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("measurement");
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<tuple<int, string, int>> list;

    for (int i = 0; i < N; i++) {
        int a, c;
        string b;
        cin >> a >> b >> c;
        list.push_back(make_tuple(a,b,c));
    }

    sort(list.begin(),list.end());
    map<string, int> count;
    count["Bessie"] = 7;
    count["Elsie"] = 7;
    count["Mildred"] = 7;

    vector<string> namesOnWall{"Bessie","Elsie","Mildred"};

    int displayChanges = 0;
    for (int i = 0; i < N; i++) {
        count[get<1>(list[i])] += get<2>(list[i]);
        int largestNumber = 0;
        for (auto &[_,milk] : count) {
            largestNumber = max(largestNumber, milk);
        }

        vector<string> newWall;
        for (auto &[name,milk] : count) {
            if (largestNumber == milk) {
                newWall.push_back(name);
            }
        }

        displayChanges += namesOnWall != newWall;
        namesOnWall = newWall;
    }

    cout << displayChanges << "\n";

    return 0;
}