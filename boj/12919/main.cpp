#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

string src;
int cnt;

string reverseString(string str) {
    reverse(str.begin(), str.end());
    return str;
}

void solve(string tgt, int len) {
    if (len == sz(src)) {
        if (tgt == src) {cnt++; return;}
        else return;
    }

    if (tgt.substr(len - 1) == "A") solve(tgt.substr(0, len - 1), len - 1);
    if (tgt[0] == 'B') solve(reverseString(tgt.substr(1, len - 1)), len - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string tgt;

    cin >> src;
    cin >> tgt;

    cnt = 0;
    solve(tgt, sz(tgt));

    if (cnt == 0) cout << 0 << endl;
    else cout << 1 << endl;

    return 0;
}