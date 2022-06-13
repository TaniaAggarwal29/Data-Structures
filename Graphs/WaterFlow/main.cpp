#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfs(vector<vector<int>> &A, int sx, int sy, bool red = true){
    int m = A.size();
    int n = A[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n, false));

    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    while(!q.empty()){
        pair<int, int> node = q.front();
        int i = node.first;
        int j = node.second;
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k];
            int y = j + dy[k];

            if(x>=0 and y>=0 and x<m and y<n and A[x][y] >= A[i][j] and !visited[x][y]){
                if((red and (x==0 or y==0)) or (!red and (x==m-1 or y==n-1)))
                    return true;

                q.push({x, y});
                visited[x][y] = true;
            }
        }
    }
    return false;
}

int solve(vector<vector<int>> &A){
    int m = A.size();
    int n = A[0].size();
    int ans = 0;

    // blue
    for(int i=0; i<n-1; i++){
        bool val = bfs(A, 0, i, false);
        if(val) ans++;
    }
    for(int i=1; i<m-1; i++){
        bool val = bfs(A, i, 0, false);
        if(val) ans++;
    }

    // red
    for(int i=1; i<m; i++){
        bool val = bfs(A, i, n-1);
        if(val) ans++;
    }
    for(int i=1; i<n-1; i++){
        bool val = bfs(A, m-1, i);
        if(val) ans++;
    }
    return ans+2;
}


int main() {
    int m = 11, n=10;
    vector<vector<int>> A = {
            {4, 12, 3, 14, 14, 5, 2, 12, 14, 9},
            {8, 5, 3, 18, 18, 20, 4, 2, 10, 19},
            {17, 16, 11, 3, 9, 7, 1, 3, 5, 9},
            {7, 6, 11, 10, 11, 11, 7, 2, 14, 9},
            {10, 4, 5, 15, 17, 1, 7, 17, 12, 9},
            {5, 20, 7, 4, 18, 19, 19, 3, 10, 2},
            {14, 16, 20, 19, 5, 11, 18, 7, 14, 7},
            {2, 6, 5, 13, 11, 10, 18, 14, 18, 13},
            {7, 11, 2, 17, 16, 8, 16, 15, 12, 13},
            {11, 11, 2, 5, 7, 11, 8, 12, 8, 18},
            {18, 8, 14, 4, 6, 10, 10, 19, 2, 9}
    };
    cout << solve(A) << endl;
    return 0;
}
