#include<bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;

int n;
vector<int> to, lg;
vector<bool> visited;

void dfsTeam(int v) {
    // cout << v << endl;
    auto vIt = find(all(lg), v);
    if (vIt != lg.end()) {
        for (auto it=lg.begin(); it!=vIt; it++) {
            // cout << v << " " << *it << endl;
            visited[*it] = false;
        }
        return;
    }
    
    visited[v] = true;
    lg.push_back(v);
    dfsTeam(to[v]);
}

int dfsNotTeam() {
    for (int v=1; v<=n; v++) {
        lg.clear();
        if (!visited[v]) dfsTeam(v);
    }
    
    int ret = 0;
    for (int i=1; i<=n; i++) {
        if (!visited[i]) ret++;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--) {
        cin>>n; to.resize(n+1); visited.resize(n+1);
        for (int i=1; i<=n; i++) {
            cin>>to[i]; visited[i]=false;
        }
        cout << dfsNotTeam() << endl;
    }
}