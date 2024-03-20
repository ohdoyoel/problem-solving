#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<vector<int>> adjacent;
vector<bool> visited;

int height(int i) {
    //cout << i << endl;
    visited[i] = true;
    int ret = 0;
    for (int j=1; j<adjacent[i].size(); j++) {
        //cout << i << " " << j << " " << adjacent[i][j] << endl;
        if (!visited[j] && adjacent[i][j] != 0) ret = max(ret, adjacent[i][j]+height(j));
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
            adjacent[i][d] = c;
        }
    }
    cout << maxHeight() << endl;
}