#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

vector<string> board;

void printBoard() {
    for (int i = 0; i < sz(board); ++i) {
        for (int j = 0; j < sz(board[0]); ++j) {
            cout << board[i][j];
        }
        cout << endl;
    }
}

void draw(int x, int y, int length) {
    if (length == 1) return;
    
    int lengthThird = length / 3;
    for (int i = x; i < x + length; ++i) {
        for (int j = y; j < y + length; ++j) {
            if ((x + lengthThird <= i) && (i < x + 2 * lengthThird) && (y + lengthThird <= j) && (j < y + 2 * lengthThird)) board[i][j] = ' ';
            else if (board[i][j] != ' ') board[i][j] = '*';
        }
    }
    draw(x, y, lengthThird);
    draw(x + lengthThird, y, lengthThird);
    draw(x + 2 * lengthThird, y, lengthThird);
    draw(x, y + lengthThird, lengthThird);
    draw(x + lengthThird, y + lengthThird, lengthThird);
    draw(x + 2 * lengthThird, y + lengthThird, lengthThird);
    draw(x, y + 2 * lengthThird, lengthThird);
    draw(x + lengthThird, y + 2 * lengthThird, lengthThird);
    draw(x + 2 * lengthThird, y + 2 * lengthThird, lengthThird);
    // printBoard();
    // cout << endl;
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

    draw(0, 0, n);

    printBoard();

    return 0;
}