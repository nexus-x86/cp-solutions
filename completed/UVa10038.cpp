// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=623&page=show_problem&problem=979
// https://github.com/nexus-x86/cp-solutions
// Friday January 6 2023

#include <iostream>
#include <sstream>
#include <string>
#include <set>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    while (cin >> N) {
        set<int> nums;
        int previous = 3001;
        for (int i = 0; i < N; i++) {
            int a;
            cin >> a;
            if (previous != 3001) {
                nums.insert(abs(previous-a));
            }
            previous = a;
        }

        int num = 1;
        int flag = 0;
        for (int a : nums) {
            if (num == a) {
                num++;
            } else {
                flag = 1;
                break;
            }
        }
        
        if (num - 1 != N-1){
            flag = 1;
        }

        if (flag == 1) {
            cout << "Not jolly\n";
        } else {
            cout << "Jolly\n";
        }

    }
}