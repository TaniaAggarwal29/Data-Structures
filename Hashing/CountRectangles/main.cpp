#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Point{
public:
    int x, y;
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
};

class Compare{
public:
    bool operator()(const Point p1, const Point p2){
        if(p1.x == p2.x)
            return p1.y < p2.y;
        return p1.x < p2.x;
    }
};

int countRectangles(const vector<Point> &points){
    set<Point, Compare> s;
    for (auto point: points) {
        s.insert(point);
    }
    int ans = 0;
    for (auto it = s.begin(); it != prev(s.end()) ; it++) {
        for (auto jt = next(it); jt != s.end() ; jt++) {
            Point p1 = *it;
            Point p2 = *jt;

            if(p1.x==p2.x or p1.y==p2.y)
                continue;

            Point p3 = Point(p1.x, p2.y);
            Point p4 = Point(p2.x, p1.y);

            if(s.find(p3)!=s.end() and s.find(p4)!=s.end())
                ans += 1;
        }
    }
    return ans/2;
}


int main() {
    int n;
    cin >> n;
    vector<Point> points;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        points.push_back(Point(x, y));
    }
    cout << countRectangles(points) << endl;
    return 0;
}

//8
//4 1
//4 0
//0 0
//0 1
//1 1
//1 0
//2 0
//2 1
