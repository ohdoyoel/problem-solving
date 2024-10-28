#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[1001][10001];
int n, k;
vector<int> I, T;

int importance(int i, int _time) {
    if (_time<0) return -987654321;
    if (i==k) return 0;

    ret = cache[i][_time];
    if (ret!=-1) return ret;

    ret = 0;
    ret = max(ret, importance(i+1, _time));
    ret = max(ret, I[i] + importance(i+1, _time-T[i]));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    memset(cache, -1, sizeof(cache));
    int n, k; cin >> n >> k; I.resize(k); T.resize(k);
    for (int i=0; i<k; ++i) cin >> I[i] >> T[i];
    cout << importance(0, n) << endl;
}