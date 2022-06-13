// Given cars and their distance from origin, find the closest k cars

#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Cars{
public:
    string id;
    int x, y;
    Cars(string id, int x, int y){
        this->id = std::move(id);
        this->x = x;
        this->y = y;
    }
    int dist() const {
        return x*x + y*y;
    }
};

class compare{
public:
    bool operator()(const Cars& A, const Cars& B){
        return A.dist() < B.dist();
    }
};

vector<Cars> findCabs(const vector<Cars>& cars, int k){
    priority_queue<Cars, vector<Cars>, compare> heap;
    unsigned int n = cars.size();
    for (int i = 0; i < k; ++i) {
        heap.push(cars[i]);
    }

    for (int i = k; i < n; ++i) {
        if(cars[i].dist() < heap.top().dist()){
            heap.pop();
            heap.push(cars[i]);
        }
    }
    vector<Cars> output;
    while(!heap.empty()){
        output.push_back(heap.top());
        heap.pop();
    }
    reverse(output.begin(), output.end());
    return output;
}

int main() {
    int n;
    cin >> n;
    vector<Cars> cars;
    for(int i=0; i<n; i++){
        string id;
        int x, y;
        cin >> id >> x >> y;
        Cars car = Cars(id, x, y);
        cars.push_back(car);
    }

    vector<Cars> output = findCabs(cars, 3);
    for(const auto& car : output){
        cout << car.id << endl;
    }
    return 0;
}
/*
5
c1 1 1
c2 2 1
c3 3 2
c4 0 1
c5 2 3

*/