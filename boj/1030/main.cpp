#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int s, n, k, r1, r2, c1, c2;

bool isInBlackRange(int x, int y, int len, int centerLen) {
    int cx = (len - centerLen) / 2;
    int cy = (len - centerLen) / 2;
    // cout << x << " " << y << " " <<  cx << " " << cy << " " << len << " " << centerLen << endl;
    if (cx <= x && x < cx + centerLen && cy <= y && y < cy + centerLen) return true;
    return false;
}

int board(int x, int y, int len, int centerLen) {
    // cout << len << " " <<  n << " "  << len / n << " " << centerLen << endl;
    if (isInBlackRange(x, y, len, centerLen)) return 1;
    else if (len == 1) return 0;
    // cout << len << " " <<  n << " "  << len / n << endl;
    return board(x % (len / n), y % (len / n), len / n, centerLen / n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;
    
    for (int i = r1; i <= r2; ++i) {
        for (int j = c1; j <= c2; ++j) {
            cout << board(i, j, pow(n,s), k * pow(n, s) / n);
        }
        cout << endl;
    }

    return 0;
}
