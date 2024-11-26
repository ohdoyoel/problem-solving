#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> moves;
inline int cell(int r, int c) { return 1<<(5*r+c); }
void precalc() {
    for (int r=0; r<4; ++r) {
        for (int c=0; c<4; ++c) {
            vector<int> cells;
            for (int dr=0; dr<2; ++dr) for (int dc=0; dc<2; ++dc) cells.push_back(cell(r+dr, c+dc));
            int square = cells[0]+cells[1]+cells[2]+cells[3];
            for (int i=0; i<4; ++i) moves.push_back(square-cells[i]);
        }
    }
    for (int r=0; r<5; ++r) {
        for (int c=0; c<4; ++c) {
            moves.push_back(cell(r, c) + cell(r, c+1));
            moves.push_back(cell(c, r) + cell(c+1, r));
        }
    }
}

char cache[1<<25];

char play(int board) {
    char& ret = cache[board];
    if (ret!=-1) return ret;

    ret = 0;
    for (int i=0; i<moves.size(); ++i) {
        if (((moves[i] & board) == 0) && !play(board | moves[i])) {
            ret = 1;
            break;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    precalc();
    int c; cin >> c;
    while(c--) {
        memset(cache, -1, sizeof(cache));
        int b = 0;
        for (int i=0; i<5; ++i) {
            for (int j=0; j<5; ++j) {
                char ch; cin >> ch;
                if (ch == '#') b |= cell(i, j);
            }
        }
        string res = play(b) ? "WINNING" : "LOSING";
        cout << res << endl;
    }
}