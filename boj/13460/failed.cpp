#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n, m;
vector<vector<char>> B;

bool findRed() {
    for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) if(B[i][j]=='R') return false;
    return true;
}

void move(int dir) {
    if (dir==0) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (B[i][j]!='#' && B[i][j]!='.' && B[i-1][j]=='.') {
                    B[i-1][j] = B[i][j];
                    B[i][j] = '.'
                }
            }
        }
    }
    else if (dir==1) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (B[i][j]!='#' && B[i][j]!='.' && B[i+1][j]=='.') {
                    B[i+1][j] = B[i][j];
                    B[i][j] = '.'
                }
            }
        }
    }
    else if (dir==2) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (B[i][j]!='#' && B[i][j]!='.' && B[i][j-1]=='.') {
                    B[i][j-1] = B[i][j];
                    B[i][j] = '.'
                }
            }
        }
    }
    else if (dir==3) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (B[i][j]!='#' && B[i][j]!='.' && B[i][j+1]=='.') {
                    B[i][j+1] = B[i][j];
                    B[i][j] = '.'
                }
            }
        }
    }
}

int solve(int depth) {
    if (findRed()) return 0;
    if (depth >= 10) return -1;

    int ret = 987654321;
    vector<vector<char>> _B = B;
    move(0);
    ret = min(ret, solve(depth+1));
    B = B_;
    move(1);
    ret = min(ret, solve(depth+1));
    B = B_;
    move(2);
    ret = min(ret, solve(depth+1));
    B = B_;
    move(3);
    ret = min(ret, solve(depth+1));
    B = B_;
    return ret;
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin >> n >> m; B.resize(n);
    for (int i=0; i<n; ++i) {
        B[i].resize(m);
        for (int j=0; j<m; ++j){
            char x; cin >> x;
            B[i][j] = x;
            if (x=='R') RED = {i, j};
        } 
    }

    cout << solve(0) << endl;

    return 0;
}