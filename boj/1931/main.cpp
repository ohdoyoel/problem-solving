#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<pair<int, int>> M;
vector<int> A;

void solve() {
    sort(M.begin(), M.end(), [](const auto &a, const auto &b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });

    int idx = 0;
    A = { 0 };
    for (int i=1; i<n; ++i) {
        if (M[idx].second <= M[i].first) {
            idx = i;
            A.push_back(idx);
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; M.resize(n);
    for (int i=0; i<n; ++i) {
        int a, b; cin >> a >> b;
        M[i] = {a, b};
    }
    solve();
    cout << A.size() << endl;
}