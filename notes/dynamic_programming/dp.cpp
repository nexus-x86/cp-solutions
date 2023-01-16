#include <iostream>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    /*
    Types of DP
    Top down
    Bottom up

    Characterization of DP
    Optimal sub-structures: The optimal solution to the sub-problems is part of the optimal
    solution to the original problem

    Overlapping sub-problems: Overlapping sub-problems occurs and DP stores past results to
    avoid repetitive computation

    Advantages:
    1. Faster than recursion
    2. Will not stack overflow

    Disadvantages:
    1. Lots of memory 
    2. Each DP programming is unique

    Bottom-up vs Top-down
    Top-down (memoization): start from the big problem and see if the sub-problems
    have been computed. (using recursion without recomputing any values)
    1. Pros
    a) Easy to transform
    b) Only compute sub-problems when needed
    2. Cons:
    a) Slower if many sub -problems are revisited
    b) MLE can easily occur

    Bottom-up (tabulation): First look at the smaller sub-problems and then solve
    the larger sub-problems. (Iterative solution)
    1. Pros:
    a) faster due to not using recursion
    b) memory saving is often possible
    2. Cons;
    a) less intuitive than top-down
    b) all states must be computed
    */
}