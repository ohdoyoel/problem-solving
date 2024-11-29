#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<int> M, L;
int c[201];

int like(int money) {
    int ret = 0;
    for (int m=0; m<=money; ++m) {
        int cand = 0;
        for (int i=0; i<n; ++i) if (m>=M[i]) cand = max(cand, c[(m-M[i])%201]+L[i]);
        c[m%201] = cand;
        ret = max(ret, cand);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    c[0] = 0;
    int ct; cin >> ct;
    while(ct--) {
        int m; cin >> n >> m; M.resize(n); L.resize(n);
        for (int i=0; i<n; ++i) cin >> M[i] >> L[i];
        for (int i=0; i<n; ++i) M[i] /= 100;
        cout << like(m/100) << endl;
    }
}