#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<vector<int>> B;
vector<vector<int>> B2;
vector<int> A;

void moveCell(int r, int c, int d) {
    if (B2[r][c]==0 || r<0 || n<=r || c<0 || n<=c) return;
    if (d==0) {
        if (r-1<0) return;
        if (B2[r-1][c]==0) {
            B2[r-1][c] = B2[r][c];
            B2[r][c] = 0;
            moveCell(r-1, c, 0);
        } else if (B2[r-1][c]==B2[r][c]) {
            B2[r-1][c] *= 2;
            B2[r][c] = 0;
        }
    } else if (d==1) {
        if (c+1==n) return;
        if (B2[r][c+1]==0) {
            B2[r][c+1] = B2[r][c];
            B2[r][c] = 0;
            moveCell(r, c+1, 1);
        } else if (B2[r][c+1]==B2[r][c]) {
            B2[r][c+1] *= 2;
            B2[r][c] = 0;
        }
    } else if (d==2) {
        if (r+1==n) return;
        if (B2[r+1][c]==0) {
            B2[r+1][c] = B2[r][c];
            B2[r][c] = 0;
            moveCell(r+1, c, 2);
        } else if (B2[r+1][c]==B2[r][c]) {
            B2[r+1][c] *= 2;
            B2[r][c] = 0;
        }
    } else if (d==3) {
        if (c-1<0) return;
        if (B2[r][c-1]==0) {
            B2[r][c-1] = B2[r][c];
            B2[r][c] = 0;
            moveCell(r, c-1, 3);
        } else if (B2[r][c-1]==B2[r][c]) {
            B2[r][c-1] *= 2;
            B2[r][c] = 0;
        }
    }
}

void moveB2(int d) {
    if (d==0) {
        for (int c=0; c<n; ++c) {
            for (int r=0; r<n; ++r) moveCell(r, c, d);
        }
    } else if (d==1) {
        for (int r=0; r<n; ++r) {
            for (int c=n-1; c>=0; --c) moveCell(r, c, d);
        }
    } else if (d==2) {
        for (int c=0; c<n; ++c) {
            for (int r=n-1; r>=0; --r) moveCell(r, c, d);
        }
    } else if (d==3) {
        for (int r=0; r<n; ++r) {
            for (int c=0; c<n; ++c) moveCell(r, c, d);
        }
    }
    
    // cout << "d: " << d << endl;
    //     for (auto l : B2) {
    //     for (int e : l) cout << std::setfill('0') << std::setw(2) << e << ' ';
    //     cout << endl;
    // }
    // cout << endl;
}

int maxScoreInB() {
    B2 = B;
    for (int a : A) moveB2(a);

    int ret = 0;
    for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) ret = max(ret, B2[i][j]);
    
    if (ret ==4) {
        B2 = B;
        for (int a : A) {
            moveB2(a);
            cout << a << ' ';
            cout << endl;
            for (auto l : B2) {
                for (int e : l) cout << std::setfill('0') << std::setw(2) << e << ' ';
                cout << endl;
            }
        }
        cout << endl;
    }
    return ret;
}

int solve() {
    if (A.size()==1) return maxScoreInB();
    
    int ret = 0;
    for (int i=0; i<4; ++i) {
        A.push_back(i);
        // ret = max(ret, solve());
        if (ret < solve()) {
            ret = solve();

            // for (auto l : B2) {
            //     for (int e : l) cout << std::setfill('0') << std::setw(2) << e << ' ';
            //     cout << endl;
            // }
            // cout << endl;
        }
        A.pop_back();
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; B.resize(n);
    for (int i=0; i<n; ++i) { 
        B[i].resize(n);
        for (int j=0; j<n; ++j) cin >> B[i][j];
    }
    cout << solve() << endl;
}