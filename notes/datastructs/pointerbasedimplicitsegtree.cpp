#include <iostream>

using namespace std;

const int mx = 5e5+2;
int a[mx];

struct node {
    int minimum, l, r;
    node* left;
    node* right;
    

    void update(int idx, int val) {
        if (idx < l || r < idx) {
            return;
        }
        if (l == r) {
            minimum = a[l];
            return;
        }
        int m = (l + r) / 2;

        if (idx >= l && m >= idx) {
            if (left == NULL) {
                left = new node();
            }
            left->l = l;
            left->r = m;
            left->update(idx, val);
            if (right == NULL) {
                minimum = left->minimum;
            } else {
                minimum = min(left->minimum,right->minimum);
            }
        } else {
            if (right == NULL) {
                right = new node();
            }
            right->l = m + 1;
            right->r = r;
            right->update(idx, val);
            if (left == NULL ){
                minimum = right->minimum;
            } else {
                minimum = min(left->minimum,right->minimum);
            }
        }
    }

    int query(int i, int j) {
        // starts from the root node
        if (l >= i && r <= j) {
            return minimum;
        }
        int m = (l + r) / 2;
        int best = 1000000;
        if (i <= min(m,j)) {
            if (left != NULL) {
                best = left->query(i,j);   
            }
        }
        if (max(i,m+1) <= j) {
            if (right != NULL) {
                best = min(best, right->query(i,j));
            }
        }
        return best;
    }
};

int N, M;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    // pointer based implicit seg tree
    cin >> N >> M;
    node rootNode;
    rootNode = {0, N-1, 0, NULL, NULL};
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        rootNode.update(i,a[i]);
    }
    for (int i = 0; i < M; i++) {
        char query;
        int b,  c;
        cin >> query >> b >> c;
        if (query == 'Q') {
            cout << rootNode.query(b,c) << "\n";
        } else {
            rootNode.update(b,c);
        }
    }
}