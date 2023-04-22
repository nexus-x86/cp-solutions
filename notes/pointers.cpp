/*
Notes document for pointers
*/

#include <iostream>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int x;

    int *p1 = &x; // non-const pointer to non-const int
    const int *p2 = &x; // non-const pointer to const int
    int *const p3 = &x; // const pointer to non-const int
    const int *const p4 = &x; // const pointer to const int

    // The pointer to a string points to the first character of the string.
    // the string ends with a null terminating character
    const char *foo = "hello";
    cout << *(foo + 3) << "\n";
    cout << foo[3] << " <=\n";

    // pointers to pointers
    // it is possible to have a pointer that point to pointers. Add a * for each
    // layer of pointers
    char a;
    char *b;
    char **c;
    a = 'z';
    b = &a;
    c = &b;

    // void pointers
    // a pointer can be saved as a void, which mean any pointer can be passed 
    // into it. The trade-off for this felxibility is that it cannot be
    // dereferenced unless its it is casted into a pointer with a type.
    
    // invalid pointers
    // c++ allows you to define a pointer uninitialized or point to any memory without raising an error until you attempt to dereference it
    int *p;
    int myArray[10];
    int *q = myArray+20; // element out of bounds


    // null pointers
    // a null point is a pointer that points to nowhere.
    int *p = 0;
    int *q = nullptr;

    // dynamic memory
    // an array can be define in the following way
    int *foo = new int[5];
    // at the end of your code, you need to put
    // delete foo, to remove the memory
    delete foo;

    
}