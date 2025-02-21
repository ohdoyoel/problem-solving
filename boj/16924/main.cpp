#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n, m;
vector<vector<int>> B;
vector<vector<int>> ANS;

bool possible(int r, int c, int s) {
    for (int i=r-s; i<=r+s; ++i) if (B[i][c]==0) return false;
    for (int i=c-s; i<=c+s; ++i) if (B[r][i]==0) return false;
    return true;
}

void setB(int r, int c, int s) {
    for (int i=r-s; i<=r+s; ++i) B[i][c]++;
    for (int i=c-s; i<=c+s; ++i) B[r][i]++;
}

bool hasBlank() {
    for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) if (B[i][j]==1) return true;
    return false;
}

void solve() {
    for (int s=1; s<min(n,m); s++) {
        for (int i=s; i<n-s; ++i) {
            for (int j=s; j<m-s; ++j) {
                if (possible(i, j, s)) {
                    ANS.push_back({i+1, j+1, s});
                    setB(i, j, s);
                }
            }
        }
    }
    if (hasBlank()) ANS.clear();
}

int main() {
    cin >> n >> m;
    B.assign(n, vector<int>(m, 0));
    for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) {
        char c; cin >> c;
        if (c=='*') B[i][j] = 1;
    }
    solve();
    
    if (ANS.size()==0) cout << -1 << endl;
    else {
        cout << ANS.size() << endl;
        for (auto a : ANS)  cout << a[0] << " " << a[1] << " " << a[2] << endl;
    }
}