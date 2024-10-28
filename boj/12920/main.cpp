#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[101][10001];
int n, m;
vector<int> V, C, K;

int contentment(int i, int volume) {
    if (volume<0) return -987654321;
    if (i==n) return 0;

    int& ret = cache[i][volume];
    if (ret!=-1) return ret;

    ret = 0;
    for (int j=0; j<=K[i]; ++j) ret = max(ret, j*C[i] + contentment(i+1, volume-j*V[i]));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n >> m; V.resize(n); C.resize(n); K.resize(n);
    for (int i=0; i<n; ++i) cin >> V[i] >> C[i] >> K[i];
    cout << contentment(0, m) << endl;
}