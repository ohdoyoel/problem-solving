#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

double cache[51][1000001];
int n;
vector<int> L, Q;
vector<vector<double>> T;

// k분 30초에 q번 노래가 나올 확률
double prob(int q, int k) {
    if (k==0) return q==0 ? 1 : 0;

    double& ret = cache[q][k];
    if (ret>=0) return ret;

    ret = 0;
    for (int i=0; i<n; ++i) ret += T[i][q] * prob(i, k-L[i]);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c; cin >> c;
    while(c--) {
        for (int i=0; i<51; ++i) for (int j=0; j<1000001; ++j) cache[i][j] = -1;
        int k, m; cin >> n >> k >> m; L.resize(n); T.resize(n); Q.resize(m);
        for (int i=0; i<n; ++i) cin >> L[i];
        for (int i=0; i<n; ++i) {
            T[i].resize(n);
            for (int j=0; j<n; ++j) cin >> T[i][j];
        }
        for (int i=0; i<m; ++i) cin >> Q[i];
        for (int i=0; i<m; ++i) cout << prob(Q[i], k) << " ";
        cout << endl;
    }
}