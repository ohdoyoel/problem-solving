#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n, m;
vector<pair<int, int>> H;
vector<pair<int, int>> C;
vector<pair<int, int>> CC;

int chickenDistance() {
    int ret = 0;
    for (auto h : H) {
        int dis = 987654321;
        for (auto c : CC) dis = min(dis, abs(h.first-c.first)+abs(h.second-c.second));
        ret += dis;
    }
    return ret;
}

int solve(int i) {
    if (CC.size() == m) return chickenDistance();
    if (i==C.size()) return 987654321;

    int ret = 987654321;
    ret = min(ret, solve(i+1));
    CC.push_back(C[i]);
    ret = min(ret, solve(i+1));
    CC.pop_back();
    return ret;
}

int main() {
    cin >> n >> m;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            int x; cin >> x;
            if (x==1) H.push_back({i, j});
            else if (x==2) C.push_back({i, j});
        }
    }

    cout << solve(0) << endl;
}