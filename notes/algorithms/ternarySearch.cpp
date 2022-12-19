#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return -1*pow(x,2) + 6*x - 4.39;
}

double ternarySearch1(double l, double r) {
    double epsilon = 1e-9;
    while (r - l > epsilon) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);
        double f2 = f(m2);
        if (f1 < f2) {
            l = m1;
        } else {
            r = m2;
        }
    }
    return f(l);
}

double ternarySearch2(double l, double r) {
    double epsilon = 1e-9;
    while (r - l > epsilon) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);
        double f2 = f(m2);
        if (f1 < f2) {
            //l = m1;
            r = m1;
        } else {
            //r = m2;
            l = m2;
        }
    }
    return f(l);
}

int main() {
    // given an algebraic function, find the maximum of the function on 
    // the interval [l,r]
    // the interval must only have 1 turning point for ternary search to be applicable
    double max = ternarySearch1(0,6);
    double min = ternarySearch2(0,6);
    cout << max << "\n";
    cout << min << "\n";
}