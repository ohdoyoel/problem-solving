#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

double cache[101];
int n, m, q;
vector<string> word;
vector<int> R, Q, A;
vector<double> B;
vector<vector<double>> T, M;

double recognize(int i) {
    if (i==n) {
        double ret = B[Q[0]];
        for (int i=0; i<n-1; ++i) ret *= T[Q[i]][Q[i+1]];
        for (int i=0; i<n; ++i) ret *= M[Q[i]][R[i]];
        ret /= B[R[0]];
        for (int i=0; i<n-1; ++i) ret /= T[R[i]][R[i+1]];
        return ret;
    }

    double& ret = cache[i];
    if (ret > 0) return ret;

    ret = 0.0f;
    for (int j=0; j<m; j++) {
        Q[i] = j;
        double cand = recognize(i+1);
        if (ret < cand) {
            ret = cand;
            A[i] = j;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> m >> q; word.resize(m); B.resize(m); T.resize(m); M.resize(m);
    for (int i=0; i<m; ++i) cin >> word[i];
    for (int i=0; i<m; ++i) cin >> B[i];
    for (int i=0; i<m; ++i) {
        T[i].resize(m);
        for (int j=0; j<m; ++j) cin >> T[i][j];
    }
    for (int i=0; i<m; ++i) {
        M[i].resize(m);
        for (int j=0; j<m; ++j) cin >> M[i][j];
    }

    while (q--) {
        for (int i=0; i<101; ++i) cache[i] = -1;
        cin >> n; R.resize(n); Q.resize(n); A.resize(n);
        for (int i=0; i<n; ++i) {
            string w; cin >> w;
            for (int j=0; j<m; ++j) if (w==word[j]) R[i] = j;
        }
        recognize(0);
        for (int a : A) cout << word[a] << ' ';
        cout << endl;
    }
}