#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[21][301], invest[21][301];
int n, m;
vector<vector<int>> B;

int benefit(int i, int money) {
    if (money<0) return -987654321;
    if (money==0 || i==m) return 0;

    int& ret = cache[i][money];
    if (ret!=-1) return ret;

    ret = 0;
    for (int j=0; j<=n; j++) {
        int cand = B[j][i] + benefit(i+1, money-j);
        if (ret < cand) {
            ret = cand;
            invest[i][money] = j;
        }
    }
    return ret;
}

void showInvest(int i, int money) {
    if (i==m) return;

    int res = invest[i][money];
    cout << res << ' ';
    showInvest(i+1, money-res);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n >> m; B.resize(n+1); B[0].resize(m);
    for (int j=0; j<m; ++j) B[0][j] = 0;
    for (int i=1; i<=n; ++i) {
        B[i].resize(m);
        int x; cin >> x;
        for (int j=0; j<m; j++) cin >> B[i][j];
    }
    cout << benefit(0, n) << endl;
    showInvest(0, n);
}