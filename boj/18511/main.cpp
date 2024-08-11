#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<int> s;

long res;

void solve(int p, long sum) {
    if (sum > n) return;
    if (sum <= n) res = max(res, sum);

    for (int e : s) {
        sum += e*pow(10, p);
        solve(p+1, sum);
        sum -= e*pow(10, p);
    }
}

int main() {
    int k; cin >> n >> k; s.resize(k);
    for (int i=0; i<k; i++) cin >> s[i];

    res = 0;
    solve(0, 0);
    cout << res << endl;
}