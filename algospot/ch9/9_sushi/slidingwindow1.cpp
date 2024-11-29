#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<int> M, L;
int c[20001];

int like(int m) {
    int ret = 0;
    for (int i=0; i<=m; ++i) {
        c[i%20001] = 0;
        for (int j=0; j<n; ++j) if (i>=M[j]) c[i%20001] = max(c[i%20001], L[j]+c[(i-M[j])%20001]);
        ret = max(ret, c[i%20001]);
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