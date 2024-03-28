#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n, m;
vector<vector<int>> maze;

int minDistance(int x, int y) {
    // cout << x << " " << y << endl;
    if (x>n-1 || y>m-1) return 987654321;
    if (x==n-1 && y==m-1) return 1;
    
    int ret = 987654321;
    if (x<n-1 && maze[x+1][y]==1) {
        maze[x][y] = 0;
        ret = min(ret, 1+minDistance(x+1, y));
        maze[x][y] = 1;
    }
    if (y<m-1 && maze[x][y+1]==1) {
        maze[x][y] = 0;
        ret = min(ret, 1+minDistance(x, y+1));
        maze[x][y] = 1;
    }
    if (0<x && maze[x-1][y]==1) {
        maze[x][y] = 0;
        ret = min(ret, 1+minDistance(x-1, y));
        maze[x][y] = 1;
    }
    if (0<y && maze[x][y-1]==1) {
        maze[x][y] = 0;
        ret = min(ret, 1+minDistance(x, y-1));
        maze[x][y] = 1;
    }
    
    return ret;
}

int main() {
    cin >> n >> m; maze.resize(n);
    for (int i=0; i<n; i++) {
        string line; cin >> line;
        maze[i].resize(m);
        for (int j=0; j<m; j++) maze[i][j] = line[j] - '0';
    }

    cout << minDistance(0, 0) << endl;
}