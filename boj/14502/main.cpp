#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n, m;
vector<vector<short>> M;
vector<pair<int,int>> V;

void moveVirus(int i, int j) {
    M[i][j] = 2; 
    if (i+1<n && M[i+1][j]==0) moveVirus(i+1, j);
    if (j+1<m && M[i][j+1]==0) moveVirus(i, j+1);
    if (0<=i-1 && M[i-1][j]==0) moveVirus(i-1, j);
    if (0<=j-1 && M[i][j-1]==0) moveVirus(i, j-1);
}

int safe() {
    for (auto v : V) moveVirus(v.first, v.second);
    
    int ret = 0;
    for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) if (M[i][j]==0) ret++;
    
    for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) if (M[i][j]==2) M[i][j]=0;
    for (auto v : V) M[v.first][v.second] = 2;
    
    return ret;
}

int solve(int w) {
    if (w==0) return safe();

    int ret = 0;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (M[i][j]==0) {
                M[i][j] = 1;
                ret = max(ret, solve(w-1));
                M[i][j] = 0;
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m; M.resize(n);
    for (int i=0; i<n; ++i) {
        M[i].resize(m);
        for (int j=0; j<m; ++j) {
            int x;
            cin >> x;
            M[i][j] = x;
            if (x==2) V.push_back(make_pair(i, j));
        }
    }
    cout << solve(3) << endl;
}