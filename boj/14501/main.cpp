#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int cache[16];
vector<pii> table;

// table의 n번째 날 ~ 끝까지 일했을 때 벌 수 있는 최대 수익
int solve(int n) {
    if (n > sz(table)) return 0;
    
    int & ret = cache[n];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = n; i <= sz(table); ++i) {
        if (i + table[i].first <= sz(table)) {
            ret = max(ret, table[i].second + solve(i + table[i].first));
        }
    }
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    int n;
    cin >> n;
    table.resize(n);
    for (int i = 0; i < n; ++i) cin >> table[i].first >> table[i].second;
    cout << solve(0) << endl;
    return 0;
}