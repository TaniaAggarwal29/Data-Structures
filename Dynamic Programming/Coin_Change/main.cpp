// Minimum number of coins from the given array of coins, that make up for a change of target money

#include <iostream>
#include <vector>

// Top Down DP
int min_coins_TD(int target, std::vector<int> coins, std::vector<int> dp) {
    if (target == 0)
        return 0;

    if (dp[target] != 0)
        return dp[target];

    int ans = INT_MAX;
    for(int i=0; i<coins.size(); i++){
        if (target-coins[i] >= 0)
            ans = std::min(ans, min_coins_TD(target-coins[i], coins, dp)+1);
    }
    return dp[target] = ans;
}

// Bottom Up DP
int min_coins_BU(int target, std::vector<int> coins){
    std::vector<int> dp(target+1, 0);
    dp[0] = 0;

    for(int i=1; i<=target; i++){
        int ans = INT_MAX;
        for(int j=0; j<coins.size(); j++){
            if(i-coins[j] >= 0)
                ans = std::min(ans, dp[i-coins[j]]+1);
        }
        dp[i] = ans;
    }
    return dp[target]==INT_MAX? -1: dp[target];
}

int min_coins_divyam(int n, std::vector<int> denoms){
    if (n==0) return 0;

    static std::vector<int> dp(n+1, 0);
    int Min = INT_MAX;
    if (dp[n] != 0)
        return dp[n];
    for(int i=0; i<denoms.size(); i++){
        if (n-denoms[i] >= 0){
            int x = min_coins_divyam(n-denoms[i], denoms);
            if (Min > x)
                Min = x;
        }
    }
    return dp[n] = Min+1;
}

int main() {
    std::vector<int> coins = {2, 5};
//    std::vector<int> coins = {1, 3, 7, 10};
    std::vector<int> dp(1000, 0);
    int target_money = 3;
    std::cout << min_coins_TD(target_money, coins, dp) << std::endl;
    std::cout << min_coins_BU(target_money, coins) << std::endl;
    std::cout << min_coins_divyam(target_money, coins) << std::endl;
    return 0;
}
