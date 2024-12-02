#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<int> L, M;
int cache[21][2147400];

int like(int money) {
    if (money<0) return -987654321;

    int& ret = cach[money];
    if (ret!=-1) return ret;

    ret = 0;
    for (int i=0; i<n; ++i) {
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
        cout << like(0, m) << endl;
    }
}