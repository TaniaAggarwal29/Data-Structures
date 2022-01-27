// Given an array sequence, find the length of the longest subsequence
// such that the elements of the subsequence are in increasing order

#include <iostream>
#include <vector>
using namespace std;

// Top Down DP
//int longest_subsequence_TD(vector<int> arr, int n){
//    static vector<int> dp(n, 0);
//    if(n==0)
//        return 1;
//
//}

// Bottom Up DP
int longest_subsequence_BU(vector<int> arr){
    int n = arr.size();
    vector<int> dp(n, 1);

    int ans = 1;
    for(int i=1; i<n; i++){
        for(int j=i-1; j>=0; j--){
            if(arr[j]<arr[i])
                dp[i] = max(dp[i], dp[j]+1);
        }
        if(dp[i]>ans)
            ans = dp[i];
    }
    return ans;
}

int main() {
    vector<int> arr = {50, 4, 10, 8, 30, 100, 2, 110, 40, 50, 60};
    cout << longest_subsequence_BU(arr) << endl;
    return 0;
}
