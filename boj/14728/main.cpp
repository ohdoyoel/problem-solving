#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[101][10001];
int n;
vector<int> T, S;

int score(int i, int tme) {
    if (tme < 0) return -987654321;
    if (i==n) return 0;

    int& ret = cache[i][tme];
    if (ret!=-1) return ret;

    ret = 0;
    ret = max(ret, score(i+1, tme));
    ret = max(ret, S[i]+score(i+1, tme-T[i]));

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(cache, -1, sizeof(cache));
    int t; cin >> n >> t; T.resize(n); S.resize(n);
    for (int i=0; i<n; ++i) cin >> T[i] >> S[i];
    cout << score(0, t) << endl;
}