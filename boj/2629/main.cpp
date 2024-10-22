#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
int cache[31][15001];
int sumW;
vector<int> W;

bool add(int i, int weight) {
    if (weight==0) return true;
    if (weight<0||15000<weight) return false;
    if (i==n) return false;

    int& ret = cache[i][weight];
    if (ret!=-1) return ret;

    return ret = add(i+1, weight) || add(i+1, weight-W[i]);
}

bool check(int x) {
    if (add(0, x)) return true;
    for (int i=0; i<=sumW-x; i++) if (add(0, i) && add(0, i+x)) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n; W.resize(n); sumW = 0;
    for (int i=0; i<n; ++i) {
        cin >> W[i];
        sumW += W[i];
    }
    int c; cin >> c;
    while (c--) {
        int x; cin >> x;
        if (check(x)) cout << 'Y' << ' ';
        else cout << 'N' << ' ';
    }
}