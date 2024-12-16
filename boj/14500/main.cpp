#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n, m;
vector<vector<int>> S;

const short COVER[19][4][2] = {
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 0}},
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
    {{0, 2}, {1, 0}, {1, 1}, {1, 2}},
    {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
    {{0, 1}, {1, 1}, {2, 1}, {2, 0}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
    {{0, 0}, {1, 0}, {2, 0}, {0, 1}},
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
    {{1, 0}, {1, 1}, {0, 1}, {0, 2}},
    {{0, 1}, {1, 1}, {1, 0}, {2, 0}},
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
    {{0, 0}, {1, 0}, {2, 0}, {1, 1}},
    {{1, 0}, {1, 1}, {1, 2}, {0, 1}},
    {{0, 1}, {1, 1}, {2, 1}, {1, 0}},
};

bool placable(int r, int c, int k) {
    for (int i=0; i<4; ++i) if (n<=r+COVER[k][i][0] || m<=c+COVER[k][i][1]) return false;
    return true;
}

int score(int r, int c, int k) {
    int ret = 0;
    for (int i=0; i<4; ++i) ret += S[r+COVER[k][i][0]][c+COVER[k][i][1]];
    return ret;
}

int maxScore() {
    int ret = 0;
    for (int r=0; r<n; ++r) {
        for (int c=0; c<m; ++c) {
            for (int i=0; i<19; ++i) if (placable(r, c, i)) ret = max(ret, score(r, c, i));
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m; S.resize(n);
    for (int i=0; i<n; ++i) {
        S[i].resize(m);
        for (int j=0; j<m; ++j) cin >> S[i][j];
    }
    cout << maxScore() << endl;
}