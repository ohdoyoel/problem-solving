#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int cache[201][201];

// 0~n 중 k개를 뽑았을 때 합이 n인 경우의 수
int solve(int n, int k) {

    int& ret = cache[n][k];
    if (ret != -1) return ret;
    
    if (k == 0) return ret = 0;
    if (k == 1) return ret = 1;
    if (k == 2) return ret = n + 1;
    if (n == 0) return ret = 1;

    ret = 0;
    for (int i = 0; i <= n; ++i) {
        ret += solve(n - i, k - 1);
        ret %= 1000000000;
    }
    return ret % 1000000000;
}

int main() {
    memset(cache, -1, sizeof(cache));
    int n, k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
}