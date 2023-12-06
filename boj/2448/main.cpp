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

bool isHaveToBeBlank(int x, int y, int height, int width) {
    if (height == 3) {
      if (x == 1 && y == 2) return true;
      if ((x == 1 && y == 1) || (x == 1 && y == 3) || (x == 2 && y == 2)) return false;
    }
    
    int heightHalf = height / 2;
    int widthHalf = (width + 1) / 2 - 1;

    if ((x + y + 1) < height) return true;
    else if (height < (y - x + 1)) return true;
    else if (x >= heightHalf && 0 < (y - x + 1) && (x + y + 1) <= width) return true;

    return false;
}

void draw(int x, int y, int height, int width) {
    // printBoard();
    // cout << endl;
    
    if (height == 1) return;
    
    int heightHalf = height / 2;
    int widthHalf = (width + 1) / 2 - 1;
    int widthFourth = (widthHalf + 1) / 2 - 1;
    for (int i = x; i < x + height; ++i) {
        for (int j = y; j < y + width; ++j) {
            if (isHaveToBeBlank(i - x, j - y, height, width)) board[i][j] = ' ';
            else if (board[i][j] != ' ') board[i][j] = '*';
        }
    }

    draw(x, y + widthFourth + 1, heightHalf, widthHalf);
    draw(x + heightHalf, y, heightHalf, widthHalf);
    draw(x + heightHalf, y + widthHalf + 1, heightHalf, widthHalf);


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    
    board.resize(n);
    for (int i = 0; i < n; ++i) {
      board[i].resize(2 * n - 1);
    }

    draw(0, 0, n, 2 * n - 1);

    printBoard();

    return 0;
}