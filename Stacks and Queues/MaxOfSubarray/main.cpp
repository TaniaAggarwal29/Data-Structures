// Given an array and an integer k, find the maximum element for each subarray of size k

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void maxSubArray(vector<int> arr, int k){
    int n = arr.size();
    deque<int> q(k);

    // Process first k elements
    for(int i=0; i<k; i++){
        while(!q.empty() and arr[q.back()] < arr[i])
            q.pop_back();
        q.push_back(i);
    }
    cout << arr[q.front()] << " ";

    // Process remaining elements
    for(int i=k; i<n; i++){
        // check if the front elements are out of current window
        while(!q.empty() and q.front() <= k-i)
            q.pop_front();

        while(!q.empty() and arr[q.back()] < arr[i])
            q.pop_back();

        q.push_back(i);
        cout << arr[q.front()] << " ";
    }

}

int main() {
    vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;
    maxSubArray(arr, k);
    return 0;
}
