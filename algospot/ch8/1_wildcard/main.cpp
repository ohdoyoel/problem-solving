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

string pieceToFind(string w) {
    int starIdx = sz(w);
    for (int i = 0; i < sz(w); ++i) {
        if (w[i] == '*') {
            starIdx = i;
            break;
        }
    }
    return w.substr(0, starIdx);
}

bool patternMatched(string wildcard, string filename) {
    int pos = 0;
    while ((pos < sz(wildcard) && pos < sz(filename)) && (wildcard[pos] == '?' || wildcard[pos] == filename[pos])) {
        pos++;
    }
    
    if (pos == sz(wildcard)) return (pos == sz(filename));
    if (pos == sz(filename)) return isOnlyHaveStar(wildcard.substr(pos));

    if (wildcard[pos] == '*') {
        for (int skip = 0; skip < sz(filename) - pos; ++skip) {
            if (patternMatched(wildcard.substr(pos + 1), filename.substr(pos + 1 + skip))) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int c;
    cin >> c;
    while (c--) {
        string w;
        cin >> w;
        vector<string> result;
        int n;
        cin >> n;
        while (n--) {
            string f;
            cin >> f;
            if (patternMatched(w, f)) result.push_back(f);
        }
        sort(result.begin(), result.end());
        for (auto e:result) {
            cout << e << endl;
        }
    }

    return 0;
}