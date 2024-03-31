#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<int> to, log;
vector<bool> visited;

void dfsTeam(int v) {
    visited[v] = true;
    log.push_back(v);
    // ... return;
    visited[v] = false;
    log.pop_back();
}

int dfsNotTeam() {
    for (int v=1; v<=n; v++) {
        if (!visited[v]) dfsTeam(v);
    }
    
    int ret = 0;
    for (int i=1; i<=n; i++) {
        if (!visited[i]) ret++;
    }
    return ret;
}

int main() {
    int t; cin>>t;
    while(t--) {
        cin>>n; to.resize(n+1); visited.resize(n+1);
        for (int i=1; i<=n; i++) cin>>to[i];
        cout << dfsNotTeam() << endl;
    }
}