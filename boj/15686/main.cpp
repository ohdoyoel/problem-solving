#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n, m;
vector<vector<int>> M;
vector<pair<int, int>> H;
vector<pair<int, int>> C;

int chicken() {
    int ret = 0;
    for (auto h : H) {
        int d = 987654321;
        for (auto c : C) d = min(d, abs(h.first-c.first) + abs(h.second-c.second));
        ret += d;
    }
    return ret;
}

// 없애야하는 치킨집의 수만큼 없앤 후 도시의 치킨 거리
int solve(int e) {
    if (e==0) return chicken();

    int ret = 987654321;
    for (auto it=C.begin(); it!=C.end(); ++it) {
        C.erase(it);
        ret = min(ret, solve(e-1));
        C.insert(it);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m; M.resize(n);
    for (int i=0; i<n; ++i) {
        M[i].resize(n);
        for (int j=0; j<n; ++j) {
            int x; cin >> x;
            M[i][j] = x;
            if (x==2) C.push_back(make_pair(i, j));
            else if (x==1) H.push_back(make_pair(i, j));
        }
    }

    cout << solve(C.size()-m) << endl;
}