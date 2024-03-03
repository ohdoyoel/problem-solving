#include<bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

int cache[101][101];

// 첫 줄에 k개가 들어갈 때, n개의 조각으로 만들 수 있는 세로 단조 폴리오미노의 수
int solve(int n, int k) {
    int& ret = cache[n][k];
    if (ret != -1) return ret;
    
    if (n == k || n == 0 || n == 1) return ret = 1;

    ret = 0;
    for (int next = 1; next <= n - k; ++next) {
        // cout << "(" << n - k << " " << next << " " << solve(n - k, next) << ")" << endl;
        ret += ((k + next - 1) * solve(n - k, next)) % 10000000;
        ret %= 10000000;
    }
    return ret;
}

int main() {
    int c;
    cin >> c;
    while(c--) {
        memset(cache, -1, sizeof(cache));
        int n;
        cin >> n;
        int res = 0;
        for (int first = 1; first <= n; ++first) {
            // cout << "(" << n << " " << first << " " << solve(n, first) << ")" << endl;
            res += solve(n, first) % 10000000;
            res %= 10000000;
        }
        cout << res << endl;
    }
}