#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using pii = pair<int,int>;

vector<vector<pii>> adjacent;
vector<bool> visited;

int height(int i) {
    //cout << i << endl;
    visited[i] = true;
    int ret = 0;
    for (int j=0; j<adjacent[i].size(); j++) {
        //cout << i << " " << j << " " << adjacent[i][j] << endl;
        pii adj = adjacent[i][j];
        if (!visited[adj.first]) ret = max(ret, adj.second+height(adj.first));
    }
    return ret;
}

int maxHeight() {
    int ret = 0;
    for (int i=1; i<adjacent.size(); i++) {
        if (!visited[i]) ret = max(ret, height(i));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n; adjacent.resize(n+1); visited.resize(n+1);
    int t = n;
    while(t--) {
        int i; cin >> i;
        adjacent[i].resize(n+1);
        while(1) {
            int d; cin >> d;
            if (d == -1) break;
            int c; cin >> c;
            adjacent[i].push_back(make_pair(d, c));
        }
    }
    cout << maxHeight() << endl;
}