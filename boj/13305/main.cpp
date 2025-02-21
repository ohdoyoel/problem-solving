#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<int> P, D;
set<pair<int,int>> minPI;

long long solve(int i, int j) {
    if (i==j) return 0;

    int minP=0, minPIdx=0;
    for (auto [p, idx] : minPI) { if (i<=idx && idx<j) { minP=p; minPIdx=idx; break; } }

    long long ret = solve(i, minPIdx);
    for (int i=minPIdx; i<j; ++i) ret += (long long)minP*D[i];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; n--; P.resize(n); D.resize(n);
    for (int i=0; i<n; ++i) cin >> D[i];
    for (int i=0; i<n; ++i) {
        cin >> P[i];
        minPI.insert({P[i], i});
    }
    cout << solve(0, n+1) << endl;
}