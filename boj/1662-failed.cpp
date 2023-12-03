#include <bits/stdc++.h>
// #include "bits/stdc++.h"
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int countLength(string line) {
    int cnt = 0;
    for (int i = 0; i < sz(line); ++i) {
        if (line[i] == '(') {
            cnt--;
            return cnt + (line[i - 1] - '0') * countLength(line.substr(i + 1));
        } else if (line[i] == ')') {
            return cnt;
        } else {
            cnt++;
        }
    }
    cnt += countLength(line.substr(line.find_last_of(')') + 1));
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string l;
    cin >> l;
    cout << countLength(l) << endl;

    return 0;
}
