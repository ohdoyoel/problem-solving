#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<pair<int,int>> S;

int solve() {
    int ret = 0;
    int lastEnd = 0;
    for (auto [e, s] : S) {
        if (s >= lastEnd) {
            ret++;
            lastEnd = e;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    while (n--) {
        int s, e; cin >> s >> e;
        S.push_back({e, s});
    }
    
    auto cmp = [](const auto& a, const auto& b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    };
    sort(S.begin(), S.end(), cmp);
    
    cout << solve() << endl;
}