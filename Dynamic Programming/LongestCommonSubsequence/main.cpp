// Given two sequences, find the longest subsequence which is common to them

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Top Down DP
int LCS_TopDown(const string& s1, const string& s2, int i, int j){
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    if(i==n || j==m)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
        return dp[i][j] = 1 + LCS_TopDown(s1, s2, i+1, j+1);

    int op1 = LCS_TopDown(s1, s2, i, j+1);
    int op2 = LCS_TopDown(s1, s2, i+1, j);
    return dp[i][j] = max(op1, op2);
}

// Bottom Up DP
int LCS_BottomUp(const string& s1, const string& s2){
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    // Print the subsequence
    vector<char> ans;
    int i = n, j = m;
    while(i != 0 and j != 0){
        if(dp[i][j] == dp[i][j-1])
            j--;
        else if (dp[i][j] == dp[i-1][j])
            i--;
        else{
            ans.push_back(s1[i-1]);
            i--;
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto x: ans)
        cout << x << " ";
    cout << endl;
    return dp[n][m];
}

int main() {
    cout << LCS_TopDown("ABCDEFGHI", "ABEDGIH", 0, 0) << endl;
    cout << LCS_BottomUp("ABCDEFGHI", "ABEDGIH") << endl;
    return 0;
}
