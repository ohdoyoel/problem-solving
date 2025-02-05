#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n, m;
vector<vector<int>> B;

const short C[19][4][2] = {
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

bool placable(int r, int c, int t) {
    for (int i=0; i<4; ++i) if (r+C[t][i][0]>=n || c+C[t][i][1]>=m) return false;
    return true;
}

int score(int r, int c, int t) {
    int ret = 0;
    for (int i=0; i<4; ++i) ret += B[r+C[t][i][0]][c+C[t][i][1]];
    return ret;
}

int solve() {
    int ret = 0;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            for (int k=0; k<19; ++k) {
                if (placable(i, j, k)) ret = max(ret, score(i, j, k));
            }
        }
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

    cout << solve() << endl;
}