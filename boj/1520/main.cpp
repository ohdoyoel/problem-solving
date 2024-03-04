#include<bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

int m, n;
vector<vector<int>> height;
int cache[501][501];

// (x, y)에서 출발하여 오른쪽 아래로 내리막길로만 가는 경우의 수
int solve(int x, int y) {
    int & ret = cache[x][y];
    if (ret != -1) return ret;

    if (x == m-1 && y == n-1) return ret = 1;

    ret = 0;
    if (x+1 < m && height[x][y] > height[x+1][y]) ret += solve(x+1, y);
    if (x-1 >= 0 && height[x][y] > height[x-1][y]) ret += solve(x-1, y);
    if (y+1 < n && height[x][y] > height[x][y+1]) ret += solve(x, y+1);
    if (y-1 >= 0 && height[x][y] > height[x][y-1]) ret += solve(x, y-1);
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> m >> n;
    height.resize(m);
    for (int i = 0; i < m; ++i) {
        height[i].resize(n);
        for (int j = 0; j < n; ++j) cin >> height[i][j];
    }

    cout << solve(0, 0) << endl;
}