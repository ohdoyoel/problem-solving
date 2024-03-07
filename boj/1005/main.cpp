#include<bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

int cache[1001];
vector<int> spentTime;
vector<vector<int>> before;

// n번 건물을 짓는데 걸리는 최소 시간 점화식: time[n] + max({solve(before[n])})
int solve(int n) {
    int& ret = cache[n];
    if (ret != -1) return ret;

    ret = spentTime[n];
    for (int b : before[n]) ret = max(ret, spentTime[n] + solve(b));
    return ret;
}

int main() {
    int t; cin >> t;
    while (t--) {
        memset(cache, -1, sizeof(cache));
        int n, k; cin >> n >> k;
        spentTime.resize(n+1); for (int i = 1; i <= n; ++i) cin >> spentTime[i];
        before.resize(n+1); for (int i = 1; i <= n; ++i) before[i] = {};
        while(k--) {
            int x, y; cin >> x >> y;
            before[y].push_back(x);
        }
        int w; cin >> w;
        cout << solve(w) << endl;
    }
}