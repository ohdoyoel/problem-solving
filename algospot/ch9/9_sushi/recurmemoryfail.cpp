#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<int> L, M;
int cache[21][2147483648];

int like(int i, int money) {
    if (i==n) return 0;
    if (money<0) return -987654321;

    int& ret = cache[i][money];
    if (ret!=-1) return ret;

    ret = like(i+1, money);
    ret = max(ret, L[i]+like(i+1, money-M[i]));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c; cin >> c;
    while (c--) {
        int m; cin >> n >> m; L.resize(n); M.resize(n);
        for (int i=0; i<n; ++i) cin >> L[i] >> M[i];
        cout << like(0, m) << endl;
    }
}