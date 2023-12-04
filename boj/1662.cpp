#include <bits/stdc++.h>
// #include "bits/stdc++.h"
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int closeParentIdx = -1;

int countLength(string line, int startIdx) {
    int cnt = 0;
    for (int i = startIdx; i < sz(line); ++i) {
        // cout << line[i] << " " << cnt << endl;
        if (line[i] == '(') {
            cnt--;
            cnt += (line[i - 1] - '0') * countLength(line, i + 1);
            if (closeParentIdx != -1) cnt += countLength(line, closeParentIdx + 1);
            return cnt;
        } else if (line[i] == ')') {
            closeParentIdx = i;
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

    string l;
    cin >> l;
    cout << countLength(l, 0) << endl;

    return 0;
}
