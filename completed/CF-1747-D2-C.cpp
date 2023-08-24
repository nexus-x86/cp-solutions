#include <iostream>
using namespace std;
const int mx = 1e5+2;
int n, a[mx], t;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        int min = 1e9+5;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] < min) {
                min = a[i];
            }
            
        }
        if (a[0] > min) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }

        // a1 > min(a)  

        // 

        // a1 = min(a)

    }
}