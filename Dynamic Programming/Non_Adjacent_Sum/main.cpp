// Given an array of positive integers
// return the maximum sum of non-adjacent elements of an array

#include <iostream>
#include <vector>
using namespace std;

// Top Down DP
int max_sum_TD(vector<int> arr, int n){
    static vector<int> dp(n, 0);
    if (n==0) return arr[0];
    if (n==1) return max(arr[0], arr[1]);

    if (dp[n] != 0)
        return dp[n];

    dp[n] = max(max_sum_TD(arr, n-1), max_sum_TD(arr, n-2)+arr[n]);
    return dp[n];
}

// Bottom Up DP
int max_sum_BU(vector<int> arr){
    int n = arr.size();
    if (n==0) return 0;
    if (n==1) return arr[0];

    vector<int> dp(n);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for(int i=2; i<n; i++) {
        dp[i] = max(dp[i-1], arr[i]+dp[i-2]);
    }
    return dp[n-1];
}

int main() {
    vector<int> arr = {6, 10, 12, 7, 9, 14};
    int n = arr.size();
    cout << max_sum_TD(arr, n-1) << endl;
    cout << max_sum_BU(arr) << endl;
    return 0;
}
