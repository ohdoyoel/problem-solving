#include<bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef pair<int,int> pvw;

vector<vector<pvw>> adjacentVW;
vector<bool> visited, isTo;
int n;

int dfsHeight(int v) {
    visited[v] = true;
    int ret = 0;
    for (pvw vw : adjacentVW[v]) {
        if (!visited[vw.first]) ret = max(ret, vw.second+dfsHeight(vw.first));
    }
    visited[v] = false;
    return ret;
}

int dfsRadiusWithCenter(int v) {
    visited[v] = true;
    vector<int> childHeight;
    for (pvw vw: adjacentVW[v]) {
        if (!visited[vw.first]) childHeight.push_back(vw.second+dfsHeight(vw.first));
    }
    visited[v] = false;
    sort(all(childHeight), greater<int>());
    return childHeight[0]+childHeight[1];
}

int dfsRadius(int v) {
    if (adjacentVW[v].size() < 2) return dfsHeight(v);
    return dfsRadiusWithCenter(v);
}

int dfsMaxRadius() {
    int ret = 0;
    for (int v=1; v<=n; v++) {
        if (adjacentVW[v].size()>=2 || !isTo[v]) ret = max(ret, dfsRadius(v));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n; adjacentVW.resize(n+1); visited.resize(n+1); isTo.resize(n+1);
    for (int i=0; i<n; i++) {
        int v; cin >> v;
        while(1) {
            int dst; cin >> dst;
            if (dst==-1) break;
            int w; cin >> w;
            adjacentVW[v].push_back(make_pair(dst, w));
            isTo[dst] = true;
        }
    }

    cout << dfsMaxRadius() << endl;
}