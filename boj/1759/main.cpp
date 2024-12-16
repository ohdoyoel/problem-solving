#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int l, c;
vector<char> A;
vector<char> B;
vector<string> R;

bool possible() {
    int p = 0;
    for (char b : B) if (string("aeiou").find(b)!=string::npos) p++;
    return p>=1 && (B.size()-p)>=2;
}

// i번째를 뽑을지 말지
void solve(int i) {
    if (B.size()==l && possible()) {
        string r = "";
        for (char b : B) r += b;
        R.push_back(r);
        return;
    }
    if (i==c) return;

    B.push_back(A[i]);
    solve(i+1);
    B.pop_back();
    solve(i+1);

    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> l >> c; A.resize(c);
    for (int i=0; i<c; ++i) cin >> A[i];
    sort(A.begin(), A.end());
    solve(0);

    for (string r : R) cout << r << endl;
}