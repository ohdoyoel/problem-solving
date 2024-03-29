#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n, maxHeight=0;
vector<vector<int>> mapHeight;
vector<vector<int>> visited;

// height만큼 비가 왔을 때 (x,y)에서 안전 구역을 방문
void dfsSafe(int x, int y, int height) {
    visited[x][y] = true;
    if (0<x && !visited[x-1][y] && mapHeight[x-1][y]>height) dfsSafe(x-1, y, height);
    if (x<n-1 && !visited[x+1][y] && mapHeight[x+1][y]>height) dfsSafe(x+1, y, height);
    if (0<y && !visited[x][y-1] && mapHeight[x][y-1]>height) dfsSafe(x, y-1, height);
    if (y<n-1 && !visited[x][y+1] && mapHeight[x][y+1]>height) dfsSafe(x, y+1, height);
}

// height만큼 비가 왔을 때 안전 구역의 개수
int dfsCntSafe(int height) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) visited[i][j] = false;
    }
    
    int ret = 0;
    for (int x=0; x<n; x++){
        for (int y=0; y<n; y++) {
            if (!visited[x][y] && mapHeight[x][y]>height) {
                ret++;
                dfsSafe(x, y, height);
            }
        }
    }
    return ret;
}

// 안전 구역의 개수의 최댓값
int dfsMaxSafe() {
    int ret = 0;
    for (int height=0; height<=maxHeight; height++) ret = max(ret, dfsCntSafe(height));
    return ret;
}

int main() {
    cin >> n; mapHeight.resize(n); visited.resize(n);
    for (int i=0; i<n; i++){
        mapHeight[i].resize(n); visited[i].resize(n);
        for (int j=0; j<n; j++) {
            cin >> mapHeight[i][j];
            maxHeight = max(maxHeight, mapHeight[i][j]);
        }
    }
    cout << dfsMaxSafe() << endl;
}