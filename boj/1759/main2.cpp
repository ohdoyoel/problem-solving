#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int l, c;
vector<char> C;
vector<string> A;
string cand;
int vowels;

void solve(int i) {
    if (cand.size()==l && vowels>=1 && cand.size()-vowels>=2) {
        A.push_back(cand);
        return;
    }
    if (i==C.size()) return;

    cand.push_back(C[i]);
    if (string("aeiou").find(C[i])!=string::npos) vowels++;
    solve(i+1);
    cand.pop_back();
    if (string("aeiou").find(C[i])!=string::npos) vowels--;
    
    solve(i+1);

    return;
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    cin >> l >> c; C.resize(c);
    for (int i=0; i<c; ++i) cin >> C[i];
    sort(C.begin(), C.end());

    cand = "";
    vowels = 0;
    solve(0);

    for (string a : A) cout << a << endl;
}