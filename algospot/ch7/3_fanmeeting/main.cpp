#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

void addTo(vector<int> &a, vector<int> &b, int k) {
    int an = sz(a), bn = sz(b);
    if (bn == 0) return an;

    for (int i = k; i < bn; ++i) a[i] += b[i - k];
}

vector<int> karatsuba(vector<int> &a, vector<int> &b) {
    int an = sz(a), bn = sz(b);
    if (an < bn) return karatsuba(b, a);
    if (an == 0 || bn == 0) return vector<int> ();
    
    int midIdx = an / 2;
    vector<int> a0(a.begin(), a.begin() + midIdx);
    vector<int> a1(a.begin() + midIdx, a.end());
    vector<int> b0(b.begin(), b.begin() + min(sz(b), midIdx));
    vector<int> b1(b.begin() + min(sz(b), midIdx), b.end());

    vector<int> z2 = zaratsuba(a1, b1);
    vector<int> z0 = zaratsuba(a0, b0);

    addTo(a0, a1, 0);
    addTo(b0, b1, 0);
    
}

int hugCnt (string members, string fans) {
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c;
    cin >> c;
    while (c--) {
        string members, fans;
        cin >> members, fans;
        cout << sz(fans) - sz(members) + 1 - hugCnt(members, fans) << endl;
    }

    return 0;
}