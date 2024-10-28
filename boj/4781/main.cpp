#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[5001][10001];
int n, m;
vector<int> C, P;

int calorie(int i, int price) {
    if (price<0) return -987654321;
    if (i==n) return 0;

    int& ret = cache[i][price];
    if (ret!=-1) return ret;

    ret = 0;
    for (int j=0; j<=price/P[i]+1; ++j) ret = max(ret, j*C[i]+calorie(i+1, price-j*P[i]));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(1){
        memset(cache, -1, sizeof(cache));
        double _m; cin >> n >> _m; m = 100 * _m;
        if (n==0 && m==0) break;
        C.resize(n); P.resize(n);
        for (int i=0; i<n; ++i) {
            cin >> C[i] >> _m;
            P[i] = 100 * _m;
        }
        cout << calorie(0, m) << endl;
    }
}