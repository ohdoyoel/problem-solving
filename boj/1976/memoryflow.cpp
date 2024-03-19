#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<vector<short>> adjacent;
vector<short> plan;
short cache[202][201][201];

bool possible(short prev, short a, short b) {
    short& ret = cache[prev][a][b];
    if (ret != -1) return ret;
      
    if (a == b) return ret=true;
    for (short i=0; i<adjacent[a].size(); i++) {
        if (i != prev && adjacent[a][i] && possible(a, i, b)) return ret=true;
    }
    return ret=false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    memset(cache, -1, sizeof(cache));
    short n, m; cin >> n >> m; adjacent.resize(n); plan.resize(m);
    for (short i=0; i<n; i++) {
        adjacent[i].resize(n);
        for (short j=0; j<n; j++) cin >> adjacent[i][j];
    }
    for (short i=0; i<m; i++) cin >> plan[i];

    bool ret = true;
    for (short i=1; i<m; i++) {
       if (!possible(201, plan[i-1]-1, plan[i]-1)) {
         ret = false;
         break;
       }
    }
    
    if (ret) cout << "YES" << endl;
    else cout << "NO" << endl;
}