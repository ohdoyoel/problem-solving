#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int cache[1001];

int sol(int n) {
    int& ret = cache[n];
    if (ret != 0) return ret;

    if (n == 1) return ret = 1;
    else if (n == 2) return ret = 3;

    return ret = (sol(n - 1) + 2 * sol(n - 2)) % 10007;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(cache, 0, sizeof(cache));

    int n;
    cin >> n;
    
    cout << sol(n) % 10007 << endl;

    return 0;
}