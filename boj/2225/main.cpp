#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int cache[201][201];

int solve(int n, int k) {
    if (n == 0) return 1;

    int& ret = cache[n][k];
    if (ret != -1) return ret;
    
    if (k == 1) return ret = 1;
    if (k == 2) return ret = n + 1;

    ret = 0;
    for (int i = 0; i <= n; ++i) {
        ret += solve(n - i, k - 1);
    }
    return ret % 1000000000;
}

int main() {
    memset(cache, -1, sizeof(cache));
    int n, k;
    cin >> n >> k;
    cout << solve(n, k) % 1000000000 << endl;
}