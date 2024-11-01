#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<vector<int>> W;
vector<int> P;
vector<bool> V;

long long path(int here) {
    if (P.size()==n) return W[here][P.front()]==0 ? 987654321987654321 : W[here][P.front()];

    long long ret = 987654321987654321;
    for (int next=0; next<n; ++next) {
        if (V[next]) continue;

        P.push_back(next);
        V[next] = true;
        
        if (here==-1) ret = min(ret, path(next));
        else if (W[here][next]!=0) ret = min(ret, W[here][next]+path(next));
        
        P.pop_back();
        V[next] = false;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; W.resize(n); V.resize(n);
    for (int i=0; i<n; ++i) {
        W[i].resize(n);
        for (int j=0; j<n; ++j) cin >> W[i][j];
    }
    cout << path(-1) << endl;;
}