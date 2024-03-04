#include<bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

double cache[51][101];
vector<vector<int>> isConnected;
int p;

int numOfConnected(int vlg) {
    int ret = 0;
    for (int c = 0; c < sz(isConnected); ++c) if (isConnected[vlg][c]) ret++;
    return ret;
}

// d일 뒤에 q에 있을 확률
double prob(int q, int d) {
    double& ret = cache[q][d];
    if (ret >= 0) return ret;

    if (d == 0) {
        if (q == p) return 1.0f;
        return 0.0f;
    }

    ret = 0.0f;
    for (int vlg = 0; vlg < sz(isConnected); ++vlg) if (isConnected[q][vlg]) ret += prob(vlg, d - 1) / numOfConnected(vlg);
    return ret;
}

int main() {
    cout << fixed;
    cout.precision(8);
    int c;
    cin >> c;
    while(c--) {
        for (int i = 0; i < 51; ++i) for (int j = 0; j < 101; ++j) cache[i][j] = -1.0f;
        int n, d;
        cin >> n >> d >> p;
        isConnected.resize(n);
        for (int i = 0; i < n; ++i) {
            isConnected[i].resize(n);
            for (int j = 0; j < n; ++j) cin >> isConnected[i][j];
        }
        int t;
        cin >> t;
        while(t--) {
            int q;
            cin >> q;
            cout << prob(q, d) << " ";
        }
        cout << endl;
    }
}