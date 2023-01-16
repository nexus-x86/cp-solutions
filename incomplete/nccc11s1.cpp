// https://dmoj.ca/problem/nccc11s1
// https://github.com/nexus-x86/cp-solutions
// Friday January 6 2023

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181./
// limit if 1e5 for input data so brute force is possible

// 4 6 7 9

int dp[35];
int fib(int n) {
    if (dp[n] != -1) {
        return dp[n];
    }

    if (n == 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    }
    dp[n] = fib(n-1) + fib(n-2);
    return dp[n];
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 35; i++) {
        dp[i] = -1;
    }
    vector<string> first30Fib;
    for (int i = 1; i <= 30; i++) {
        first30Fib.push_back(to_string(fib(i)));        
    }

    reverse(first30Fib.begin(),first30Fib.end());

    int T;
    cin >> T;


    while (T--) {
        string a;
        cin >> a;

        vector<pair<int,int>> stringsToDeleted;
        int deletions = 0;
        for (string deletionStr : first30Fib) {
            string::size_type idx = a.find(deletionStr);
            while (idx != string::npos) {
                stringsToDeleted.push_back(make_pair(idx,deletionStr.length()));
                deletions++;
                idx = a.find(deletionStr,idx+deletionStr.length());
            }
        }

        for (pair<int,int> myPair : stringsToDeleted) {
            string builder = "";
            for (int i = 0; i < myPair.second; i++) {
                builder += " ";
            }
            a.replace(myPair.first, myPair.second, builder);
        }
        int flag = 0;
        auto strBegin = a.find_first_not_of(" \t");
        if (strBegin == std::string::npos)
            flag = 1;

        if (deletions >= 2 && flag == 1) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }

    }

}