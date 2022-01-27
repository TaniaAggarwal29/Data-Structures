// In how many ways can you climb to the top of 'n' steps, if you can climb at most 'k' steps ar a time

#include <iostream>
#include <vector>
//using namespace std;

// Normal Recursive Approach
int climb_stairs(int n, int k) {
    if (n==0)
        return 1;
    if (n<0)
        return 0;
    int ans = 0;
    for(int i=1; i<=k; i++)
        ans += climb_stairs(n-i, k);
    return ans;
}

// Top Down DP
int climb_stairs_TD(int n, int k, int *dp){
    if (n==0) return 1;
    if (n<0) return 0;

    if (dp[n] != 0)
        return dp[n];

    int ans = 0;
    for(int jump = 1; jump <= k; jump++)
        ans += climb_stairs_TD(n-jump, k, dp);

    return dp[n] = ans;
}

// Bottom Up DP
int climb_stairs_BU(int n, int k){
    std::vector<int> dp(n+1, 0);
    dp[0] = 1;

    for(int i=1; i<=n; i++){
        for(int jump=1; jump<=k; jump++){
            if (i-jump >= 0){
                dp[i] += dp[i-jump];
            }
        }
    }
    return dp[n];
}

// Optimised Bottom Up DP
int climb_stairs_opt(int n, int k){
    std::vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= k; ++i) {
        dp[i] = 2*dp[i-1];
    }
    for(int i = k+1; i<=n; i++){
        dp[i] = 2*dp[i-1] - dp[i-k-1];
    }
    return dp[n];
}

int main() {
    int n, k;
    std::cin >> n >> k;
    int dp[1000] = {0};
    std::cout << climb_stairs(n, k) << std::endl;
    std::cout << climb_stairs_TD(n, k, dp) << std::endl;
    std::cout << climb_stairs_BU(n, k) << std::endl;
    std::cout << climb_stairs_opt(n, k) << std::endl;
    return 0;
}
