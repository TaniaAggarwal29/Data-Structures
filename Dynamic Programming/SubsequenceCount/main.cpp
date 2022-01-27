// Given two strings, find the number of times the second string occurs as a subsequence in the first string

#include <iostream>
#include <vector>
using namespace std;

// Top Down DP
int countSubsequence_TopDown(const string& s1, const string& s2, int i, int j) {
    unsigned int n = s1.length(), m = s2.length();

    // dp[i][j] will consider substrings s1[0..i] and s2[0..j] for an answer
    vector<vector<int>> dp(n, vector<int> (m, -1));

    // base case
    // if both the strings are finished, or s2 is finished
    if((i==-1 and j==-1) or j==-1)
        return 1;
    // if s1 alone is finished
    if (i==-1)
        return 0;

    // Memoization
    if(dp[i][j] != -1)
        return dp[i][j];

    // recursive case
    if(s1[i] == s2[j])
        return dp[i][j] = countSubsequence_TopDown(s1, s2, i-1, j-1) + countSubsequence_TopDown(s1, s2, i-1, j);

    return dp[i][j] = countSubsequence_TopDown(s1, s2, i-1, j);
}

// Bottom Up DP
int countSubsequence_BottomUp(string s1, string s2){
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++){
            if(j==0){
                dp[i][j] = 1;
                continue;
            }
            if(i==0){
                dp[i][j] = 0;
                continue;
            }
            if(s1[i] == s2[j]) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n-1][m-1];
}

int main() {
    string s1 = "ABBCCDGCCH";
    string s2 = "ABC";
    cout << countSubsequence_TopDown(s1, s2, s1.length()-1, s2.length()-1) << endl;
    cout << countSubsequence_BottomUp(s1, s2) << endl;
    return 0;
}
