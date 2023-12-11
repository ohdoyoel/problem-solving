#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int cnt;
vector<string> dict;

bool pickedContainsAllAlphabet(vector<string> picked) {
    bool isAlphabetContained[26] =
    {
      false, false, false, false,
      false, false, false, false,
      false, false, false, false, 
      false, false, false, false, 
      false, false, false, false, 
      false, false, false, false, 
      false, false
    };
    
    for (string word : picked) {
        for (int i = 0; i < sz(word); ++i) {
            isAlphabetContained[word[i] - 'a'] = true;
        }
    }
    
    for (int i = 0; i < 26; ++i) {
        if (isAlphabetContained[i] == false) return false;
    }
    return true;
}

void solve(vector<string> picked, int startIdx) {
    if (pickedContainsAllAlphabet(picked)) {cnt++; return;}
    if (startIdx == sz(dict)) return;
    for (int i = startIdx; i < sz(dict); ++i) {
        picked.push_back(dict[i]);
        solve(picked, i + 1);
        picked.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    dict.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> dict[i];
    }

    cnt = 0;
    vector<string> picked;
    solve(picked, 0);
    cout << cnt << endl;

    return 0;
}