#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<string> P;
set<string> PF;

bool solve() {
    sort(P.begin(), P.end());
    for (int i=0; i<n; ++i) {
        for (int j=1; j<P[i].size(); ++j) {
            string prefix = P[i].substr(0, j);
            if (PF.find(prefix)!=PF.end()) return false;
        }
        PF.insert(P[i]);
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) {
        cin >> n; P.resize(n);
        for (int i=0; i<n; ++i) cin >> P[i];
        PF.clear();
        if (solve()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}