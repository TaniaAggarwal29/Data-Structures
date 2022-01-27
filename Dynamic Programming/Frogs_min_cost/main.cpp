// Given an array of size N, where every element represents the height if i-th stone
// a frog can jump from i-th stone to (i+1)th or (i+2)th stone
// cost of each jump = |Hj - Hi|
// Return the Minimum Cost

#include <iostream>
#include <vector>
using namespace std;

// Top Down DP
int min_jump_cost_TD(vector<int> heights, int n){
    static vector<int> dp(n, 0);

    if(n==0)
        return 0;
    if(n==1)
        return abs(heights[1]-heights[0]);

    if(dp[n] != 0)
        return dp[n];

    dp[n] = min( min_jump_cost_TD(heights, n-1) + abs(heights[n]-heights[n-1]), min_jump_cost_TD(heights, n-2) + abs(heights[n]-heights[n-2]) );
    return dp[n];
}

// Bottom Up DP
int min_jump_cost_BU(vector<int> heights){
    int n = heights.size();
    vector<int> dp(n, 0);
    if(n>1)
        dp[1] = abs(heights[1] - heights[0]);

    for(int i=2; i<n; i++){
        dp[i] = min(dp[i-1]+abs(heights[i]-heights[i-1]), dp[i-2]+abs(heights[i]-heights[i-2]));
    }
    return dp[n-1];
}

int main() {
//    vector<int> arr = {10, 30, 40, 20};
    vector<int> arr = {30, 10, 60, 10, 60, 50};
    int n = arr.size();
    cout << min_jump_cost_TD(arr, n-1) << endl;
    cout << min_jump_cost_BU(arr) << endl;
    return 0;
}
