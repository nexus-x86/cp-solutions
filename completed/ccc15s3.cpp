// https://dmoj.ca/problem/ccc15s3
// https://github.com/nexus-x86/cp-solutions
// Friday October 14 2022

#include <iostream>
#include <set>
using namespace std;

int main() {
    int G,P;
    cin >> G >> P;
    int count = 0;
    set<int> gates;
    for (int i = 0; i < G; i++) {
        gates.insert(i); // gates from 1 to G
    }
    for (int i = 0; i < P; i++) {
        int n;
        cin >> n;
        set<int>::iterator it = gates.lower_bound(G-n);
        if (it == gates.end()) {
            break;
        }
        gates.erase(it);
        count++;    
    }
    cout << count << "\n";
}