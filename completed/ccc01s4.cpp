#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long double ld;
typedef pair<ld,ld> Point;
int N;
const int mx = 12;
Point points[mx];

ld distance(Point a, Point b) {
    return sqrt(pow(a.second-b.second,2)  + pow (a.first- b.first,2));
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    // r = abc/4*sqrt(s(s-a)(s-b)(s-c) where
    // s is the semi perimeter: (a+b+c)/2
    // take every combination of 3 points, calculate diameter of the circle
    // and the maximum is the answer
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
    }

    ld minDiam = -100;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            for (int k = j+1; k < N; k++) {
                Point a = points[i];
                Point b = points[j];
                Point c = points[k];
                ld d1 = distance(b,a);
                ld d2 = distance(a,c);
                ld d3 = distance(b,c);
                ld s = (d1 + d2 + d3)/2;
                ld dist = 0;
                // obtuse triangle check
                if (((d1*d1+d2*d2+-d3*d3<0)||(d2*d2+d3*d3-d1*d1<0)||(d3*d3+d1*d1-d2*d2<0))) {
                    dist = max({d1,d2,d3});
                } else {
                    dist = (d1*d2*d3)/(2*sqrt(s*(s-d1)*(s-d2)*(s-d3)));
                }
                minDiam = max(minDiam, dist);
            }
        }
    }
    printf("%.2Lf\n", minDiam);
}