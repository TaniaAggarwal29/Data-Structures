// Count the number of triplets with indices i, j, k such that elements at those indices are in GP for given common ratio r

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countTriplets(const vector<int> &arr, int r){
    unordered_map<int, int> left, right;
    for(int x: arr){
        right[x]++;
        left[x] = 0;
    }

    int ans = 0;
    for(int x: arr){
        right[x]--;

        if(x%r==0){
            ans += (left[x/r] * right[x*r]);
        }

        left[x]++;
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 16, 4, 16, 64, 16};
    cout << countTriplets(arr, 4) << endl;
    return 0;
}
