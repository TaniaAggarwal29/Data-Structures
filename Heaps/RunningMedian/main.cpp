// Given a running stream of integers, output median of numbers read so far after every input

#include <iostream>
#include <queue>
using namespace std;

void median(){
    // take two heaps -  min heap and max heap
    priority_queue<int> left_heap; // max heap
    priority_queue<int, vector<int>, greater<>> right_heap; // min heap

    int d;
    cin >> d;
    left_heap.push(d);
    float curr_median = d;
    cout << curr_median << " ";
    while (1){
        cin >> d;
        if(d==-1) break;
        if (d <= curr_median){
            left_heap.push(d);
            if((left_heap.size() - right_heap.size()) > 1){
                right_heap.push(left_heap.top());
                left_heap.pop();
            }
        }
        else{
            right_heap.push(d);
            if((right_heap.size() - left_heap.size()) > 1){
                left_heap.push(right_heap.top());
                right_heap.pop();
            }
        }
        if(left_heap.size() > right_heap.size())
            curr_median = left_heap.top();
        else if (right_heap.size() > left_heap.size())
            curr_median = right_heap.top();
        else
            curr_median = (left_heap.top() + right_heap.top())/2.0;
        cout << curr_median << " ";
    }

}

int main() {
    median();
    return 0;
}
