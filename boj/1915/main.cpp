#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[1001][1001];
vector<vector<bool>> board;
int n, m;

// (x, y) 부터 끝까지 가장 큰 정사각형 영역의 넓이
int area(int x, int y) {
    int& ret = cache[x][y];
    if (ret != -1) return ret;

    ret = 0;
    for (int l=1; l<; l++) {
        if (isAllWhite(x, y, l)) ret = max(ret, pow(l, 2));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n, m; board.resize(n);
    for (int i=0; i<n; i++) {
        board[i].resize(m);
        for (int j=0; j<n; j++) cin >> board[i][j];
    }

    cout << area(0, 0) << endl;
}