#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n, m;
vector<vector<char>> B;

bool findRed() {
    for (int i=0; i<B.size(); ++i) for (int j=0; j<B[0].size(); ++j) if(B[i][j]=='R') return false;
    return true;
}

void rotate() {
    vector<vector<char>> _B;
    _B.resize(B[0].size());
    for (int i=0; i<B[0].size(); ++i) B[i].resize(B.size());
    for (int i=0; i<B.size(); ++i) {
        for (int j=0; j<B[0].size(); ++j) {
            _B[i][j] = B[j][B[0].size()-i];
        }
    }
}

void move() {
    for (int i=0; i<B.size(); ++i) {
        vector<char> line = B[i];
        for (int j=0; j<line.size(); ++j) {
            if (line[j]!='#' && line[j]!='.' && line[j]!='O') {
                int idx = j;
                while (idx>0 && line[idx]!='#' && line[idx]!='.' && line[idx]!='O') idx--;
                if (line[j]=='R' && line[idx-1]=='O') {
                    line[idx] = '.';
                    line[j] = '.';
                }
                line[idx] = line[j];
                line[j] = '.';
            }
        }
    }
}

int solve(int depth, int dir) {
    if (findRed()) return 0;
    if (depth >= 10) return -1;

    int ret = 987654321;
    vector<vector<char>> _B = B;
    for (int r=0; r<4; ++r) {
        if (r==dir || r==((dir+2)%4)) continue;
        for (int i=0; i<r; ++i) rotate();
        move();
        ret = min(ret, solve(depth+1, r));
        B = _B;
    }
    return ret;
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin >> n >> m; B.resize(n);
    for (int i=0; i<n; ++i) {
        B[i].resize(m);
        for (int j=0; j<m; ++j) cin >> B[i][j];
    }

    cout << solve(0, -1) << endl;

    return 0;
}