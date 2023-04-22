#include <iostream>

using namespace std;

struct product {
    int weight;
    double price;
}; // apple,banana,melon;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    product apple;
    product banana, melon;

    apple.price = 0;
    // arrow operator
    // if a pointer points to a struct, its elements can be dereferenced
    // with the arrow operator

    product t;
    product *apples = &t;
    apples->price = 1;
    (*apples).weight = 10; // alternative
}