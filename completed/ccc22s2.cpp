// https://dmoj.ca/problem/ccc22s2
// https://github.com/nexus-x86/cp-solutions
// Monday October 10 2022

#include <iostream>
#include <unordered_map>

using namespace std;

typedef pair<int,int> pii;

int X, Y, G;
const int mx = 4e5+5;

int group[mx];
pii must[mx];
pii mustNot[mx];
unordered_map<string, int> m;

int main() {
    int count = 0;
    cin >> X;
    for (int i = 0; i < X; i++) {
        string a,b;
        cin >> a >> b;
        if (m[a] == 0){ 
            m[a] = ++count; // giving strings an integer id
        }
        if (m[b] == 0){ 
            m[b] = ++count;
        }
        must[i] = make_pair(m[a],m[b]);
    }
    cin >> Y;
    for (int i = 0; i < Y; i++) {
        string a,b;
        cin >> a >> b;
        if (m[a] == 0) {
            m[a] = ++count;
        } 
        if (m[b] == 0){ 
            m[b] = ++count;
        }
        mustNot[i] = make_pair(m[a],m[b]);
    }
    cin >> G;
    for (int i = 1; i <= G; i++) {
        for (int j = 0; j < 3; j++) {
            string a;
            cin >> a;
            if (m[a] == 0) {
                m[a] = ++count;
            }
            group[m[a]] = i; // assigning the int id's the index of the group they are apart of
        }
    }
    int ans = 0;
    for (int i = 0; i < X; i++) {
        if (group[must[i].first] != group[must[i].second]) { // if they are not in the same group
            ans++;
        }
    }
    for (int i = 0; i < Y; i++) {
        if (group[mustNot[i].first] == group[mustNot[i].second]) { // if they are in the same group
            ans++;
        }
    }
    cout << ans << "\n";
}