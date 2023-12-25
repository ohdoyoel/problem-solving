#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

void printVector(vector<int> v) {
    for (int i = 0; i < sz(v); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void cTimes(vector<int> &a, vector<int> &b, int c) {
    int an = sz(a), bn = sz(b);
    if (bn == 0 || c == 0) return;
    
    for (int i = 0; i < sz(a); ++i) {
        a[i] += c * b[i];
    }
}

vector<int> multiply(vector<int> &a, vector<int> &b) {
    int an = sz(a), bn = sz(b);
    vector<int> c(an + bn, 0);
    for (int i = 0; i < an; ++i) {
        for (int j = 0; j < bn; ++j) {
            c[i + j] += a[i] * b[j];
        }
    }
    return c;
}

void addTo(vector<int> &a, vector<int> &b, int k) {
    int an = sz(a), bn = sz(b);
    if (bn == 0) return;
    
    if (an < bn + k) a.resize(bn + k, 0);

    for (int i = k; i < bn + k; ++i) a[i] += b[i - k];
}

void subFrom(vector<int> &a, vector<int> &b) {
    int an = sz(a), bn = sz(b);
    if (bn == 0) return;

    for (int i = 0; i < bn; ++i) a[i] -= b[i];
}


vector<int> karatsuba(vector<int> &a, vector<int> &b) {
    // cout << "{" << endl;
    int an = sz(a), bn = sz(b);
    // cout << "an " << an << " " << "bn " << bn << endl;
    if (an < bn) return karatsuba(b, a);
    if (an == 0 || bn == 0) return vector<int>();
    else if (an == 1) { vector<int> ret(bn, 0); cTimes(ret, b, a[0]); return ret; }
    else if (bn == 1) { vector<int> ret(an, 0); cTimes(ret, a, b[0]); return ret; }
    else if (an <= 50) return multiply(a, b);
    
    int midIdx = an / 2;
    vector<int> a0(a.begin(), a.begin() + midIdx);
    vector<int> a1(a.begin() + midIdx, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(sz(b), midIdx));
    vector<int> b1(b.begin() + min<int>(sz(b), midIdx), b.end());

    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);

    addTo(a0, a1, 0);
    addTo(b0, b1, 0);
    
    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);

    vector<int> ret;
    addTo(ret, z0, 0);
    addTo(ret, z1, midIdx);
    addTo(ret, z2, 2 * midIdx);
    
    // printVector(ret);
    // cout << '}' << endl;

    return ret;
}

int hugCnt (string members, string fans) {
    int mn = sz(members), fn = sz(fans);
    vector<int> membersVector(mn), fansVector(fn);
    for (int i = 0; i < mn; ++i) {
        if (members[i] == 'M') membersVector[mn - 1 - i] = 1;
        else membersVector[mn - 1 - i] = 0;
    }
    for (int i = 0; i < fn; ++i) {
        if (fans[i] == 'M') fansVector[i] = 1;
        else fansVector[i] = 0;
    }
    
    // printVector(membersVector);
    // printVector(fansVector);

    vector<int> karatsubaMembersAndFans = karatsuba(membersVector, fansVector);
    
    // printVector(karatsubaMembersAndFans);
    
    int ret = 0;
    for (int i = mn - 1; i < fn; ++i) {
        if (karatsubaMembersAndFans[i] == 0) ret++;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c;
    cin >> c;
    while (c--) {
        string members, fans;
        cin >> members >> fans;
        cout << hugCnt(members, fans) << endl;
    }

    return 0;
}