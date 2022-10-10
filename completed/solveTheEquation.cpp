// https://leetcode.com/problems/solve-the-equation/
// https://github.com/nexus-x86/cp-solutions
// Sunday October 9 2022

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

pair<int,int> calculate (string s) {
    int coefficient = 0;
    int constant = 0;
    int num = 0;
    int sign = 1;

    for (int i = 0 ; i < s.length(); i++) {
        char c = s[i];
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else if (c == '+' || c == '-') {
            constant += sign * num;
            sign = c == '+' ? 1 : -1;
            num = 0;
        } else {
            if (i > 0 && num == 0 && s[i-1] == '0') {
                continue;
            }
            coefficient += num == 0 ? sign : sign * num;
            num = 0; 
        }
    }
    
    return {coefficient, constant + sign * num};
}

int main() {

    string equation;
    cin >> equation;

    string lhs = equation.substr(0,equation.find('='));
    string rhs = equation.substr(equation.find('=') + 1);

    pair<int,int> l = calculate(lhs);
    pair<int,int> r = calculate(rhs);
    int lhsCoefficient = l.first;
    int lhsConstant = l.second;
    int rhsCoefficient = r.first;
    int rhsConstant = r.second;

    int coefficient = lhsCoefficient - rhsCoefficient;
    int constant = rhsConstant - lhsConstant;

    if (coefficient == 0 && constant == 0) {
        cout << "Infinite solutions" << "\n";
    } else if (coefficient == 0 && constant != 0) {
        cout << "No solution";
    } else {
        cout << "x=" << to_string(constant/coefficient) << "\n";
    }

    return 0;
}