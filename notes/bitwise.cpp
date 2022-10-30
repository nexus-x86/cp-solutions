// info on printf
#include <cstdio> // necessary for printf
#include <bitset>
#include <string>
#include <iostream>
using namespace std;

long long fastExp(long long a, long long n) {
    long long ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans *= a;
        }
        a *= a;
        n >>= 1;
    }
    return ans;
}

int main() {
    printf("%08d\n",42); // the %08d prints an integer with 8 characters in width and adds leading zeroes, the width
    // of the number is length 8
    printf("%.2f\n", 42.2); // %.2f means float with two places after decimal point


    // some bitwise operators
    // bitwise not  ~ a     
    // bitwise and a & b
    // bitwise or a | b
    // bitwise xor a ^ b
    // bitwise left shift
    // a << n
    // this adds n zeros to the right of the binary vallue of a. this is an alternative to computing a2^n
    // bitwise right shift
    // a >> n
    // delete the right most n digits of the binary value of a. this is an alternative to computing floor(a/2^n)

    // bitset
    // array of booleans that you can apply bitwise operations
    // if the array is small, just use integers and bitwise operations. this is called bitmask
    bitset<100> b;
    b[0] = 1;

    // bitmask
    // 1. bitwise operations are faster than complicated arithmetic operations that involves powers of 2s.
    // 2. bitwise operators are easier to understand if your intention is to modify binary numbers
    // 3. assignment operator can be com=bined with a bit operator
    // x <<= n
    // x shifted to the left by n and x is equal to that
    //same as x=( x << n)

    // set nth bit to  1
    // x |= (1 << n)

    // setting nth bit to 0
    // x &= ~(1 << n)

    //switching nth bit to the other one
    // x ^= (1 << n)

    // check the nth bit
    // (x >> n) & 1

    // smallest power of 2 that divides x:
    // x & -x

    // turn on all bits of size n:
    // (1 << n) - 1
    
    // enumerate all subsets of a given bitmask:
    // 10010 -> 10010 > 10000 > 00010

    int mask = 18;
    for (int subset = mask; subset; subset = (mask & (subset-1))) {
        cout << subset << "\n";
    }

    cout << fastExp(7,20) << "\n";
    

    // GNU C++ compiler functinos for bitmasking
    int n = 20;
    __builtin_popcount( n ); // coutns the number of bits that are on in n
    __builtin_ctz( n ); // number of trailing zeroes of n in binary
    __builtin_clz ( n ); // number of leading zeroes of n in binary
}