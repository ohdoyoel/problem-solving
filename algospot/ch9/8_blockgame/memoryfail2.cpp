#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[(1<<25)];
int B;

bool isInBoard(int x, int y) { return 0 <= x && x < 5 && 0 <= y && y < 5; }

bool isBlank(int r, int c) { return (board & (1<<(5*r+c)))==0; }
void fill(int r, int c, bool b) {
    if (b) board |= (1<<(5*r+c));
    else board &= ~(1<<(5*r+c));
    return;
}

int winnable(int board) {
    int& ret = cache[board];
    if (ret!=-1) return ret;

    for (int r=0; r<5; ++r) {
        for (int c=0; c<5; ++c) {
            if (isInBoard(r, c) && isBlank(r, c) && isInBoard(r+1, c) && isBlank(r+1, c)) {
                fill(r, c, true); fill(r+1, c, true);
                if (!winnable(board)) return ret = 1;
                fill(r, c, false); fill(r+1, c, false);
            }
            if (isInBoard(r, c) && isBlank(r, c) && isInBoard(r, c+1) && isBlank(r, c+1)) {
                fill(r, c, true); fill(r, c+1, true);
                if (!winnable(board)) return ret = 1;
                fill(r, c, false); fill(r, c+1, false);
            }
            if (isInBoard(r, c) && isBlank(r, c) && isInBoard(r, c+1) && isBlank(r, c+1) && isInBoard(r-1, c+1) && isBlank(r-1, c+1)) {
                fill(r, c, true); fill(r, c+1, true); fill(r-1, c+1, true);
                if (!winnable(board)) return ret = 1;
                fill(r, c, false); fill(r, c+1, false); fill(r-1, c+1, false);
            }
            if (isInBoard(r, c) && isBlank(r, c) && isInBoard(r, c+1) && isBlank(r, c+1) && isInBoard(r+1, c+1) && isBlank(r+1, c+1)) {
                fill(r, c, true); fill(r, c+1, true); fill(r+1, c+1, true);
                if (!winnable(board)) return ret = 1;
                fill(r, c, false); fill(r, c+1, false); fill(r+1, c+1, false);
            }
            if (isInBoard(r, c) && isBlank(r, c) && isInBoard(r+1, c) && isBlank(r+1, c) && isInBoard(r+1, c-1) && isBlank(r+1, c-1)) {
                fill(r, c, true); fill(r+1, c, true); fill(r+1, c-1, true);
                if (!winnable(board)) return ret = 1;
                fill(r, c, false); fill(r+1, c, false); fill(r+1, c-1, false);
            }
            if (isInBoard(r, c) && isBlank(r, c) && isInBoard(r+1, c) && isBlank(r+1, c)&& isInBoard(r+1, c+1) && isBlank(r+1, c+1)) {
                fill(r, c, true); fill(r+1, c, true); fill(r+1, c+1, true);
                if (!winnable(board)) return ret = 1;
                fill(r, c, false); fill(r+1, c, false); fill(r+1, c+1, false);
            }
        }
    }
    return ret = 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c; cin >> c; B = 0;
    while(c--) {
        memset(cache, -1, sizeof(cache));
        for (int i=0; i<5; ++i) {
            for (int j=0; j<5; ++j) {
                char c; cin >> c;
                if (c=='#') B |= (1<<5*i+j);
            }
        }
        string res = winnable(B) ? "WINNING" : "LOSING";
        cout << res << endl;
    }
}