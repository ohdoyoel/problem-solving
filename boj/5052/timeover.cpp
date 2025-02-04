#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<string> P;

bool solve() {
    sort(P.begin(), P.end());
    for (int i=0; i<P.size(); ++i)
      for (int j=i+1; j<P.size(); ++j)
        if (P[i].size()!=P[j].size() && P[i]==P[j].substr(0, P[i].size())) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c; cin >> c;
    while(c--) {
        cin >> n; P.resize(n);
        for (int i=0; i<n; ++i) cin >> P[i];
        if (solve()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}