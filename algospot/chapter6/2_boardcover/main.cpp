#include <bits/stdc++.h>
// #include "bits/stdc++.h"
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int cnt = 0;
vector<vector<bool>> board;

const pii LTYPES[4][3] = {
  { make_pair(0,0), make_pair(0,1), make_pair(1,0) },
  { make_pair(0,0), make_pair(0,1), make_pair(1,1) },
  { make_pair(0,0), make_pair(1,0), make_pair(1,1) },
  { make_pair(0,0), make_pair(1,0), make_pair(1,-1) },
};

bool isWhite(bool b) {
    return b;
}

void printBoard() {
  for (int i = 0; i < sz(board); ++i) {
    string line;
    for (int j = 0; j < sz(board[0]); ++j) {
      if (isWhite(board[i][j])) line += "W";
      else line += "B";
    }
    cout << line << endl;
  }
}

pii findWhite() {
  for (int i = 0; i < sz(board); ++i) {
    for (int j = 0; j < sz(board[0]); ++j) {
      if (isWhite(board[i][j])) return make_pair(i, j);
    }
  }
  return make_pair(-1, -1);
}

bool isLInBoard(int x, int y) {
  return 0 <= x && x < sz(board) && 0 <= y && y < sz(board[0]);
}

bool isLPlacable (int x, int y, int state) {
  for (int i = 0; i < 3; ++i) {
    int nx = x + LTYPES[state][i].first;
    int ny = y + LTYPES[state][i].second;
    // cout << nx << " " << ny << endl;
    if (!isLInBoard(nx, ny) || !isWhite(board[nx][ny])) return false;
  }
  return true;
}

void coverLInBoard(int x, int y, int state, char c) {
  for (auto move : LTYPES[state]) {
    int nx = x + move.first;
    int ny = y + move.second;
    if (c == 'W') board[nx][ny] = true;
    else if (c == 'B') board[nx][ny] = false;
  }
}

void solve() {
  // cout << "{" << endl;
  // printBoard();

  int whiteX = findWhite().first;
  int whiteY = findWhite().second;

  // cout << whiteX << " " << whiteY << endl;

  if (whiteX == -1) {
    cnt++;
    // cout << "cnt = " << cnt << endl;
    // cout << "}" << endl;
    return;
  }

  for (int s = 0; s < 4; ++s) {
    if (isLPlacable(whiteX, whiteY, s)) {
      coverLInBoard(whiteX, whiteY, s, 'B');
      solve();
      coverLInBoard(whiteX, whiteY, s, 'W');
      // printBoard();
    }
  }
  // cout << "}" << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c;
    cin >> c;

    while (c--) {
        int h, w;
        cin >> h >> w;
        board.resize(h);
        for (int j = 0; j < h; ++j) {
            board[j].resize(w);
        }
        int numOfWhite = 0;
        for (int j = 0; j < h; ++j) {
            string line;
            cin >> line;
            for (int k = 0; k < w; ++k) {
                board[j][k] = (line[k] == '.') ? true : false;
                if (line[k] == '.') numOfWhite++;
            }
        }

        cnt = 0;
        solve();
        cout << cnt << endl;
        
        // cout << LTYPES[0][0].first << " " << LTYPES[0][0].second << endl;
        // cout << LTYPES[0][1].first << " " << LTYPES[0][1].second << endl;
        // cout << LTYPES[0][2].first << " " << LTYPES[0][2].second << endl;
        // cout << LTYPES[1] << endl;
        // cout << LTYPES[2] << endl;
        // cout << LTYPES[3] << endl;
    }

    return 0;
}
