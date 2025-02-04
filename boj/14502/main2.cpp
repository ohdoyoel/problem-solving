#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n, m;
vector<vector<int>> B;
vector<vector<int>> _B;
vector<pair<int,int>> E;

void virus(int i, int j) {
    _B[i][j] = 2;
    if (i+1<n && _B[i+1][j]==0) virus(i+1, j);
    if (i-1>=0 && _B[i-1][j]==0) virus(i-1, j);
    if (j+1<m && _B[i][j+1]==0) virus(i, j+1);
    if (j-1>=0 && _B[i][j-1]==0) virus(i, j-1);
}

int count() {
    _B = B;
    for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) if (B[i][j]==2) virus(i, j);

    int ret = 0;
    for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) if (_B[i][j]==0) ret++;
    return ret;
}

int solve(int i, int w) {
    if (w==0) return count();
    if (i==E.size()) return -987654321;

    int ret = 0;
    ret = max(ret, solve(i+1, w));
    B[E[i].first][E[i].second] = 1;
    ret = max(ret, solve(i+1, w-1));
    B[E[i].first][E[i].second] = 0;
    return ret;
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m; B.resize(n);
    for (int i=0; i<n; ++i) {
        B[i].resize(m);
        for (int j=0; j<m; ++j) {
            int x; cin >> x;
            B[i][j] = x;
            if (x==0) E.push_back({i, j});
        }
    }
    cout << solve(0,3) << endl;
}