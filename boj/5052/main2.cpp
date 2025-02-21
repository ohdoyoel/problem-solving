#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n; 
vector<string> A;
set<string> PF;

bool solve() {
    for (int i=0; i<n; ++i) {
        for (int j=1; j<A[i].size(); ++j) {
            string prefix = A[i].substr(0, j);
            if (PF.count(prefix)>0) return false;
        }
        PF.insert(A[i]);
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> n; A.resize(n);
        for (int i=0; i<n; ++i) cin >> A[i];
        sort(A.begin(), A.end());
        PF.clear();
        if (solve()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}