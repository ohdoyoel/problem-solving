#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n, m;
vector<pair<int, pair<int, int>>> C;
vector<vector<int>> M;

void fillM(int r, int c, int d, int flag) {
    d %= 4;
    // 채우기
    if (flag==1) {
        if (d==0) {
            for (int i=r-1; i>=0; --i) {
                if (M[i][c]==6) return;
                if (M[i][c]==0 || M[i][c]>=7) M[i][c]+=7;
            }
        }
        else if (d==1) {
            for (int i=c+1; i<m; ++i) {
                if (M[r][i]==6) return;
                if (M[r][i]==0 || M[r][i]>=7) M[r][i]+=7;
            }
        }
        else if (d==2) {
            for (int i=r+1; i<n; ++i) {
                if (M[i][c]==6) return;
                if (M[i][c]==0 || M[i][c]>=7) M[i][c]+=7;
            }
        }
        else if (d==3) {
            for (int i=c-1; i>=0; --i) {
                if (M[r][i]==6) return;
                if (M[r][i]==0 || M[r][i]>=7) M[r][i]+=7;
            }
        }
    }
    // 빼기
    else if (flag==0) {
        if (d==0) {
            for (int i=r-1; i>=0; --i) {
                if (M[i][c]==6) return;
                if (M[i][c]>=7) M[i][c]-=7;
            }
        }
        else if (d==1) {
            for (int i=c+1; i<m; ++i) {
                if (M[r][i]==6) return;
                if (M[r][i]>=7) M[r][i]-=7;
            }
        }
        else if (d==2) {
            for (int i=r+1; i<n; ++i) {
                if (M[i][c]==6) return;
                if (M[i][c]>=7) M[i][c]-=7;
            }
        }
        else if (d==3) {
            for (int i=c-1; i>=0; --i) {
                if (M[r][i]==6) return;
                if (M[r][i]>=7) M[r][i]-=7;
            }
        }
    }
}

int zeroCnt() {
    int ret = 0;
    for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) if (M[i][j]==0) ret++;
    return ret;
}

// 각 cctv의 방향을 정한다.
int min0Cnt(int i) {
    if (i==C.size()) {
      // for (auto m : M) {
      //   for (auto a : m) cout << a << ' ';
      //   cout << endl;
      // }
      // cout << endl;
      return zeroCnt();
    }
      
    int ret = 987654321;
    if (C[i].first == 1) {
        for (int d=0; d<4; ++d) {
            fillM(C[i].second.first, C[i].second.second, d, 1);
            ret = min(ret, min0Cnt(i+1));
            fillM(C[i].second.first, C[i].second.second, d, 0);
        }
    } else if (C[i].first == 2) {
        for (int d=0; d<2; ++d) {
            fillM(C[i].second.first, C[i].second.second, d, 1);
            fillM(C[i].second.first, C[i].second.second, d+2, 1);
            ret = min(ret, min0Cnt(i+1));
            fillM(C[i].second.first, C[i].second.second, d, 0);
            fillM(C[i].second.first, C[i].second.second, d+2, 0);
        }
    } else if (C[i].first == 3) {
        for (int d=0; d<4; ++d) {
            fillM(C[i].second.first, C[i].second.second, d, 1);
            fillM(C[i].second.first, C[i].second.second, d+1, 1);
            ret = min(ret, min0Cnt(i+1));
            fillM(C[i].second.first, C[i].second.second, d, 0);
            fillM(C[i].second.first, C[i].second.second, d+1, 0);
        }
    } else if (C[i].first == 4) {
        for (int d=0; d<4; ++d) {
            fillM(C[i].second.first, C[i].second.second, d, 1);
            fillM(C[i].second.first, C[i].second.second, d+1, 1);
            fillM(C[i].second.first, C[i].second.second, d+2, 1);
            ret = min(ret, min0Cnt(i+1));
            fillM(C[i].second.first, C[i].second.second, d, 0);
            fillM(C[i].second.first, C[i].second.second, d+1, 0);
            fillM(C[i].second.first, C[i].second.second, d+2, 0);
        }
    } else if (C[i].first == 5) {
        for (int d=0; d<4; ++d) fillM(C[i].second.first, C[i].second.second, d, 1);
        ret = min(ret, min0Cnt(i+1));
        for (int d=0; d<4; ++d) fillM(C[i].second.first, C[i].second.second, d, 0);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m; M.resize(n);
    for (int i=0; i<n; ++i) {
        M[i].resize(m);
        for (int j=0; j<m; ++j) {
            int x; cin >> x;
            M[i][j]=x;
            if (x!=0 && x!=6) C.push_back(make_pair(x, make_pair(i, j)));
        }
    }
    cout << min0Cnt(0) << endl;
}