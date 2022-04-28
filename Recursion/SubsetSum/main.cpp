// Given a set of non-negative integers, and a value 'sum'
// determine if there's a subset of the given set with sum equal to given sum.

#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(vector<int> arr, int sum, int index) {
    if(sum==0)
        return true;
    if(sum < 0 or index >= arr.size())
        return false;
    return subsetSum(arr, sum-arr[index], index+1) or subsetSum(arr, sum, index+1);
}

// count subsets with sum equal to given sum
int countSubsets(vector<int> arr, int sum, int index){
    if(sum==0)
        return 1;
    if(sum<0 or index >= arr.size())
        return 0;

    int ans = countSubsets(arr, sum-arr[index], index+1) + countSubsets(arr, sum, index+1);
    return ans;
}

int main() {
    vector<int> arr = {10, 12, 15, 6, 19, 20, 1, 4};
//    vector<int> arr = {10, 15, 6, 1};
    cout << subsetSum(arr, 17, 0) << endl;
    cout << countSubsets(arr, 16, 0) << endl;
    return 0;
}
