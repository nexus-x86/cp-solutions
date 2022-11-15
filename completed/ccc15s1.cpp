// https://dmoj.ca/problem/ccc15s1
// https://github.com/nexus-x86/cp-solutions
// Saturday November 5

#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> st;
    int a = 0;
    int K;
    cin >> K;
    for (int i =0 ; i < K; i++) {
        int b;
        cin >> b;
        if (b == 0) {
            int c = st.top();
            st.pop();
            a -= c;
        } else {
            st.push(b);
            a += b;
        }
    }
    cout << a << "\n";
}