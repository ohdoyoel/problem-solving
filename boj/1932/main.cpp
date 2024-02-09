#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int cache[501][501];
vector<vector<int>> cost;

int path(int x, int y) {
    int& ret = cache[x][y];
    if (ret != 0) return ret;

    if (x == sz(cost) - 1) return ret = cost[x][y];
    return ret = cost[x][y] + max(path(x + 1, y), path(x + 1, y + 1));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(cache, 0, sizeof(cache));

    int n;
    cin >> n;
    cost.resize(n);
    for (int i = 0; i < n; ++i) {
        cost[i].resize(n);
        for (int j = 0; j <= i; ++j) {
            cin >> cost[i][j];
        }
    }
    
    cout << path(0, 0) << endl;

    return 0;
}