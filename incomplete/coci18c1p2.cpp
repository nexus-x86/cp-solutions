#include <iostream>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

bool isNum(string line) {
    char* p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}

unordered_map<string, set<string>> adjList;
unordered_map<string ,int> numMap;\

bool endProgram = false;

void link(string a, string b) {

    for (auto x : adjList[a]) {
        adjList[b].insert(x);
        if (isNum(x) && !isNum(b)) {
            if (numMap[b] != 0) {
                cout << "NE\n";
                return;
            } else {
                numMap[b] = stoi(x);
                endProgram = true;
            }
        }
    }
    for (auto x : adjList[b]) {
        adjList[a].insert(x);
        if (isNum(x) && !isNum(a)) {
            if (numMap[a] != 0) {
                cout << "NE\n";
                return;
            } else {
                numMap[a] = stoi(x);
                endProgram = true;
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    string arr1[N],arr2[N];
    for (int i = 0; i < N; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> arr2[i];
        if (isNum(arr1[i]) && isNum(arr2[i]) && (stoi(arr1[i]) != stoi(arr2[i]))) {
            cout << "NE\n";
            return 0;
        }
        link(arr1[i],arr2[i]);
        if (endProgram) {
            return 0;
        }
    }

    cout << "DA\n";
}