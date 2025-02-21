#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n, k;
multimap<int, int, greater<int>> J;
multiset<int> C;

long long solve() {
    long long ret = 0;
    for (auto [v, m] : J) {
        auto it = C.lower_bound(m);
        if (it==C.end()) continue;
        ret += v;
        C.erase(it);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i=0; i<n; ++i) {
        int m, v; cin >> m >> v; J.insert({v, m});
    }
    for (int i=0; i<k; ++i) {
        int c; cin >> c; C.insert(c);
    }

    cout << solve() << endl;
}