// Given n, find how many BSTs can be made from n nodes numbered 1 to n

#include <iostream>
#include <vector>
using namespace std;

// Top Down DP
int count_BST_TopDown(int n){
    static vector<int> dp(n+1, 0);

    // base case
    if(n==0 or n==1)
        return 1;

    // memoization
    if(dp[n] != 0)
        return dp[n];

    int ans=0;
    for(int i=1; i<=n; i++){
        int x = count_BST_TopDown(i-1);
        int y = count_BST_TopDown(n-i);
        ans += x*y;
    }
    return dp[n] = ans;
}

// Bottom Up DP
int count_BST_BottomUp(int n){
    vector<int> dp(n+1, 1);

    for(int i=2; i<=n; i++){
        int ans = 0;
        for(int j=1; j<=i; j++){
            ans += dp[j-1]*dp[i-j];
        }
        dp[i] = ans;
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << count_BST_TopDown(n) << endl;
    cout << count_BST_BottomUp(n) << endl;
    return 0;
}
