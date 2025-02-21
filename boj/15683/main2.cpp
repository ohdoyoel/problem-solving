#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n, m;
vector<vector<int>> B;
vector<pair<int,pair<int,int>>> CCTV; // CCTV[i] = {k, (r, c)}

int count() {
    int ret = 0;
    for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) if (B[i][j]==0) ret++;
    return ret;
}

void setLine(int r, int c, int dir, int on) {
    if (dir==0) for (int i=r; i<n; ++i) {
        if (B[i][c]<0) break;
        else B[i][c] += on;
    }
    else if (dir==1) for (int i=c; i<m; ++i) {
        if (B[r][i]<0) break;
        else B[r][i] += on;
    }
    else if (dir==2) for (int i=r; i>=0; --i) {
        if (B[i][c]<0) break;
        else B[i][c] += on;
    } 
    else if (dir==3) for (int i=c; i>=0; --i) {
        if (B[r][i]<0) break;
        else B[r][i] += on;
    }
}

int solve(int i) {
    if (i==CCTV.size()) return count();

    int ret = 987654321;
    auto [k, cord] = CCTV[i];
    auto [r, c] = cord;
    if (k==1) {
        for (int dir=0; dir<4; ++dir) {
            setLine(r, c, dir, 1);
            ret = min(ret, solve(i+1));
            setLine(r, c, dir, -1);
        }
    }
    else if (k==2) {
        for (int dir=0; dir<2; ++dir) {
            setLine(r, c, dir, 1);
            setLine(r, c, dir+2, 1);
            ret = min(ret, solve(i+1));
            setLine(r, c, dir, -1);
            setLine(r, c, dir+2, -1);
        }
    }
    else if (k==3) {
        for (int dir=0; dir<4; ++dir) {
            setLine(r, c, dir, 1);
            setLine(r, c, (dir+1)%4, 1);
            ret = min(ret, solve(i+1));
            setLine(r, c, dir, -1);
            setLine(r, c, (dir+1)%4, -1);
        }
    }
    else if (k==4) {
        for (int dir=0; dir<4; ++dir) {
            setLine(r, c, dir, 1);
            setLine(r, c, (dir+1)%4, 1);
            setLine(r, c, (dir+2)%4, 1);
            ret = min(ret, solve(i+1));
            setLine(r, c, dir, -1);
            setLine(r, c, (dir+1)%4, -1);
            setLine(r, c, (dir+2)%4, -1);
        }
    }
    else if (k==5) {
        setLine(r, c, 0, 1);
        setLine(r, c, 1, 1);
        setLine(r, c, 2, 1);
        setLine(r, c, 3, 1);
        ret = min(ret, solve(i+1));
        setLine(r, c, 0, -1);
        setLine(r, c, 1, -1);
        setLine(r, c, 2, -1);
        setLine(r, c, 3, -1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> n >> m;
    B.assign(n, vector<int>(m));
    for (int i=0; i<n; ++i) {
      for (int j=0; j<m; ++j) {
        int x; cin >> x;
        if (x!=0 && x!=6) CCTV.push_back({x, {i, j}});
        else if (x==6) B[i][j] = -1;
        else B[i][j] = x;
      }
    }
    cout << solve(0) << endl;
    return 0;
}