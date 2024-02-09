#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int cache[301][3][2];
vector<int> stairs;

int score(int n, int s, int c) {
    int& ret = cache[n][s][c];
    if (ret != 0) return ret;
    
    if (n > sz(stairs) - 1) return ret = -987654321;
    if (n == sz(stairs) - 1) return ret = stairs[n];

    if (c == 1 || score(n + s, 1, c + 1) < score(n + s, 2, c)) {
        return ret = stairs[n] + score(n + s, 2, 0);
    } else {
        return ret = stairs[n] + score(n + s, 1, c + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(cache, 0, sizeof(cache));

    int n;
    cin >> n;
    stairs.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> stairs[i];
    }
    
    cout << max({score(0, 1, 1), score(0, 2, 0), score(1, 1, 1), score(1, 2, 0)}) << endl;
    // cout << score(0, 1, 1) << endl;
    // cout << score(0, 2, 0) << endl;
    // cout << score(1, 1, 1) << endl;
    // cout << score(1, 2, 0) << endl;

    return 0;
}