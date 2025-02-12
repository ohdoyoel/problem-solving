#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

struct INFO {
    int rr, rc, br, bc, count;
};

int n, m;
INFO start;
vector<vector<int>> B;

int solve() {
    const int dr[] = {-1, 1, 0, 0};
    const int dc[] = {0, 0, -1, 1};

    bool visited[10][10][10][10] = {0,};
    queue<INFO> Q;
    Q.push(start);
    visited[start.rr][start.rc][start.br][start.rc] = 1;

    int ret = -1;
    while(!Q.empty()) {
        INFO cur = Q.front(); Q.pop();
        if (cur.count > 10) return -1;
        if (B[cur.rr][cur.rc]=='O' && B[cur.br][cur.bc]!='O') {
            ret = cur.count;
            break;
        }
        
        for (int dir=0; dir<4; ++dir) {
            int next_rr = cur.rr;
            int next_rc = cur.rc;
            int next_br = cur.br;
            int next_bc = cur.bc;

            while(1) {
                if (B[next_rr][next_rc]!='#' && B[next_rr][next_rc]!='O') {
                    next_rr += dr[dir], next_rc += dc[dir];
                } else {
                    if (B[next_rr][next_rc]=='#') {
                        next_rr -= dr[dir], next_rc -= dc[dir];
                    }
                    break;
                }
            }

            while(1) {
                if (B[next_br][next_bc]!='#' && B[next_br][next_bc]!='O') {
                    next_br += dr[dir], next_bc += dc[dir];
                } else {
                    if (B[next_br][next_bc]=='#') {
                        next_br -= dr[dir], next_bc -= dc[dir];
                    }
                    break;
                }
            }

            if (next_rr==next_br && next_rc==next_bc) {
                if (B[next_rr][next_rc] != 'O') {
                    int rd = abs(next_rr - cur.rr) + abs(next_rc - cur.rc);
                    int bd = abs(next_br - cur.br) + abs(next_bc - cur.bc);
                    if (rd > bd) {
                        next_rr -= dr[dir], next_rc -= dc[dir];
                    } else {
                        next_br -= dr[dir], next_bc -= dc[dir];
                    }
                }
            }

            if (!visited[next_rr][next_rc][next_br][next_bc]) {
                visited[next_rr][next_rc][next_br][next_bc] = true;
                INFO next;
                next.rr = next_rr;
                next.rc = next_rc;
                next.br = next_br;
                next.bc = next_bc;
                next.count = cur.count+1;
                Q.push(next);
            }
        }
    }

    return ret;
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m; 
    for (int i=0; i<n; ++i) {
        B[i].resize(m);
        for (int j=0; j<m; ++j) {
            char x; cin >> x;
            B[i][j] = x;
            if (x=='R') start.rr = i, start.rc = j;
            else if (x=='B') start.br = i, start.bc = j;
        }
    }

    start.count = 0;
    cout << solve() << endl;
}