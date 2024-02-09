#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int cache[10001][2];
vector<int> amt;

int maxAmt(int n, int c) {
    int& ret = cache[n][c];
    if (ret != 0) return ret;
    
    if (n > sz(amt) - 1) return ret = -987654321;
    if (n == sz(amt) - 1) return ret = amt[n];

    int maxRest = 0;
    if (c == 0) maxRest = max(maxAmt(n + 1, 1), maxRest);
    maxRest = max(maxAmt(n + 2, 0), maxRest);
    maxRest = max(maxAmt(n + 3, 0), maxRest);
    
    return ret = amt[n] + maxRest;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(cache, 0, sizeof(cache));

    int n;
    cin >> n;
    amt.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> amt[i];
    }
    
    cout << max(maxAmt(0, 0), maxAmt(1, 0)) << endl;
    // cout << maxAmt(0, 0) << endl;
    // cout << maxAmt(1, 0) << endl;

    return 0;
}