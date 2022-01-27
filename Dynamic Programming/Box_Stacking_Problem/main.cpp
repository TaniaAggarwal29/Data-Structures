// Given an array of boxes where each box is represented by its width, length and height
// One box can be stacked on top of other only if it has strictly lower dimensions
// Return the maximum height we can stack

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int stack_max_height(vector<vector<int>> boxes){
    int n = boxes.size();
    sort(boxes.begin(), boxes.end(), compare);
    vector<int> dp(n, 0);
    dp[0] = boxes[0][2];
    int ans = 0;
    for(int i=1; i<n; i++){
        dp[i] = boxes[i][2];
        for(int j=i-1; j>=0; j--){
            if(boxes[j][0] < boxes[i][0] and boxes[j][1] < boxes[i][1] and boxes[j][2] < boxes[i][2]){
                int curr_height = boxes[i][2];
                if(dp[j]+curr_height > dp[i])
                    dp[i] = dp[j]+curr_height;
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main() {
    vector<vector<int>> boxes = {{2,1,2}, {3,2,3}, {2,2,8}, {2,3,4}, {2,2,1}, {4,4,5}};
    cout << stack_max_height(boxes) << endl;
    return 0;
}
