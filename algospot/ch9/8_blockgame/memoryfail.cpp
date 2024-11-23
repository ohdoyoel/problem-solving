#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[(1<<25)];
vector<string> B;

bool isInBoard(int x, int y) { return 0 <= x && x < 5 && 0 <= y && y < 5; }

int bijection(vector<string>& board) {
    int ret = 0;
    for (int i=0; i<5; ++i) {
        for (int j=0; j<5; ++j) {
            ret *= 2;
            if (board[i][j]=='#') ret++;
        }
    }
    return ret;
}

int winnable(vector<string>& board) {
    int& ret = cache[bijection(board)];
    if (ret!=-1) return ret;

    for (int r=0; r<5; ++r) {
        for (int c=0; c<5; ++c) {
            if (isInBoard(r, c) && board[r][c]=='.' && isInBoard(r+1, c) && board[r+1][c]=='.') {
                board[r][c] = '#'; board[r+1][c] = '#';
                if (!winnable(board)) return ret = 1;
                board[r][c] = '.'; board[r+1][c] = '.';
            }
            if (isInBoard(r, c) && board[r][c]=='.' && isInBoard(r, c+1) && board[r][c+1]=='.') {
                board[r][c] = '#'; board[r][c+1] = '#';
                if (!winnable(board)) return ret = 1;
                board[r][c] = '.'; board[r][c+1] = '.';
            }
            if (isInBoard(r, c) && board[r][c]=='.' && isInBoard(r, c+1) && board[r][c+1]=='.' && isInBoard(r-1, c+1) && board[r-1][c+1]=='.') {
                board[r][c] = '#'; board[r][c+1] = '#'; board[r-1][c+1] = '#';
                if (!winnable(board)) return ret = 1;
                board[r][c] = '.'; board[r][c+1] = '.'; board[r-1][c+1] = '.';
            }
            if (isInBoard(r, c) && board[r][c]=='.' && isInBoard(r, c+1) && board[r][c+1]=='.' && isInBoard(r+1, c+1) && board[r+1][c+1]=='.') {
                board[r][c] = '#'; board[r][c+1] = '#'; board[r+1][c+1] = '#';
                if (!winnable(board)) return ret = 1;
                board[r][c] = '.'; board[r][c+1] = '.'; board[r+1][c+1] = '.';
            }
            if (isInBoard(r, c) && board[r][c]=='.' && isInBoard(r+1, c) && board[r+1][c]=='.' && isInBoard(r+1, c-1) && board[r+1][c-1]=='.') {
                board[r][c] = '#'; board[r+1][c] = '#'; board[r+1][c-1] = '#';
                if (!winnable(board)) return ret = 1;
                board[r][c] = '.'; board[r+1][c] = '.'; board[r+1][c-1] = '.';
            }
            if (isInBoard(r, c) && board[r][c]=='.' && isInBoard(r+1, c) && board[r+1][c]=='.' && isInBoard(r+1, c+1) && board[r+1][c+1]=='.') {
                board[r][c] = '#'; board[r+1][c] = '#'; board[r+1][c+1] = '#';
                if (!winnable(board)) return ret = 1;
                board[r][c] = '.'; board[r+1][c] = '.'; board[r+1][c+1] = '.';
            }
        }
    }
    return ret = 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c; cin >> c;
    B.resize(5);
    for (int i=0; i<5; i++) B[i].resize(5);
    while(c--) {
        memset(cache, -1, sizeof(cache));
        for (int i=0; i<5; ++i) for (int j=0; j<5; ++j) cin >> B[i][j];
        string res = winnable(B) ? "WINNING" : "LOSING";
        cout << res << endl;
    }
}