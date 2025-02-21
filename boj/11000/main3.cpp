#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

multimap<int,int> S;

int solve() {
    int ret = 0;
    while (!S.empty()) {
        auto here = S.begin();
        while(here != S.end()) {
            auto there = S.lower_bound(here->second);
            S.erase(here);
            here = there;
        }
        ret++;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    while (n--) {
        int s, e; cin >> s >> e;
        S.insert({s, e});
    }
    cout << solve() << endl;
}