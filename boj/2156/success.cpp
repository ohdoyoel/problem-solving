#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int cache[10001];
vector<int> amt;

void maxAmt(int n) {
    cache[0] = 0;
    cache[1] = amt[1];
    cache[2] = amt[1] + amt[2];
    
    for (int i = 3; i <= n; ++i) {
        cache[i] = max({
                        cache[i - 3] + amt[i - 1] + amt[i],
                        cache[i - 2] + amt[i],
                        cache[i - 1],
                    });
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(cache, 0, sizeof(cache));

    int n;
    cin >> n;
    amt.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> amt[i];
    }
    
    maxAmt(n);
    
    cout << cache[n] << endl;

    return 0;
}