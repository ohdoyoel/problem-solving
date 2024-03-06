#include<bits/stdc++.h>
#define endl "\n";
#define sz(x) (uint)(x).size()
using namespace std;

int n, m;
int cache[1001][1001];
vector<vector<int>> candy;

// (x, y)에서 (n, m)으로 이동할 때 가질 수 있는 사탕의 최대 개수
int solve(int x, int y) {
    int& ret = cache[x][y];
    if (ret != -1) return ret;
    
    if (x == n-1 && y == m-1) return ret = candy[x][y];

    int cur = candy[x][y];
    candy[x][y] = -1;
    if (x < n-1) ret = max(ret, cur + solve(x+1, y));
    if (y < m-1) ret = max(ret, cur + solve(x, y+1));
    if (x < n-1 && y < m-1) ret = max(ret, cur + solve(x+1, y+1));
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n >> m;
    candy.resize(n);
    for (int i = 0; i < n; ++i) {
        candy[i].resize(m);
        for (int j = 0; j < m; ++j) cin >> candy[i][j];
    }
    cout << solve(0, 0) << endl;
}