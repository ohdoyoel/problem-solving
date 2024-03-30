#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
// weight[n][m] n~m까지 가는데 걸리는 거리
vector<vector<int>> weight;
vector<bool> visited;

// v에서 출발해서 갈 수 있는 최대 거리
int dfsDis(int v) {
    visited[v] = true;
    int ret = 0;
    for (int next=1; next<=n; next++) {
        if (weight[v][next]!=0 && !visited[next]) ret = max(ret, weight[v][next]+dfsDis(next));
    }
    visited[v] = false;
    return ret;
}

int dfsMaxDis() {
    int ret = 0;
    for (int v=1; v<=n; v++) ret = max(ret, dfsDis(v));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n; weight.resize(n+1); visited.resize(n+1);
    for (int i=1; i<=n; i++) weight[i].resize(n+1);
    for (int i=1; i<=n; i++) {
        int v; cin >> v;
        while(1) {
            int d; cin >> d;
            if (d==-1) break;
            else {
                int w; cin >> w;
                weight[v][d] = w;
            }
        }
    }

    cout << dfsMaxDis() << endl;
}