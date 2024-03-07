#include<bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

int n;
int cache[3][17][17];
vector<vector<int>> isWall;

// dir가 0이면 가로, 1이면 대각선, 2이면 세로
// (r, c)에서 dir 방향으로 끝났을 때 끝에 도달하는 방법의 수
int solve(int dir, int r, int c) {
    int& ret = cache[dir][r][c];
    if (ret != -1) return ret;

    if (r == n && c == n) return ret = 1;

    ret = 0;
    switch(dir) {
        case 0:
            if (c+1 <= n && !isWall[r][c+1]) ret += solve(0, r, c+1);
            if (r+1 <= n && c+1 <= n && !isWall[r][c+1] && !isWall[r+1][c] && !isWall[r+1][c+1]) ret += solve(1, r+1, c+1);
            break;
        case 1:
            if (c+1 <= n && !isWall[r][c+1]) ret += solve(0, r, c+1);
            if (r+1 <= n && c+1 <= n && !isWall[r][c+1] && !isWall[r+1][c] && !isWall[r+1][c+1]) ret += solve(1, r+1, c+1);
            if (r+1 <= n && !isWall[r+1][c]) ret += solve(2, r+1, c);
            break;
        case 2:
            if (r+1 <= n && c+1 <= n && !isWall[r][c+1] && !isWall[r+1][c] && !isWall[r+1][c+1]) ret += solve(1, r+1, c+1);
            if (r+1 <= n && !isWall[r+1][c]) ret += solve(2, r+1, c);
    }
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n;
    isWall.resize(n+1);
    for (int i = 1; i <= n; ++i) {
        isWall[i].resize(n+1);
        for (int j = 1; j <= n; ++j) cin >> isWall[i][j];
    }
    cout << solve(0, 1, 2) << endl;
}