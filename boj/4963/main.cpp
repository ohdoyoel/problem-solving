#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int w, h;
vector<vector<bool>> isLand;
vector<vector<bool>> visited;

void dfsLand(int x, int y) {
    visited[x][y] = true;
    
    if (0<x && !visited[x-1][y] && isLand[x-1][y]) dfsLand(x-1, y);
    if (x<h-1 && !visited[x+1][y] && isLand[x+1][y]) dfsLand(x+1, y);
    if (0<y && !visited[x][y-1] && isLand[x][y-1]) dfsLand(x, y-1);
    if (y<w-1 && !visited[x][y+1] && isLand[x][y+1]) dfsLand(x, y+1);
    
    if (0<x && 0<y && !visited[x-1][y-1] && isLand[x-1][y-1]) dfsLand(x-1, y-1);
    if (0<x && y<w-1 && !visited[x-1][y+1] && isLand[x-1][y+1]) dfsLand(x-1, y+1);
    if (x<h-1 && 0<y && !visited[x+1][y-1] && isLand[x+1][y-1]) dfsLand(x+1, y-1);
    if (x<h-1 && y<w-1 && !visited[x+1][y+1] && isLand[x+1][y+1]) dfsLand(x+1, y+1);
}

int dfsCntLand() {
    int ret = 0;
    for (int x=0; x<h; x++) {
        for (int y=0; y<w; y++) {
            if (!visited[x][y] && isLand[x][y]) {
                ret++;
                dfsLand(x, y);
            }
        }
    }
    return ret;
}

int main() {
    while (1) {
        cin >> w >> h;
        if (w==0 && h==0) break;
        isLand.resize(h); visited.resize(h);
        for (int i=0; i<h; i++) {
            isLand[i].resize(w); visited[i].resize(w);
            for (int j=0; j<w; j++) {
                int b; cin >> b;
                isLand[i][j] = (b==1);
            }
        }
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) visited[i][j] = false;
        }
        cout << dfsCntLand() << endl;
    }
}