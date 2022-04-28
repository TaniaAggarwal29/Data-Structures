// Given Ladder containing N steps, you can take a jump of 1, 2, or 3 steps at a time
// Find the number of ways to climb the ladder

#include <iostream>
using namespace std;

int climbLadder(int n) {
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    return climbLadder(n-1) + climbLadder(n-2) + climbLadder(n-3);
}

int main() {
    cout << climbLadder(4) << endl;
    return 0;
}

//                                  5
//                            /     |     \
//                           4      3      2
//                         / | \
//
