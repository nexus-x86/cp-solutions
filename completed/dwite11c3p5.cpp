// https://dmoj.ca/problem/dwite11c3p5
// https://github.com/nexus-x86/cp-solutions
// Friday October 28 2022 

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string letters = "abcdefghij";
int n = 0;

bool myRecursionFunction(string s) {
    //cout << s << "\n";
    if (s[0] == '~') {
        return !myRecursionFunction(s.substr(1));
    }
    if (s[0] == '(') {
        int count = 1;
        int i;
        for (i = 1; i < s.length(); i++) {
            if (s[i] == '(') {
                count++;
            } 
            if (s[i] == ')') {
                count--;
            }
            if (count == 0) {
                i++;
                break;
            }
        }
        if (i == s.length()) {
            return myRecursionFunction(s.substr(1,i-2)); 
        }
        if (s[i] == '^') {
            return myRecursionFunction(s.substr(1,i-2)) && myRecursionFunction(s.substr(i+1));
        } else {
            return myRecursionFunction(s.substr(1,i-2)) || myRecursionFunction(s.substr(i+1));
        }
    }
    if (s.length() > 1) {
        if (s[1] == '^') {
            return myRecursionFunction(s.substr(0,1)) && myRecursionFunction(s.substr(2));
        } else {
            return myRecursionFunction(s.substr(0,1)) || myRecursionFunction(s.substr(2));
        }
    }

    
    return (n >> letters.find(s[0])) & 1; // reached when the recursion function gets to a single character
    // (n >> letters.find(s[0])) & 1
    // checks the letters.find(s[0])th bit of n 
    //0000001
    //1024 = 2^n
    // the 1 goes up 10 times
    // guarantees that every combination will be reached
}

bool check(string s) {
    for (n = 0; n < 1024; n++) {
        if (!myRecursionFunction(s)) {
            return false;
        }
    }
    return true;
}

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            string x;
            getline(cin,x);
            string formula = "";
            for (char&c : x) {
                if (c != ' ') {
                    formula = formula + c;
                }
            }
            //cout << formula << "\n";
            if (check(formula)) {
                cout << "Y";
            } else {
                cout << "N";
            }
        }
        cout << "\n";
    }
}