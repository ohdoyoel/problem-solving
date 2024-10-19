#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[50001];

int sqr(int n) {
    int& ret = cache[n];
    if (ret!=-1) return ret;

    ret = n;
    for (int i=1; i<=pow(n, 0.5); i++) ret = min(ret, 1+sqr(n-pow(i, 2)));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(cache, -1, sizeof(cache));
    int n; cin >> n;
    cout << sqr(n) << endl;
}