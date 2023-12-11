#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int s, n, k, r1, r2, c1, c2;
vector<vector<int>> board;

void printBoard(int r1, int r2, int c1, int c2) {
    for (int i = r1; i <= r2; ++i) {
        for (int j = c1; j <= c2; ++j) {
            cout << board[i][j];
        }
        cout << endl;
    }
}

bool isBoardAllWhite(int x, int y, int len) {
    for (int i = x; i < x + len; ++i) {
        for (int j = y; j < y + len; ++j) {
            if (board[i][j] == 1) return false;
        }
    }
    return true;
}

void boardEdit(int t, int x, int y, int len, int centerLen) {
    if (t == s) return;
    if (isBoardAllWhite(x, y, len)) {
        int cx = x + (len - centerLen) / 2;
        int cy = y + (len - centerLen) / 2;
        for (int i = cx; i < cx + centerLen; ++i) {
            for (int j = cy; j < cy + centerLen; ++j) {
                board[i][j] = 1;
            }
        }

        for (int i = x; i < x + len; i += (len / n)) {
            for (int j = y; j < y + len; j += len / n) {
                if (!(i == cx && j == cy)
                    && (r1 - (len / n)) < i && (i < r2)
                    && (c1 - (len / n)) < j && (j < c2)) boardEdit(t + 1, i, j, len / n, centerLen / n);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;

    board.resize(pow(n, s));
    for (int i = 0; i < pow(n, s); ++i) {
        board[i].resize(pow(n, s));
        for (int j = 0; j < pow(n, s); ++j) {
            board[i][j] = 0;
        }
    }
    
    boardEdit(0, 0, 0, pow(n, s), k * pow(n, s) / n);

    printBoard(r1, r2, c1, c2);
    
    cout << endl;
    printBoard(0, pow(n, s) - 1, 0, pow(n, s) - 1);

    return 0;
}
