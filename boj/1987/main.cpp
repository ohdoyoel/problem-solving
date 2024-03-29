#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int r, c;
vector<string> board;
vector<vector<bool>> visited;
string lg;

int dfsHeight(int x, int y) {
    // cout << x << y << board[x][y] << endl;
    visited[x][y] = true;
    lg += board[x][y];
    
    int ret = 1;
    if (0<x && !visited[x-1][y] && lg.find(board[x-1][y])==-1){
        ret = max(ret, 1+dfsHeight(x-1, y));
    }
    if (x<r-1 && !visited[x+1][y] && lg.find(board[x+1][y])==-1){
        ret = max(ret, 1+dfsHeight(x+1, y));
    }
    if (0<y && !visited[x][y-1] && lg.find(board[x][y-1])==-1) {
        ret = max(ret, 1+dfsHeight(x, y-1));
    }
    if (y<c-1 && !visited[x][y+1] && lg.find(board[x][y+1])==-1) {
        ret = max(ret, 1+dfsHeight(x, y+1));
    }
    
    visited[x][y] = false;
    lg.pop_back();
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> r >> c; board.resize(r); visited.resize(r);
    for (int i=0; i<r; i++) {
        visited[i].resize(c);
        cin >> board[i];
    }

    lg = "";
    cout << dfsHeight(0, 0) << endl;
}