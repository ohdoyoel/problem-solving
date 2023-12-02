#include <bits/stdc++.h>
// #include "bits/stdc++.h"
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int cntBlue;
int cntWhite;
vector<vector<bool>> isBoardBlue;

int isAllColor

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    board.resize(n);
    for (int i = 0; i < n; ++i) {
        board[j].resize(n);
    }
    char c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> c;
            isBoardOne[i][j] = (c == 1) ? true : false;
        }
    }

    cntBlue = 0;
    cntWhite = 0;
    solve();
    cout << cnt << endl;

    return 0;
}
