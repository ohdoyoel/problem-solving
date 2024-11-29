#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<int> M, L;
int c[2147483647];

int like(int m) {
    for (int i=0; i<=m; ++i) {
        c[i] = 0;
        for (int j=0; j<n; ++j) if (i>=M[j]) c[i] = max(c[i], L[j]+c[i-M[j]]);
    }
    return c[m];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    c[0] = 0;
    int ct; cin >> ct;
    while(ct--) {
        int m; cin >> n >> m; M.resize(n); L.resize(n);
        for (int i=0; i<n; ++i) cin >> M[i] >> L[i];
        cout << like(m) << endl;
    }
}