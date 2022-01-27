// We have an array that gives the prices of n wines
// Every year we can sell 1 wine bottle only, and it will be sold at the price = prices[i]*year
// You can only sell either leftmost bottle or rightmost bottle every year
// What is the maximum profit that can be made selling all the wines

#include <iostream>
#include <vector>
using namespace std;

// Top Down DP
int maxProfit_TopDown(const vector<int>& prices, int start, int end){
    int n = prices.size();

    // dp[i][j] stores max profit that can be earned by selling ith to jth bottles
    static vector<vector<int>> dp(n, vector<int>(n, -1));

    if(start > end)
        return 0;

    // memoization
    if(dp[start][end] != -1)
        return dp[start][end];

    // recursion
    int year = n-(end-start);
    if(start==end)
        return dp[start][end] = prices[start]*year;

    int p1 = prices[start]*year + maxProfit_TopDown(prices, start+1, end);
    int p2 = prices[end]*year + maxProfit_TopDown(prices, start, end-1);
    return dp[start][end] = max(p1, p2);
}

// Bottom Up DP
// We'll fill up diagonally-- because dp[i][i] would mean only one element is left and for it maxmimum profit can have only one value
int maxProfit_BottomUp(const vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i = n-1; i>=0; i--) {
        for(int j=0; j<n; j++) {
            if(i==j)
                dp[i][j] = prices[i]*n;
            else if (i<j) {
                int year = n-(j-i);
                int p1 = prices[i]*year + dp[i+1][j];
                int p2 = prices[j]*year + dp[i][j-1];
                dp[i][j] = max(p1, p2);
            }
        }
    }
    return dp[0][n-1];
}

int main() {
    vector<int> prices = {2, 3, 5, 1, 4};
    int n = prices.size();
    cout << maxProfit_TopDown(prices, 0, n-1) << endl;
    cout << maxProfit_BottomUp(prices) << endl;
    return 0;
}
