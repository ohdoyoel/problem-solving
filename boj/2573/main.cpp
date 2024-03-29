#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int r, c;
vector<vector<int>> height;
vector<vector<bool>> visited;

void heightMelt() {
    vector<vector<int>> afterMelt = height;
    for (int x=1; x<r-1; x++) {
        for (int y=1; y<c-1; y++) {
            if (afterMelt[x][y]>0) afterMelt[x][y] -= ((height[x-1][y]==0)+(height[x+1][y]==0)+(height[x][y-1]==0)+(height[x][y+1]==0));
            if (afterMelt[x][y]<0) afterMelt[x][y] = 0;
        }
    }
    height = afterMelt;
}

void dfsLand(int x, int y) {
    visited[x][y] = true;
    if (0<x && !visited[x-1][y] && height[x-1][y]>0) dfsLand(x-1, y);
    if (x<r-1 && !visited[x+1][y] && height[x+1][y]>0) dfsLand(x+1, y);
    if (0<y && !visited[x][y-1] && height[x][y-1]>0) dfsLand(x, y-1);
    if (y<c-1 && !visited[x][y+1] && height[x][y+1]>0) dfsLand(x, y+1);
}

int dfsCntLand() {
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) visited[i][j] = false;
    }

    int ret = 0;
    for (int x=0; x<r; x++) {
        for (int y=0; y<c; y++) {
            if (height[x][y]>0 && !visited[x][y]) {
                ret++;
                dfsLand(x, y);
            }
        }
    }
    return ret;
}

bool allMelt() {
    for (int x=0; x<r; x++) {
        for (int y=0; y<c; y++) {
            if (height[x][y]>0) return false;
        }
    }
    return true;
}

int timeForTwo() {
    int ret = 0;
    while(dfsCntLand() < 2) {
        if (allMelt()) return 0;
        heightMelt();
        ret++;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> r >> c; height.resize(r); visited.resize(r);
    for (int i=0; i<r; i++) {
        height[i].resize(c); visited[i].resize(c);
        for (int j=0; j<c; j++) cin >> height[i][j];
    }
    cout << timeForTwo() << endl;
}