#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

vector<vector<int>> board;
int cntOne;
int cntZero;
int cntMinusOne;

bool allUniVal(int x, int y, int length, int val) {
    for (int i = x; i < x + length; ++i) {
        for (int j = y; j < y + length; ++j) {
            if (board[i][j] != val) return false;
        }
    }
    return true;
}

void solve(int x, int y, int length) {
    if (allUniVal(x, y, length, 1)) {
        cntOne++;
        return;
    } else if (allUniVal(x, y, length, 0)) {
        cntZero++;
        return;
    } else if (allUniVal(x, y, length, -1)) {
        cntMinusOne++;
        return;
    }
    if (length == 1) return;

    int lengthThird = length / 3;
    solve(x, y, lengthThird);
    solve(x + lengthThird, y, lengthThird);
    solve(x + 2 * lengthThird, y, lengthThird);
    solve(x, y + lengthThird, lengthThird);
    solve(x + lengthThird, y + lengthThird, lengthThird);
    solve(x + 2 * lengthThird, y + lengthThird, lengthThird);
    solve(x, y + 2 * lengthThird, lengthThird);
    solve(x + lengthThird, y + 2 * lengthThird, lengthThird);
    solve(x + 2 * lengthThird, y + 2 * lengthThird, lengthThird);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    board.resize(n);
    for (int i = 0; i < n; ++i) {
        board[i].resize(n);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    cntOne = 0;
    cntZero = 0;
    cntMinusOne = 0;

    solve(0, 0, n);

    cout << cntMinusOne << endl;
    cout << cntZero << endl;
    cout << cntOne << endl;

    return 0;
}