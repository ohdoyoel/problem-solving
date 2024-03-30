#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef pair<int,int> pvw;

int n;
vector<vector<pvw>> adjacentVW;
vector<int> adjSize;
vector<bool> visited, isTo;

int dfsHeight(int v) {
    visited[v] = true;
    int ret = 0;
    for (pvw adjVW : adjacentVW[v]) {
        if (!visited[adjVW.first]) ret = max(ret, adjVW.second+dfsHeight(adjVW.first));
    }
    visited[v] = false;
    return ret;
}

int dfsRadiusWithCenter(int v) {
    visited[v] = true;
    vector<int> childHeight;
    for (pvw adjVW : adjacentVW[v]) childHeight.push_back(adjVW.second+dfsHeight(adjVW.first));
    visited[v] = false;
    sort(all(childHeight), greater<int>());
    return childHeight[0]+childHeight[1];
}

int dfsRadius(int v) {
    if (adjSize[v] < 2) return dfsHeight(v);
    return dfsRadiusWithCenter(v);
}

int dfsMaxRadius() {
    int ret = 0;
    for (int v=1; v<=n; v++) {
        if (adjSize[v]>=2 || !isTo[v]) ret = max(ret, dfsRadius(v));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio; cin.tie(0); cout.tie(0);
    cin>>n; adjacentVW.resize(n+1); adjSize.resize(n+1); visited.resize(n+1); isTo.resize(n+1);
    int t = n-1;
    while(t--) {
        int s,d,w; cin>>s>>d>>w;
        adjacentVW[s].push_back(make_pair(d,w));
        adjSize[s]++;
        isTo[d] = true;
    }
    cout << dfsMaxRadius() << endl;
}