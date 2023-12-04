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

bool isAllColorSomething(int x, int y, int length, char color) {
    if (length == 1) return true;
    if (color == 'B') {
        for (int i = x; i < x + length; ++i) {
            for (int j = y; j < y + length; ++j) {
                if (!isBoardBlue[i][j]) return false;
            }
        }
        return true;
    } else if (color == 'W') {
        for (int i = x; i < x + length; ++i) {
            for (int j = y; j < y + length; ++j) {
                if (isBoardBlue[i][j]) return false;
            }
        }
        return true;
    }
}

void seperateBoard(int x, int y, int length) {
    if (isAllColorSomething(x, y, length, 'B')) { cntBlue++; return; }
    else if (isAllColorSomething(x, y, length, 'W')) { cntWhite++; return; }
    
    int halfOfLength = length / 2;
    seperateBoard(x, y, halfOfLength);
    seperateBoard(x + halfOfLength, y, halfOfLength);
    seperateBoard(x, y + halfOfLength, halfOfLength);
    seperateBoard(x + halfOfLength, y + halfOfLength, halfOfLength);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    isBoardBlue.resize(n);
    for (int i = 0; i < n; ++i) {
        isBoardBlue[i].resize(n);
    }
    char c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> c;
            isBoardBlue[i][j] = (c == 1) ? true : false;
        }
    }

    cntBlue = 0;
    cntWhite = 0;
    seperateBoard(0, 0, n);
    cout << cntWhite << endl;
    cout << cntBlue << endl;
    
    return 0;
}
