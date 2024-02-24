#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int cache[10][101];

// s로 시작하고, 길이가 n인 계단수
int solve(int s, int n) {
    if (s == -1) return 0; // 졸라 중요! 먼저 기저 사례 체크 -> 캐시 배열 접근 시 안틀리게

    int & ret = cache[s][n];
    if (ret != -1) return ret;

    if (s == 10) return ret = 0;
    if (n == 1) return ret = 1;

    return ret = (solve(s + 1, n - 1) + solve(s - 1, n - 1)) % 1000000000;    
}

int solve(int n) {
    int ret = 0;
    for (int i = 1; i <= 9; ++i) {
        ret += solve(i, n);
        ret %= 1000000000;
    }
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    int n;
    cin >> n;
    cout << solve(n) << endl;

    return 0;
}