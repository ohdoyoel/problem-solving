#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[100001];

int coin(int n) {
    if (n==2 || n==5) return 1;

    int& ret = cache[n];
    if (ret!=-1) return ret;

    ret = 987654321;
    ret = min(ret, 1+coin(n-2));
    ret = min(ret, 1+coin(n-5));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(cache, -1, sizeof(cache));
    int n; cin >> n;
    int res = coin(n);
    if (res = 987654321) res = -1;
    cout << res << endl;
}