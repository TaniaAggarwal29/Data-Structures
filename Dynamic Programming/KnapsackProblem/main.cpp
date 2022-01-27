// Given weights and prices of n items,
// We need to put a subset of items in a bag of capacity W such that we get maximum total profit in a bag

#include <iostream>
#include <vector>
using namespace std;

// Top Down DP
int maxProfit_TopDown(const vector<int>& prices, const vector<int>& wts, int w, int n){
    static vector<vector<int>> dp(n+1, vector<int>(w+1, -1));

    // base case
    if(n==0 or w==0)
        return 0;

    // memoization
    if (dp[n][w] != -1)
        return dp[n][w];

    // recurrence
    int inc = 0, exc = 0;
    if(wts[n-1] <= w)
        inc = prices[n-1] + maxProfit_TopDown(prices, wts, w-wts[n-1], n-1);
    exc = maxProfit_TopDown(prices, wts, w, n-1);
    return max(inc, exc);
}

// Bottom Up DP
int maxProfit_BottomUp(const vector<int>& prices, const vector<int>& wts, int w){
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=w; j++) {
            int inc = 0, exc = 0;
            if(wts[i-1] <= j)
                inc = prices[i-1] + dp[i-1][j-wts[i-1]];
            exc = dp[i-1][j];
            dp[i][j] = max(inc, exc);
        }
    }
    return dp[n][w];
}

int main() {
    vector<int> prices = {5, 20, 20, 10, 20, 20};
    vector<int> wts = {2, 7, 3, 4, 2, 3};
    int W = 11;
    cout << maxProfit_TopDown(prices, wts, W, prices.size()) << endl;
    cout << maxProfit_BottomUp(prices, wts, W) << endl;

    return 0;
}
