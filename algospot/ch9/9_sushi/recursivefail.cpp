#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<int> L, M;
int cache[2147483647];

int like(int money) {
    int& ret = cache[money];
    if (ret!=-1) return ret;

    ret = 0;
    for (int i=0; i<n; ++i) {
        if (money < M[i]) continue;
        ret = max(ret, L[i]+like(money-M[i]));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c; cin >> c;
    while (c--) {
      memset(cache, -1, sizeof(cache));
        int m; cin >> n >> m; L.resize(n); M.resize(n);
        for (int i=0; i<n; ++i) cin >> M[i] >> L[i];
        cout << like(m) << endl;
    }
}