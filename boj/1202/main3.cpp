#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

multimap<int, int, greater<int>> J;
multiset<int> B;

long long solve() {
    long long ret = 0;
    for (auto& vm : J) {
        auto it = it = B.lower_bound(vm.second);
        if (it == B.end()) continue;
        B.erase(it);
        ret += vm.first;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    while(n--) {
        int m, v; cin >> m >> v;
        J.insert({v, m});
    }
    while(k--) {
        int c; cin >> c;
        B.insert(c);
    }
    cout << solve() << endl;
}