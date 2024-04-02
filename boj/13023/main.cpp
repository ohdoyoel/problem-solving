#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<vector<int>> adjacent;
vector<int> visited;

bool isFriend(int a, int b) {
    if (a==b) return true;
    visited[a] = true;
    for (int adj : adjacent[a]) {
        if (!visited[adj] && isFriend(adj, b)) return true;
    }
    return false;
}

int main() {
    int n,m; cin>>n>>m; adjacent.resize(n); visited.resize(n);
    // for (int i=0; i<n; i++) adjacent[i].resize(n);
    while(m--) {
        int a,b; cin>>a>>b;
        adjacent[a].push_back(b);
        // adjacent[b].push_back(a);
    }
    
    for (int i=0; i<n; i++) visited[i] = false;
    bool ret = isFriend(0,1);
    for (int i=0; i<n; i++) visited[i] = false;
    ret = ret && isFriend(1,2);
    for (int i=0; i<n; i++) visited[i] = false;
    ret = ret && isFriend(2,3);
    for (int i=0; i<n; i++) visited[i] = false;
    ret = ret && isFriend(3,4);

    cout << ret << endl;
}