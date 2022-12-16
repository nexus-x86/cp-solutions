// http://www.usaco.org/index.php?page=viewproblem2&cpid=526
// https://github.com/nexus-x86/cp-solutions
// Sunday December 4 2022

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("censor");
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    string a, b;
    cin >> a >> b;
    int N = a.length();
    int subLength = b.length();
    string ans;
    for (int i = 0; i < N; i++) {
        ans += a[i];
        if (ans.size() > subLength && ans.substr(ans.size() - subLength) == b) {
            ans.resize(ans.size() - subLength);
        }
    } 
    cout << ans << "\n";

    return 0;
}