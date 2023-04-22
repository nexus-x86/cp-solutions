/*
Implementation of a linked list using pointers
*/

#include <iostream>
#include <string>

using namespace std;

struct scuffedInteger {
    scuffedInteger* forward = nullptr;
    scuffedInteger* backward = nullptr;
    int value = -1;
} currSelected;

void goBack() {
    currSelected = *currSelected.backward;
}

void goForward() {
    currSelected = *currSelected.forward;
}

void setValue(int val) {
    currSelected.value = val;
}

void createVal(int val) {
    scuffedInteger newScuffed;

    newScuffed.value = val;
    //cout << "Created a new element with value: " << val << "\n";
    newScuffed.forward = &currSelected;
    if (currSelected.forward != 0) {
        //cout << "this element's next value is " << newScuffed.nextElement->value << "\n";
    }
    //if (currSelected.value != -1) {
        currSelected.backward = &newScuffed;
    //}

    currSelected = newScuffed;
}

void removeCurr() {
    scuffedInteger trash = currSelected;

    currSelected.forward->backward = currSelected.backward;
    currSelected.backward->forward = currSelected.forward;

    goForward();

    delete &trash;
}

void printCurr() {
    cout << currSelected.value << "\n";
}

void printList() {

    while (currSelected.backward != nullptr) {
        //cout << currSelected.value << " ";
        currSelected = *currSelected.backward;
    }
    
    cout << "\n";
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        string operation;
        cin >> operation;

        if (operation == "+") {
            int val;
            cin >> val;
            createVal(val);
        } else if (operation == "=") {
            int val;
            cin >> val;
            setValue(val);
        } else if (operation == "-") {
            removeCurr();
        } else if (operation == "<") {
            goBack();
        } else if (operation == ">") {
            goForward();
        } else if (operation == "!") {
            printCurr();
        }
        // printList();
    }
    printList();
}