#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

bool isOnlyHaveStar(string s) {
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] != '*') return false;
    }
    return true;
}

bool patternMatched(string wildcard, string filename) {
    int pos = 0;
    while ((pos < sz(wildcard) && pos < sz(filename)) && (wildcard[pos] == '?' || wildcard[pos] == filename[pos])) {
        pos++;
        if (pos == sz(wildcard)) {
            return pos == sz(filename);
        }
        if (pos == sz(filename)) {
            return isOnlyHaveStar(wildcard.substr(pos));
        }
        if (wildcard[pos] == '*') {
            string piece = wildcard[pos + 1 : '*'가 나오기 전];
            int skip = filename.find(piece, pos);
            if (skip == -1) {
                return false;
            } else {
                return patternMatched(wildcard.substr(pos + 1), filename.substr(pos + skip));
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c;
    cin >> c;
    while (c--) {
        string w;
        cin >> w;
        int n;
        cin >> n;
        while (n--) {
            string f;
            cin >> f;
            if (patternMatched(w, f)) cout << f << endl;
        }
    }

    return 0;
}