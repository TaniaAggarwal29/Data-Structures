#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int mergingRopes(const vector<int> &ropes){
    priority_queue<int, vector<int>, greater<>> heap(ropes.begin(), ropes.end());
//    for(auto x: ropes){
//        heap.push(x);
//    }
    int ans = 0;
    while(heap.size() > 1){
        int l1 = heap.top();
        heap.pop();
        int l2 = heap.top();
        heap.pop();
        ans += l1+l2;
        heap.push(l1+l2);
    }
    return ans;
}

int main() {
    vector<int> ropes = {3, 4, 2, 6};
    cout << mergingRopes(ropes) << endl;
    return 0;
}
