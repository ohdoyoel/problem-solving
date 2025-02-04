#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
set<int> W;

bool makeable(i) {
    if (i==0) return true;
    auto it = W.lower_bound(i+1);
    it--;
    return makeable(i-*it);
}

int solve() {
    int ret = 0;
    while (true) {
        if (!makeable(ret)) return ret;
        ret++;
    }
    return 987654321;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n; W.resize(n);
    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        W.insert(x);
    }
    cout << solve() << endl;

    return 0;
}