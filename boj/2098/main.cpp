#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[17][1<<16][17];
int n;
vector<vector<int>> W;
uint visited;

int path(int here, uint visited, int start) {
    if (visited==(1<<n)-1) return W[here][start]==0 ? 987654321 : W[here][start];
    
    int& ret = cache[here+1][visited][start+1];
    if (ret!=-1) return ret;

    ret = 987654321;
    for (int next=0; next<n; ++next) {
        if (visited & (1<<next)) continue;

        visited |= (1<<next);
        
        if (here==-1) ret = min(ret, path(next, visited, next));
        else if (W[here][next]!=0) ret = min(ret, W[here][next] + path(next, visited, start));
        
        visited &= ~(1<<next);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n; W.resize(n);
    for (int i=0; i<n; ++i) {
        W[i].resize(n);
        for (int j=0; j<n; ++j) cin >> W[i][j];
    }
    cout << path(-1, 0, -1) << endl;;
}