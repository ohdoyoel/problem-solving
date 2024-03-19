#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<vector<int>> adjacent;
bool visited[100001];
vector<int> parent;

void solve(int i) {
    if (visited[i]) return;
    visited[i] = true;
    for (int adj : adjacent[i]) {
        if (parent[adj] == 0) parent[adj] = i;
        solve(adj);
    }
}

int main() {
    memset(visited, 0, sizeof(visited));
    int n; cin >> n; adjacent.resize(n+1); parent.resize(n+1);
    while(n--) {
        int a, b; cin >> a >> b;
        adjacent[a].push_back(b);
        adjacent[b].push_back(a);
    }

    solve(1);

    for (int p=2; p<=parent.size()-1; p++) cout << parent[p] << endl;
}