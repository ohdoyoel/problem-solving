#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

string w;
string f;
int cache[101][101];

int patternMatched(int wIdx, int fIdx) {
    int& ret = cache[wIdx][fIdx];
    if (ret != -1)  return ret;

    while ((wIdx < sz(w) && fIdx < sz(f)) && (w[wIdx] == '?' || w[wIdx] == f[fIdx])) {
        wIdx++;
        fIdx++;
    }
    
    if (wIdx == sz(w)) return ret = (fIdx == sz(f));

    if (w[wIdx] == '*') {
        for (int skip = 0; skip + fIdx <= sz(f); ++skip) {
            if (patternMatched(wIdx + 1, fIdx + skip)) {
                return ret = 1;
            }
        }
    }
    
    return ret = 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int c;
    cin >> c;
    while (c--) {
        cin >> w;
        vector<string> result;
        int n;
        cin >> n;
        while (n--) {
            for (int i = 0; i < 101; ++i)
                for (int j = 0; j < 101; ++j)
                    cache[i][j] = -1;
            cin >> f;
            if (patternMatched(0, 0) == 1) result.push_back(f);
        }
        sort(result.begin(), result.end());
        for (auto e:result) {
            cout << e << endl;
        }
    }

    return 0;
}