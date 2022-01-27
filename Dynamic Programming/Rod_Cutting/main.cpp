// Given a rod of n length and an array containing the profit that can be made selling the (i+1) length piece.
// Maximize the profit.

#include <iostream>
#include <vector>

// Top Down DP
int rod_cutting_TD(int length, std::vector<int> profits){
    if (length == 0)
        return 0;
    static std::vector<int> dp(length+1, 0);

    if (dp[length] != 0)
        return dp[length];

    int profit = 0;
    for(int i=0; i<profits.size(); i++){
        if(length-i-1 >= 0)
            profit = std::max(profit, rod_cutting_TD(length-i-1, profits)+profits[i]);
    }
    return dp[length] = profit;
}

// Bottom Up DP
int rod_cutting_BU(int length, std::vector<int> profits){
    std::vector<int> dp(length+1, 0);

    for(int i=1; i<=length; i++){
        for(int j=0; j<=profits.size() and j<=i; j++){
            if (i-j-1 >= 0)
                dp[i] = std::max(dp[i], dp[i-j-1]+profits[j]);
        }
    }
    return dp[length];
}


int main() {
    int length = 8;
    std::vector<int> profits = {3, 5, 8, 9, 10, 17, 17, 20};
    std::cout << rod_cutting_TD(length, profits) << std::endl;
    std::cout << rod_cutting_BU(length, profits) << std::endl;
    return 0;
}
