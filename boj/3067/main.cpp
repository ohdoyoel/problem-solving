#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[21][10001];
int n;
vector<int> C;

int coin(int i, int money) {
    if (money==0) return 1;
    if (money<0||i==n) return 0;

    int& ret = cache[i][money];
    if (ret!=-1) return ret;

    ret = 0;
    for (int j=0; j<=money/C[i]; ++j) ret += coin(i+1, money-j*C[i]);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--){
        memset(cache, -1, sizeof(cache));
        cin >> n; C.resize(n);
        for (int i=0; i<n; ++i) cin >> C[i];
        int m; cin >> m;
        cout << coin(0, m) << endl;
    }
}