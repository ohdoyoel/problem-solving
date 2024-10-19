#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[101][101];

int solve(int n, int up) {
    if (n==0) return 1;
    int& ret = cache[n][up];
    if (ret!=-1) return ret;
    ret = 0;
    for (int p=1; p<=n; p++) {
        ret += (up+p-1) * solve(n-p, p);
        ret %= 10000000;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c; cin >> c;
    while(c--) {
        memset(cache, -1, sizeof(cache));
        int n; cin >> n;
        int res = 0;
        for (int i=1; i<=n; i++) {
            res += solve(n-i, i);
            res %= 10000000;
        }
        cout << res << endl;
    }
    return 0;
}