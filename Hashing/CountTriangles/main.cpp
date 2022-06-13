// Given points (xy coordinates), how many right-angled triangles are possible whose base and perpendicular are parallel to x, y axis

#include <iostream>
#include <vector>
#include <unordered_map>

int countTriangles(std::vector<std::pair<int, int>> &points){
    std::unordered_map<int, int> freq_x;
    std::unordered_map<int, int> freq_y;

    for(auto point: points){
        freq_x[point.first]++;
        freq_y[point.second]++;
    }

    int count = 0;
    for (auto point: points) {
        int x = point.first;
        int y = point.second;

        int fx = freq_x[x];
        int fy = freq_y[y];

        count += (fx-1)*(fy-1);
    }
    return count;
}

int main() {
    std::vector<std::pair<int, int>> points = {{1, 2}, {2, 1}, {2, 2}, {2, 3}, {3, 2}};
    std::cout << countTriangles(points) << std::endl;
    return 0;
}
