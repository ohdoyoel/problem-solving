#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[501][501];
int n;
vector<vector<int>> feed;
pair<int,int> dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int isSafe(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

int path(int x, int y) {
    int& ret = cache[x][y];
    if (ret!=-1) return ret;

    ret = 1;
    for (int i=0; i<4; i++) {
        int nextX=x+dir[i].first;
        int nextY=y+dir[i].second;
        if (isSafe(nextX, nextY) && feed[nextX][nextY] > feed[x][y]) ret = max(ret, 1+path(nextX, nextY));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    memset(cache, -1, sizeof(cache));
    cin >> n; feed.resize(n);
    for (int i=0; i<n; i++) {
        feed[i].resize(n);
        for (int j=0; j<n; j++) cin >> feed[i][j];
    }

    int res = 0;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) res = max(res, path(i, j));
    cout << res << endl;
}