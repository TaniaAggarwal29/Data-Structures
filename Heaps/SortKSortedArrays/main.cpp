#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class obj{
public:
    int val, x, y;
    obj(int val, int x, int y){
        this->val = val;
        this->x = x;
        this->y = y;
    }
};

class comparator{
public:
    bool operator()(obj a, obj b){
        return a.val > b.val;
    }
};

vector<int> mergeKArrays(const vector<vector<int>>& arr){
    vector<int> output;
    unsigned int n = arr.size();
    priority_queue<obj, vector<obj>, comparator> heap;

    for (int i = 0; i < n; ++i) {
        heap.push(obj(arr[i][0], i, 0));
    }

    while (!heap.empty()){
        obj temp = heap.top();
        heap.pop();
        output.push_back(temp.val);
        if(temp.y < arr[temp.x].size()-1){
            heap.push(obj(arr[temp.x][temp.y+1], temp.x, temp.y+1));
        }
    }

    return output;
}


int main() {
    vector<vector<int>> arr = {
            {0, 3, 6, 9},
            {1, 4, 7, 10},
            {2, 5, 8, 11}
    };
    vector<int> ans = mergeKArrays(arr);
    for (int x: ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
