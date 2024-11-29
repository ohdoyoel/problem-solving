#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

// k분 30초에 q번 노래가 나올 확률
double c[51][1000001];
int n, k;
vector<int> L, Q;
vector<vector<double>> T;

void prob() {
    for (int i=0; i<=n; ++i) c[i][0] = i==0 ? 1 : 0;
    for (int i=0; i<=k; ++i) {
        for (int j=0; j<=n; ++j) {
            double val = 0;
            for (int l=0; l<=n; ++l) if (i>=L[l]) val += c[l][(i-L[l])] * T[l][j];
            c[j][i] = val;
        }
    }    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ct; cin >> ct;
    while(ct--) {
        int k, m; cin >> n >> k >> m; L.resize(n); T.resize(n); Q.resize(m);
        for (int i=0; i<n; ++i) cin >> L[i];
        for (int i=0; i<n; ++i) {
            T[i].resize(n);
            for (int j=0; j<n; ++j) cin >> T[i][j];
        }
        for (int i=0; i<m; ++i) cin >> Q[i];
        for (int i=0; i<m; ++i) cout << c[Q[i]][k] << " ";
        cout << endl;
    }
}