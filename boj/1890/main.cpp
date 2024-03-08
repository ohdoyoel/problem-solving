#include<bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;

int n;
vector<vector<int>> dis;
lld cache[101][101];

// (x,y)에서 출발해서 가는 경우의 수
lld solve(int x, int y) {
    lld& ret = cache[x][y];
    if (ret != -1) return ret;

    if (x == n-1 && y == n-1) return ret = 1;
    else if (x > n-1 || y > n-1) return ret = 0;

    ret = 0;
    ret += solve(x + dis[x][y], y);
    ret += solve(x, y + dis[x][y]);
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n;
    dis.resize(n);
    for (int i = 0; i < n; ++i) {
        dis[i].resize(n);
        for (int j = 0; j < n; ++j) cin >> dis[i][j];
    }
    cout << solve(0, 0) << endl;
}