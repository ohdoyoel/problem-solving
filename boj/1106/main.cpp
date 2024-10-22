#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[21][1001];
int n;
vector<int> P, C;

int price(int i, int customer) {
    if (customer<=0) return 0;
    if (i==n) return 0;

    int& ret = cache[i][customer];
    if (ret!=-1) return ret;

    ret = 987654321;
    for (int j=0; j<=customer/C[i]; ++j) ret = min(ret, j*P[i] + price(i+1, customer-j*C[i]));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(cache, -1, sizeof(cache));
    int c; cin >> c >> n; P.resize(n); C.resize(n);
    for (int i=0; i<n; i++) cin >> P[i] >> C[i];
    cout << price(0, c) << endl;
}