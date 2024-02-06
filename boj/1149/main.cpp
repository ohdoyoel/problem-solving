#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int cache[1001][3];
vector<vector<int>> cost;

int rgb(int n, int c) {
    int& ret = cache[n][c];
    if (ret != -1) return ret;
    
    if (n == sz(cost) - 1) return ret = cost[n][c];
    
    if (c == 0) {
        return ret = cost[n][c] + min(rgb(n + 1, 1), rgb(n + 1, 2));
    } else if (c == 1) {
        return ret = cost[n][c] + min(rgb(n + 1, 0), rgb(n + 1, 2));
    } else if (c == 2) {
        return ret = cost[n][c] + min(rgb(n + 1, 0), rgb(n + 1, 1));
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(cache, -1, sizeof(cache));

    int n;
    cin >> n;
    cost.resize(n);
    for (int i = 0; i < n; ++i) {
        int r, g, b;
        cin >> r >> g >> b;
        cost[i].push_back(r);
        cost[i].push_back(g);
        cost[i].push_back(b);
    }

    cout << min({rgb(0, 0), rgb(0, 1), rgb(0, 2)}) << endl;

    return 0;
}