#include<bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;

vector<vector<int>> weight;
vector<int> numOfAdj;
vector<bool> visited, isTo;
int n;

int dfsHeight(int v) {
    visited[v] = true;
    int ret = 0;
    for (int next=1; next<=n; next++) {
        if (weight[v][next]!=0 && !visited[next]) ret = max(ret, weight[v][next]+dfsHeight(next));
    }
    visited[v] = false;
    return ret;
}

int dfsRadiusWithCenter(int v) {
    visited[v] = true;
    vector<int> childHeight;
    for (int next=1; next<=n; next++) {
        if (weight[v][next]!=0 && !visited[next]) childHeight.push_back(weight[v][next]+dfsHeight(next));
    }
    visited[v] = false;
    sort(all(childHeight), greater<int>());
    return childHeight[0]+childHeight[1];
}

int dfsRadius(int v) {
    if (numOfAdj[v] < 2) return dfsHeight(v);
    return dfsRadiusWithCenter(v);
}

int dfsMaxRadius() {
    int ret = 0;
    for (int v=1; v<=n; v++) {
        if (numOfAdj[v]>=2 || !isTo[v]) ret = max(ret, dfsRadius(v));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n; weight.resize(n+1); numOfAdj.resize(n+1); visited.resize(n+1); isTo.resize(n+1);
    for (int i=1; i<=n; i++) weight[i].resize(n+1);
    for (int i=0; i<n; i++) {
        int v; cin >> v;
        while(1) {
            int dst; cin >> dst;
            if (dst==-1) break;
            int w; cin >> w;
            weight[v][dst] = w;
            numOfAdj[v]++;
            isTo[dst] = true;
        }
    }

    cout << dfsMaxRadius() << endl;
}