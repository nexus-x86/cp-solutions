// https://dmoj.ca/problem/cco08p2
// https://github.com/nexus-x86/cp-solutions
// Saturday October 15 2022

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int M,N;
int count = 1;

const int mx = 1e5+5;

unordered_map<string, int> snum;
vector<int> parent, size1, parent2, size2;

void make_set(int v, int s) {
    if (s == 1) {
        parent[v] = v;
        size1[v] = 1;
    } else {
        parent2[v] = v;
        size2[v] = 1;
    }
}

int find_set(int v, int s) {
    if (s == 1) {
        if (v == parent[v]) {
            return v;
        }
        parent[v] = find_set(parent[v],1);
        return parent[v];
    } else {
        if (v == parent2[v]) {
            return v;
        }
        parent2[v] = find_set(parent2[v],2);
        return parent2[v];
    }
}
// f(1) = 2
// f(2) = 1

bool isSameGroupSet(int i, int j, int s) {
    int a = find_set(i,s); // root of i in set s
    int b = find_set(j,s); // root of j in set s
    if (s == 2) {
        s = 1;
    } else {
        s = 2;
    }
    int c = find_set(i,s); // root of i in set not s
    int d = find_set(j,s); // root of j in set not s
    cout << a << "\n";
    cout << b << "\n";
    cout << c << "\n";
    cout << d << "\n";
    return a == d || a == b || b == c || c == d;
}

bool isSameSet(int i, int j, int s)
{
    return find_set(i, s) == find_set(j, s);
}

void union_sets(int a, int b, int s) {
    if (s == 1) {
        a = find_set(a,1);
        b = find_set(b,1);
        if (a != b) {
            if (size1[a] < size1[b]) {
                swap(a,b);
            }
            parent[b] = a;
            size1[a] += size1[b];
        }
    } else {
        a = find_set(a,2);
        b = find_set(b,2);
        if (a != b) {
            if (size2[a] < size2[b]) {
                swap(a,b);
            }
            parent2[b] = a;
            size2[a] += size2[b];
        }
    }
}

// parent1 -> parallel relationships
// parent2 -> intersect relationships

int main() {
    parent.assign(mx, 0);
    size1.assign(mx,0);
    parent2.assign(mx,0);
    for (int i = 1; i <= mx; i++) {
        parent[i] = i;
        parent2[i] = i;
    }
    size2.assign(mx,0);
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        string a, b, c;
        cin >> a >> b >> c;
        int q = 3;
        if (c == "parallel") {
            q = 1;
        } else {
            q = 2;
        }
        if (snum[a] == 0) {
            snum[a] = count;
            count++;
            make_set(snum[a],q);
        }
        if (snum[b] == 0) {
            snum[b] = count;
            count++;
            make_set(snum[b],q);
        }
        union_sets(snum[a],snum[b],q);
        if (isSameSet(snum[a],snum[b],1) == true && isSameSet(snum[a],snum[b],2) == true) {
            cout << "Waterloo" << "\n";
            return 0;
        }
    }
    for (int i = 0; i < N; i++) {
        string a, b;
        cin >> a >> b;
        if (isSameGroupSet(snum[a],snum[b],1)) {
            cout << "parallel" << "\n";
        } else if (isSameGroupSet(snum[a],snum[b],2)) {
            cout << "intersect" << "\n";
        } else {
            cout << "unknown" << "\n";
        }
    }
}