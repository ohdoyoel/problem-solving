#include <bits/stdc++.h>
// #include "bits/stdc++.h"
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

string line;

int countLength(int startIdx, int endIdx) {
    int cnt = 0;
    int openParIdx = -1;
    int closeParIdx = -1;
    for (int i = startIdx; i <= endIdx; ++i) {
        if (line[i] == '(') {
            openParIdx = i;
        } else if (line[i] == ')') {
            closeParIdx = i;
            if (openParIdx != -1 && closeParIdx != -1) {
              cnt += (line[openParIdx - 1] - '0') * countLength(openParIdx + 1, closeParIdx - 1);
            }
            if (closeParIdx != -1) {
              cnt += countLength(closeParIdx + 1, endIdx);
            }
            return cnt;
        } else {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> line;
    cout << countLength(0, sz(line) - 1) << endl;

    return 0;
}
