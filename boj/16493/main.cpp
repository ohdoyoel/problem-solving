#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[21][201];
int n, m;
vector<int> D, P;

int page(int i, int days) {
    if (days<0) return -987654321;
    if (i==m) return 0;

    int& ret = cache[i][days];
    if (ret != -1) return ret;

    ret = 0;
    ret = max(ret, page(i+1, days));
    ret = max(ret, P[i] + page(i+1, days-D[i]));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n >> m; D.resize(m); P.resize(m);
    for (int i=0; i<m; ++i) cin >> D[i] >> P[i];
    cout << page(0, n) << endl;
}