// Given an array, where the value at i-th index is the maximum distance that can be covered from that index in single jump.
// Return the minimum number of jumps required to reach the end of the array

#include <iostream>
#include <vector>
using namespace std;


// Top Down DP
int min_jumps(vector<int> arr, int i=0){
    static int n = arr.size();
    static vector<int> dp(n+1, 0);

    // base case
    if (i==n-1)
        return 0;
    if (i >= n)
        return INT_MAX;

    // memoization
    if (dp[i] != 0)
        return dp[i];

    int steps = INT_MAX;
    int max_jump = arr[i];
    for(int jump = 1; jump <= max_jump; jump++){
        int next_cell = i + jump;
        int subprob = min_jumps(arr, next_cell);
        if (subprob != INT_MAX)
            steps = min(steps, subprob+1);
    }
    return dp[i] = steps;
}

// Tabulation
int min_jumps_BU(vector<int> arr){
    int n = arr.size();
    vector<int> dp(n, 0);

    for(int i=n-2; i>=0; i--){
        int max_jump = arr[i];
        dp[i] = INT_MAX;
        for(int jump = 1; jump <= max_jump and i+jump < n; jump++){
            dp[i] = min(dp[i], dp[i+jump]+1);
        }
    }
    return dp[0];
}

int main() {
//    vector<int> arr = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    vector<int> arr = {3, 4, 2, 1, 2, 3, 10, 1, 1, 1, 2, 5};
    cout << min_jumps(arr) << endl;
    cout << min_jumps_BU(arr) << endl;
    return 0;
}
